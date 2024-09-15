#include "3ds.h"
#include "csvc.h"
#include "CTRPluginFramework.hpp"
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>
#include <stdarg.h>
#include <unistd.h>

#include <string>
#include <vector>
#include <cstdio>

#include <fcntl.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>
#include <string.h>
#include <sys/iosupport.h>
#include <sys/socket.h>
#include <3ds/types.h>

#define MEM(type, addr) (*((type*) addr))

#define SOC_MEM_SIZE 0x15000

typedef enum
{
	NONE = 0,
	READ = 1,
	WRITE = 2
} MemCommand;

typedef enum
{
	LITTLE,
	BIG
} Endianness;

static u32* SOC_buffer = NULL;

u8 read8(u32 addr)
{
	return MEM(u8, addr);
}

void write8(u32 addr, u8 value)
{
	MEM(u8, addr) = value;
}

namespace CTRPluginFramework
{
	int hostfd = 0;
	
	struct sockaddr_in client;
	u32 clientlen;
	
	Endianness endianness;
	
	char ip_str[16];
	
	void init_sockets()
	{
		if (SOC_buffer == NULL)
		{
			SOC_buffer = (u32*) aligned_alloc(0x1000, SOC_MEM_SIZE);
		}
		
		socInit((u32*) SOC_buffer, SOC_MEM_SIZE);
		
		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = gethostid();
		addr.sin_port = htons(45987);
		
		inet_ntop(AF_INET, (const void*) &addr.sin_addr, ip_str, 16);
		
		if (hostfd <= 0 || ip_str[0] == '0')
		{
			if (hostfd > 0)
			{
				close(hostfd);
			}
			
			hostfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		}
		
		clientlen = sizeof(client);
		
		bind(hostfd, (struct sockaddr*) &addr, sizeof(struct sockaddr_in));
		
		fcntl(hostfd, F_SETFL, fcntl(hostfd, F_GETFL, 0) | O_NONBLOCK);
	}
	
	void socket_func()
	{
		u8 cmd[16 + 32 + 2];
		int recvlen;
		
		while (true)
		{
			init_sockets();
			
			recvlen = recvfrom(hostfd, cmd, 50, 0, (struct sockaddr*) &client, &clientlen);
			
			if (recvlen != -1)
			{
				OSD::ClearAllNotifications();
				
				switch ((MemCommand) MEM(u32, &cmd[8]))
				{
					case NONE:
					{
						sendto(hostfd, cmd, 16, 0, (struct sockaddr*) &client, clientlen);
						
						break;
					}
					
					case READ:
					{
						u32 address = MEM(u32, &cmd[16]);
						u32 size = MEM(u32, &cmd[20]);
						
						size_t i;
						for (i = 0; i < size && i < 0x80; ++i)
						{
							cmd[16 + i] = read8(address + i);
						}
						
						sendto(hostfd, cmd, 16 + i, 0, (struct sockaddr*) &client, clientlen);
						
						break;
					}
					
					case WRITE:
					{
						u32 address = MEM(u32, &cmd[16]);
						u32 size = MEM(u32, &cmd[20]);
						
						for (size_t i = 0; i < size && i < 24; ++i)
						{
							write8(address + i, cmd[24 + i]);
						}
						
						sendto(hostfd, cmd, 16, 0, (struct sockaddr*) &client, clientlen);
						
						break;
					}
				}
			}
			
			svcSleepThread(25000LL);
		}
	}
	
	void handle_event(Process::Event event)
	{
		switch (event)
		{
			case Process::Event::EXIT:
			{
				if (hostfd > 0)
				{
					close(hostfd);
					hostfd = 0;
				}
				
				socExit();
				
				break;
			}
		}
	}
	
	int main(void)
	{
		char err[128];
		
		MemInfo meminfo;
		PageInfo pageinfo;
		
		u32 ret = svcQueryMemory(&meminfo, &pageinfo, (u32) 0x06000000);
		if (meminfo.state == 6)
		{
			OSD::Notify("This version of Luma3DS does not work with this plugin.", Color::Red);
			OSD::Notify("Quitting...", Color::Red);
			
			Clock start;
			
			while (!start.HasTimePassed(Seconds(3.0f)))
			{
				svcSleepThread(250000000LL);
			}
			
			OSD::ClearAllNotifications();
		}
		
		else
		{
			Process::SetProcessEventCallback(handle_event);
			
			init_sockets();
			
			char connect_msg[128];
			snprintf(connect_msg, 128, "Run `/3ds %s' from the client...", ip_str);
			OSD::Notify(connect_msg, Color::Orange);
			
			socket_func();
		}
		
		return 0;
	}
}