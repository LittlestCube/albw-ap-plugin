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
	int hostfd;
	
	struct sockaddr_in client;
	u32 clientlen;
	
	void socket_thread_func(void* arg)
	{
		SOC_buffer = (u32*) aligned_alloc(0x1000, SOC_MEM_SIZE);
		
		socInit((u32*) SOC_buffer, SOC_MEM_SIZE);
		hostfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		
		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = gethostid();
		addr.sin_port = htons(45987);
		
		bind(hostfd, (struct sockaddr*) &addr, sizeof(struct sockaddr_in));
		
		char ip_str[16];
		inet_ntop(AF_INET, (const void*) &addr.sin_addr, ip_str, 16);
		
		char connect_msg[128];
		snprintf(connect_msg, 128, "Run `/3ds %s' from the client...", ip_str);
		
		OSD::Notify(connect_msg, Color::Orange);
		
		clientlen = sizeof(client);
		memset(&client, 0, clientlen);
		
		fcntl(hostfd, F_SETFL, fcntl(hostfd, F_GETFL, 0) | O_NONBLOCK);
		
		u32 recvlen = -1;
		u8 cmd[50];
		Endianness endianness = LITTLE;
		
		while (recvlen == -1)
		{
			recvlen = recvfrom(hostfd, cmd, 50, 0, (struct sockaddr*) &client, &clientlen);
		}
		
		if (cmd[3] != 0)
		{
			// i mean like when would this ever fire
			endianness = BIG;
		}
		
		memset(cmd, 0, 16);
		sendto(hostfd, cmd, 16, 0, (struct sockaddr*) &client, clientlen);
		
		OSD::ClearAllNotifications();
		
		inet_ntop(AF_INET, (const void*) &client.sin_addr, ip_str, 16);
		
		snprintf(connect_msg, 128, "Got connection from %s!", ip_str);
		OSD::Notify(connect_msg, Color::Green);
		
		Clock start;
		bool checkClock = true;
		
		while (true)
		{
			if (checkClock && start.HasTimePassed(Seconds(3.0f)))
			{
				OSD::ClearAllNotifications();
				
				checkClock = false;
			}
			
			recvlen = recvfrom(hostfd, cmd, 50, 0, (struct sockaddr*) &client, &clientlen);
			
			if (recvlen != -1)
			{
				switch ((MemCommand) MEM(u32, &cmd[8]))
				{
					case READ:
					{
						u32 address = MEM(u32, &cmd[16]);
						u32 size = MEM(u32, &cmd[20]);
						
						size_t i;
						for (i = 0; i < size && i < 32; ++i)
						{
							cmd[16 + i] = read8(address + i);
							
							svcSleepThread(200000LL);
						}
						
						sendto(hostfd, cmd, 16 + i, 0, (struct sockaddr*) &client, clientlen);
						
						break;
					}
					
					case WRITE:
					{
						u32 address = MEM(u32, &cmd[16]);
						u32 size = MEM(u32, &cmd[20]);
						
						for (size_t i = 0; i < size && i < 32; ++i)
						{
							write8(address + i, cmd[24 + i]);
							
							svcSleepThread(200000LL);
						}
						
						sendto(hostfd, cmd, 16, 0, (struct sockaddr*) &client, clientlen);
						
						break;
					}
				}
			}
			
			svcSleepThread(250000000LL);
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
			ThreadEx socket_thread = ThreadEx(socket_thread_func, 0x1000, 22, -1);
			socket_thread.Start(nullptr);
			
			socket_thread.Join(true);
		}
		
		return 0;
	}
	
	void PatchProcess(FwkSettings& settings)
	{
		Process::Write32(0x6FE5F8 + 4, 1);
	}
	
	// This function is called when the process exits
	// Useful to save settings, undo patchs or clean up things
	void OnProcessExit(void)
	{
		if (SOC_buffer != NULL)
		{
			free(SOC_buffer);
		}
		
		socExit();
	}
}