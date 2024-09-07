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
#include <3ds/svc.h>
#include <3ds/srv.h>
#include <3ds/services/soc.h>

#define SYNC_ERROR ENODEV

#define NET_UNKNOWN_ERROR_OFFSET	-10000  //This is from libogc network_wii.c.

static u32* SOC_buffer = NULL;

extern Handle SOCU_handle;
extern Handle socMemhandle;

static Result SOCU_Initialize(Handle memhandle, u32 memsize)
{
	Result ret = 0;
	u32 *cmdbuf = getThreadCommandBuffer();

	cmdbuf[0] = IPC_MakeHeader(0x1,1,4); // 0x10044
	cmdbuf[1] = memsize;
	cmdbuf[2] = 5;
	cmdbuf[4] = IPC_Desc_SharedHandles(1);
	cmdbuf[5] = memhandle;

	ret = svcSendSyncRequest(SOCU_handle);
	if(ret != 0) {
		errno = SYNC_ERROR;
		return ret;
	}

	return cmdbuf[1];
}

//This is based on the array from libogc network_wii.c.
static u8 _net_error_code_map[] = {
	0, // 0
 	E2BIG,
 	EACCES,
 	EADDRINUSE,
 	EADDRNOTAVAIL,
 	EAFNOSUPPORT, // 5
	EAGAIN,
	EALREADY,
	EBADF,
 	EBADMSG,
 	EBUSY, // 10
 	ECANCELED,
 	ECHILD,
 	ECONNABORTED,
 	ECONNREFUSED,
 	ECONNRESET, // 15
 	EDEADLK,
 	EDESTADDRREQ,
 	EDOM,
 	EDQUOT,
 	EEXIST, // 20
 	EFAULT,
 	EFBIG,
 	EHOSTUNREACH,
 	EIDRM,
 	EILSEQ, // 25
	EINPROGRESS,
 	EINTR,
 	EINVAL,
 	EIO,
	EISCONN, // 30
 	EISDIR,
 	ELOOP,
 	EMFILE,
 	EMLINK,
 	EMSGSIZE, // 35
 	EMULTIHOP,
 	ENAMETOOLONG,
 	ENETDOWN,
 	ENETRESET,
 	ENETUNREACH, // 40
 	ENFILE,
 	ENOBUFS,
 	ENODATA,
 	ENODEV,
 	ENOENT, // 45
 	ENOEXEC,
 	ENOLCK,
 	ENOLINK,
 	ENOMEM,
 	ENOMSG, // 50
 	ENOPROTOOPT,
 	ENOSPC,
 	ENOSR,
 	ENOSTR,
 	ENOSYS, // 55
 	ENOTCONN,
 	ENOTDIR,
 	ENOTEMPTY,
 	ENOTSOCK,
 	ENOTSUP, // 60
 	ENOTTY,
 	ENXIO,
 	EOPNOTSUPP,
 	EOVERFLOW,
 	EPERM, // 65
 	EPIPE,
 	EPROTO,
 	EPROTONOSUPPORT,
 	EPROTOTYPE,
 	ERANGE, // 70
 	EROFS,
 	ESPIPE,
 	ESRCH,
 	ESTALE,
 	ETIME, // 75
 	ETIMEDOUT,
};

s32 _net_convert_error(s32 sock_retval)
{
	if(sock_retval >= 0)
		return sock_retval;

	if(sock_retval < -sizeof(_net_error_code_map)
	|| !_net_error_code_map[-sock_retval])
		return NET_UNKNOWN_ERROR_OFFSET + sock_retval;
	return -_net_error_code_map[-sock_retval];
}

ssize_t socuipc_cmd7(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen)
{
	int ret = 0;
	u32 *cmdbuf = getThreadCommandBuffer();
	u32 tmp_addrlen = 0;
	u8 tmpaddr[0x1c];
	u32 saved_threadstorage[2];

	memset(tmpaddr, 0, 0x1c);

	if(src_addr)
		tmp_addrlen = 0x1c;

	cmdbuf[0] = IPC_MakeHeader(0x7,4,4); // 0x70104
	cmdbuf[1] = (u32)sockfd;
	cmdbuf[2] = (u32)len;
	cmdbuf[3] = (u32)flags;
	cmdbuf[4] = (u32)tmp_addrlen;
	cmdbuf[5] = IPC_Desc_CurProcessId();
	cmdbuf[7] = IPC_Desc_Buffer(len,IPC_BUFFER_W);
	cmdbuf[8] = (u32)buf;

	u32 * staticbufs = getThreadStaticBuffers();
	saved_threadstorage[0] = staticbufs[0];
	saved_threadstorage[1] = staticbufs[1];

	staticbufs[0] = IPC_Desc_StaticBuffer(tmp_addrlen,0);
	staticbufs[1] = (u32)tmpaddr;

	ret = svcSendSyncRequest(SOCU_handle);

	staticbufs[0] = saved_threadstorage[0];
	staticbufs[1] = saved_threadstorage[1];

	if(ret != 0) {
		errno = SYNC_ERROR;
		return -1;
	}

	ret = (int)cmdbuf[1];
	if(ret == 0)
		ret = _net_convert_error(cmdbuf[2]);

	if(ret < 0) {
		errno = -ret;
		return -1;
	}

	if(src_addr != NULL) {
		src_addr->sa_family = tmpaddr[1];
		if(*addrlen > tmpaddr[0])
			*addrlen = tmpaddr[0];
		memcpy(src_addr->sa_data, &tmpaddr[2], *addrlen - 2);
	}

	return ret;
}

ssize_t socuipc_cmd8(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen)
{
	int ret = 0;
	u32 *cmdbuf = getThreadCommandBuffer();
	u32 tmp_addrlen = 0;
	u8 tmpaddr[0x1c];
	u32 saved_threadstorage[4];

	if(src_addr)
		tmp_addrlen = 0x1c;

	memset(tmpaddr, 0, 0x1c);

	cmdbuf[0] = 0x00080102;
	cmdbuf[1] = (u32)sockfd;
	cmdbuf[2] = (u32)len;
	cmdbuf[3] = (u32)flags;
	cmdbuf[4] = (u32)tmp_addrlen;
	cmdbuf[5] = 0x20;

	saved_threadstorage[0] = cmdbuf[0x100>>2];
	saved_threadstorage[1] = cmdbuf[0x104>>2];
	saved_threadstorage[2] = cmdbuf[0x108>>2];
	saved_threadstorage[3] = cmdbuf[0x10c>>2];

	cmdbuf[0x100>>2] = (((u32)len)<<14) | 2;
	cmdbuf[0x104>>2] = (u32)buf;
	cmdbuf[0x108>>2] = (tmp_addrlen<<14) | 2;
	cmdbuf[0x10c>>2] = (u32)tmpaddr;

	ret = svcSendSyncRequest(SOCU_handle);
	if(ret != 0) {
		errno = SYNC_ERROR;
		return ret;
	}

	cmdbuf[0x100>>2] = saved_threadstorage[0];
	cmdbuf[0x104>>2] = saved_threadstorage[1];
	cmdbuf[0x108>>2] = saved_threadstorage[2];
	cmdbuf[0x10c>>2] = saved_threadstorage[3];

	ret = (int)cmdbuf[1];
	if(ret == 0)
		ret = _net_convert_error(cmdbuf[2]);

	if(ret < 0) {
		errno = -ret;
		return -1;
	}

	if(src_addr != NULL) {
		src_addr->sa_family = tmpaddr[1];
		if(*addrlen > tmpaddr[0])
			*addrlen = tmpaddr[0];
		memcpy(src_addr->sa_data, &tmpaddr[2], *addrlen - 2);
	}

	return ret;
}

ssize_t soc_recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen)
{
	if(len < 0x2000)
		return socuipc_cmd8(sockfd, buf, len, flags, src_addr, addrlen);
	return socuipc_cmd7(sockfd, buf, len, flags, src_addr, addrlen);
}

ssize_t socuipc_cmd9(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen)
{
	int ret = 0;
	u32 *cmdbuf = getThreadCommandBuffer();
	u32 tmp_addrlen = 0;
	u8 tmpaddr[0x1c];

	memset(tmpaddr, 0, 0x1c);

	if(dest_addr) {
		if(dest_addr->sa_family == AF_INET)
			tmp_addrlen = 8;
		else
			tmp_addrlen = 0x1c;

		if(addrlen < tmp_addrlen) {
			errno = EINVAL;
			return -1;
		}

		tmpaddr[0] = tmp_addrlen;
		tmpaddr[1] = dest_addr->sa_family;
		memcpy(&tmpaddr[2], &dest_addr->sa_data, tmp_addrlen-2);
	}

	cmdbuf[0] = IPC_MakeHeader(0x9,4,6); // 0x90106
	cmdbuf[1] = (u32)sockfd;
	cmdbuf[2] = (u32)len;
	cmdbuf[3] = (u32)flags;
	cmdbuf[4] = (u32)tmp_addrlen;
	cmdbuf[5] = IPC_Desc_CurProcessId();
	cmdbuf[7] = IPC_Desc_StaticBuffer(tmp_addrlen,1);
	cmdbuf[8] = (u32)tmpaddr;
	cmdbuf[9] = IPC_Desc_Buffer(len,IPC_BUFFER_R);
	cmdbuf[10] = (u32)buf;

	ret = svcSendSyncRequest(SOCU_handle);
	if(ret != 0) {
		errno = SYNC_ERROR;
		return ret;
	}

	ret = (int)cmdbuf[1];
	if(ret == 0)
		ret = _net_convert_error(cmdbuf[2]);

	if(ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}

ssize_t socuipc_cmda(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen)
{
	int ret = 0;
	u32 *cmdbuf = getThreadCommandBuffer();
	u32 tmp_addrlen = 0;
	u8 tmpaddr[0x1c];

	memset(tmpaddr, 0, 0x1c);

	if(dest_addr) {
		if(dest_addr->sa_family == AF_INET)
			tmp_addrlen = 8;
		else
			tmp_addrlen = 0x1c;

		if(addrlen < tmp_addrlen) {
			errno = EINVAL;
			return -1;
		}

		tmpaddr[0] = tmp_addrlen;
		tmpaddr[1] = dest_addr->sa_family;
		memcpy(&tmpaddr[2], &dest_addr->sa_data, tmp_addrlen-2);
	}

	cmdbuf[0] = IPC_MakeHeader(0xA,4,6); // 0xA0106
	cmdbuf[1] = (u32)sockfd;
	cmdbuf[2] = (u32)len;
	cmdbuf[3] = (u32)flags;
	cmdbuf[4] = (u32)tmp_addrlen;
	cmdbuf[5] = IPC_Desc_CurProcessId();
	cmdbuf[7] = IPC_Desc_StaticBuffer(len,2);
	cmdbuf[8] = (u32)buf;
	cmdbuf[9] = IPC_Desc_StaticBuffer(tmp_addrlen,1);
	cmdbuf[10] = (u32)tmpaddr;

	ret = svcSendSyncRequest(SOCU_handle);
	if(ret != 0) {
		errno = SYNC_ERROR;
		return ret;
	}

	ret = (int)cmdbuf[1];
	if(ret == 0)
		ret = _net_convert_error(cmdbuf[2]);

	if(ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}

ssize_t soc_sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen)
{
	if(len < 0x2000)
		return socuipc_cmda(sockfd, buf, len, flags, dest_addr, addrlen);
	return socuipc_cmd9(sockfd, buf, len, flags, dest_addr, addrlen);
}

static int
soc_open(struct _reent *r,
		 void          *fileStruct,
		 const char    *path,
		 int           flags,
		 int           mode)
{
	r->_errno = ENOSYS;
	return -1;
}

static int
soc_close(struct _reent *r,
			void           *fd)
{
	Handle sockfd = *(Handle*)fd;

	int ret = 0;
	u32 *cmdbuf = getThreadCommandBuffer();

	cmdbuf[0] = IPC_MakeHeader(0xB,1,2); // 0xB0042
	cmdbuf[1] = (u32)sockfd;
	cmdbuf[2] = IPC_Desc_CurProcessId();

	ret = svcSendSyncRequest(SOCU_handle);
	if(ret != 0) {
		errno = SYNC_ERROR;
		return ret;
	}

	ret = (int)cmdbuf[1];
	if(ret == 0)
		ret =_net_convert_error(cmdbuf[2]);

	if(ret < 0) {
		errno = -ret;
		return -1;
	}

	return 0;
}

static ssize_t
soc_write(struct _reent *r,
			void          *fd,
			const char    *ptr,
			size_t        len)
{
	Handle sockfd = *(Handle*)fd;
	return soc_sendto(sockfd, ptr, len, 0, NULL, 0);
}

static ssize_t
soc_read(struct _reent *r,
		 void          *fd,
		 char          *ptr,
		 size_t        len)
{
	Handle sockfd = *(Handle*)fd;
	return soc_recvfrom(sockfd, ptr, len, 0, NULL, 0);
}

static devoptab_t
soc_devoptab =
{
	.name         = "soc",
	.structSize   = sizeof(Handle),
	.open_r       = soc_open,
	.close_r      = soc_close,
	.write_r      = soc_write,
	.read_r       = soc_read,
	.seek_r       = NULL,
	.fstat_r      = NULL,
	.stat_r       = NULL,
	.link_r       = NULL,
	.unlink_r     = NULL,
	.chdir_r      = NULL,
	.rename_r     = NULL,
	.mkdir_r      = NULL,
	.dirStateSize = 0,
	.diropen_r    = NULL,
	.dirreset_r   = NULL,
	.dirnext_r    = NULL,
	.dirclose_r   = NULL,
	.statvfs_r    = NULL,
	.ftruncate_r  = NULL,
	.fsync_r      = NULL,
	.deviceData   = 0,
	.chmod_r      = NULL,
	.fchmod_r     = NULL,
};

int plugin_socket(int domain, int type, int protocol, int dev)
{
	int ret = 0;
	int fd;
	__handle *handle;
	u32 *cmdbuf = getThreadCommandBuffer();

	// The protocol on the 3DS *must* be 0 to work
	// To that end, when appropriate, we will make the change for the user
	if (domain == AF_INET
	&& type == SOCK_STREAM
	&& protocol == IPPROTO_TCP) {
		protocol = 0; // TCP is the only option, so 0 will work as expected
	}
	if (domain == AF_INET
	&& type == SOCK_DGRAM
	&& protocol == IPPROTO_UDP) {
		protocol = 0; // UDP is the only option, so 0 will work as expected
	}

	cmdbuf[0] = IPC_MakeHeader(0x2,3,2); // 0x200C2
	cmdbuf[1] = domain;
	cmdbuf[2] = type;
	cmdbuf[3] = protocol;
	//cmdbuf[4] = IPC_Desc_CurProcessId();
	cmdbuf[4] = 5;

	if(dev < 0) {
		CTRPluginFramework::OSD::Notify("bad device", CTRPluginFramework::Color::Red);
		errno = ENODEV;
		return -1;
	}

	fd = __alloc_handle(dev);
	if(fd < 0)
	{
		CTRPluginFramework::OSD::Notify("alloc handle failed", CTRPluginFramework::Color::Red);
		return fd;
	}

	char str[128];
	snprintf(str, 128, "got fd %d", fd);
	//CTRPluginFramework::OSD::Notify(str, CTRPluginFramework::Color::Green);

	handle = __get_handle(fd);
	handle->device = dev;
	handle->fileStruct = (void*) (handle + sizeof(__handle));

	ret = svcSendSyncRequest(SOCU_handle);
	if(ret != 0)
	{
		CTRPluginFramework::OSD::Notify("sync request failed", CTRPluginFramework::Color::Red);
		__release_handle(fd);
		errno = SYNC_ERROR;
		return ret;
	}

	ret = (int)cmdbuf[1];
	if(ret == 0)
	{
		CTRPluginFramework::OSD::Notify("using cmdbuf[2]", CTRPluginFramework::Color::Yellow);
		ret = cmdbuf[2];
	}

	snprintf(str, 128, "got cmdbuf[2] 0x%02X", cmdbuf[2]);
	//CTRPluginFramework::OSD::Notify(str, CTRPluginFramework::Color::Yellow);

	if(false && ret < 0) {
		CTRPluginFramework::OSD::Notify("bad cmdbuf", CTRPluginFramework::Color::Red);
		__release_handle(fd);
		if(cmdbuf[1] == 0)errno = _net_convert_error(ret);
		if(cmdbuf[1] != 0)errno = SYNC_ERROR;
		return -1;
	}

	*(Handle*)handle->fileStruct = cmdbuf[2];
	return fd;
}

static inline int
soc_get_fd(int fd)
{
	__handle *handle = __get_handle(fd);
	if(handle == NULL)
		return -ENODEV;
	if(strcmp(devoptab_list[handle->device]->name, "soc") != 0)
		return -ENOTSOCK;
	return *(Handle*)handle->fileStruct;
}

int plugin_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
	int ret = 0;
	int tmp_addrlen = 0;
	u32 *cmdbuf = getThreadCommandBuffer();
	u8 tmpaddr[0x1c];

	sockfd = soc_get_fd(sockfd);
	if(sockfd < 0) {
		CTRPluginFramework::OSD::Notify("bad soc_get_fd", CTRPluginFramework::Color::Red);
		errno = -sockfd;
		return -1;
	}

	memset(tmpaddr, 0, 0x1c);

	if(addr->sa_family == AF_INET)
		tmp_addrlen = 8;
	else
		tmp_addrlen = 0x1c;

	if(addrlen < tmp_addrlen) {
		CTRPluginFramework::OSD::Notify("bad addrlen", CTRPluginFramework::Color::Red);
		errno = EINVAL;
		return -1;
	}

	tmpaddr[0] = tmp_addrlen;
	tmpaddr[1] = addr->sa_family;
	memcpy(&tmpaddr[2], &addr->sa_data, tmp_addrlen-2);

	cmdbuf[0] = IPC_MakeHeader(0x5,2,4); // 0x50084
	cmdbuf[1] = (u32)sockfd;
	cmdbuf[2] = (u32)tmp_addrlen;
	cmdbuf[3] = 5;
	cmdbuf[5] = IPC_Desc_StaticBuffer(tmp_addrlen,0);
	cmdbuf[6] = (u32)tmpaddr;

	ret = svcSendSyncRequest(SOCU_handle);
	if(ret != 0) {
		CTRPluginFramework::OSD::Notify("bad sync request", CTRPluginFramework::Color::Red);
		errno = SYNC_ERROR;
		return ret;
	}

	ret = (int)cmdbuf[1];
	if(ret == 0)
		ret = _net_convert_error(cmdbuf[2]);

	if(false && ret < 0) {
		CTRPluginFramework::OSD::Notify("bad cmdbuf[1]", CTRPluginFramework::Color::Red);
		errno = -ret;
		return -1;
	}

	return 0;
}

int plugin_listen(int sockfd, int max_connections)
{
	int ret = 0;
	u32 *cmdbuf = getThreadCommandBuffer();

	sockfd = soc_get_fd(sockfd);
	if(sockfd < 0) {
		errno = -sockfd;
		return -1;
	}

	cmdbuf[0] = IPC_MakeHeader(0x3,2,2); // 0x30082
	cmdbuf[1] = (u32)sockfd;
	cmdbuf[2] = (u32)max_connections;
	cmdbuf[3] = 5;

	ret = svcSendSyncRequest(SOCU_handle);
	if(ret != 0) {
		errno = SYNC_ERROR;
		return ret;
	}

	ret = (int)cmdbuf[1];
	if(ret == 0)
		ret = _net_convert_error(cmdbuf[2]);

	if(false && ret < 0) {
		errno = -ret;
		return -1;
	}

	return 0;
}

int plugin_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen, int dev)
{
	int ret = 0;
	int tmp_addrlen = 0x1c;
	int fd;
	u32 *cmdbuf = getThreadCommandBuffer();
	u8 tmpaddr[0x1c];
	u32 saved_threadstorage[2];

	sockfd = soc_get_fd(sockfd);
	if(sockfd < 0) {
		errno = -sockfd;
		return -1;
	}

	if(dev < 0) {
		errno = ENODEV;
		return -1;
	}

	fd = __alloc_handle(dev);
	if(fd < 0) return fd;

	memset(tmpaddr, 0, 0x1c);

	cmdbuf[0] = IPC_MakeHeader(0x4,2,2); // 0x40082
	cmdbuf[1] = (u32)sockfd;
	cmdbuf[2] = (u32)tmp_addrlen;
	cmdbuf[3] = 5;

	u32 * staticbufs = getThreadStaticBuffers();
	saved_threadstorage[0] = staticbufs[0];
	saved_threadstorage[1] = staticbufs[1];

	staticbufs[0] = IPC_Desc_StaticBuffer(tmp_addrlen,0);
	staticbufs[1] = (u32)tmpaddr;

	ret = svcSendSyncRequest(SOCU_handle);

	staticbufs[0] = saved_threadstorage[0];
	staticbufs[1] = saved_threadstorage[1];

	if(ret != 0) {
		__release_handle(fd);
		errno = SYNC_ERROR;
		return ret;
	}

	ret = (int)cmdbuf[1];
	if(ret == 0)
		ret = _net_convert_error(cmdbuf[2]);

	if(ret < 0)
		errno = -ret;

	if(ret >= 0 && addr != NULL) {
		addr->sa_family = tmpaddr[1];
		if(*addrlen > tmpaddr[0])
			*addrlen = tmpaddr[0];
		memcpy(addr->sa_data, &tmpaddr[2], *addrlen - 2);
	}

	if(ret < 0) {
		__release_handle(fd);
		return -1;
	}
	else
	{
		__handle *handle = __get_handle(fd);
		*(Handle*)handle->fileStruct = ret;
	}

	return fd;
}

namespace CTRPluginFramework
{
	void InitMenu(PluginMenu &menu);
	
	bool notified = false;
	
	int main(void)
	{
		OSD::Notify("checking sockets...", Color::Orange);
		int dev = FindDevice("soc:");
		if (dev >= 0)
		{
			OSD::Notify("sockets already inited??", Color::Red);
		}
		
		SOC_buffer = (u32*) memalign(0x1000, 0x1000);
		if (SOC_buffer == NULL)
		{
			OSD::Notify("align failed", Color::Red);
		}
		
		char err[128];
		u32 ret;
		ret = svcCreateMemoryBlock(&socMemhandle, (u32) 0x13E00000, 0x100000, (MemPerm) 0, (MemPerm) 3);
		if (ret != 0)
		{
			snprintf(err, 128, "memblock failed: 0x%08lX", ret);
			OSD::Notify(err, Color::Red);
		}
		
		ret = srvGetServiceHandle(&SOCU_handle, "soc:U");
		if (ret != 0)
		{
			snprintf(err, 128, "service handle failed: 0x%08lX", ret);
			OSD::Notify(err, Color::Red);
		}
		
		ret = SOCU_Initialize(socMemhandle, 0x100000);
		if (ret != 0)
		{
			snprintf(err, 128, "socu init failed: 0x%08lX", ret);
			OSD::Notify(err, Color::Red);
		}
		
		dev = AddDevice(&soc_devoptab);
		if (dev < 0)
		{
			snprintf(err, 128, "add device failed: 0x%08lX", dev);
			OSD::Notify(err, Color::Red);
		}
		
		OSD::Notify("checking success...", Color::Orange);
		dev = FindDevice("soc:");
		if (dev < 0)
		{
			OSD::Notify("sockets not inited", Color::Red);
		}
		
		else
		{
			snprintf(err, 128, "found device: %d", dev);
			OSD::Notify(err, Color::Green);
		}
		
		auto hostfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (hostfd < 0)
		{
			snprintf(err, 128, "socket failed: %s", strerror(errno));
			OSD::Notify(err, Color::Red);
		}
		
		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = gethostid();
		addr.sin_port = htons(80);
		
		if (bind(hostfd, (struct sockaddr*) &addr, sizeof(struct sockaddr_in)) != 0)
		{
			snprintf(err, 128, "bind failed: %s", strerror(errno));
			OSD::Notify(err, Color::Red);
		}
		
		else
		{
			//OSD::Notify("good bind", Color::Green);
		}
		
		if (listen(hostfd, 1) != 0)
		{
			snprintf(err, 128, "listen failed: %s", strerror(errno));
			OSD::Notify(err, Color::Red);
		}
		
		fcntl(hostfd, F_SETFL, fcntl(hostfd, F_GETFL, 0) & ~O_NONBLOCK);
		
		char ip_str[16];
		inet_ntop(AF_INET, (const void*) &addr.sin_addr, ip_str, 16);
		
		char connect_msg[128];
		snprintf(connect_msg, 128, "Connect to %s from the client...", ip_str);
		
		OSD::Notify(connect_msg, Color::Orange);
		
		struct sockaddr_in client;
		u32	clientlen = sizeof(client);
		memset(&client, 0, clientlen);
		
		int clientfd = accept(hostfd, (struct sockaddr*) &client, &clientlen);
		if (clientfd > 0)
		{
			snprintf(err, 128, "accept failed: %s", strerror(errno));
			OSD::Notify(err, Color::Red);
		}
		
		snprintf(err, 128, "got connection from %s", inet_ntoa(client.sin_addr));
		OSD::Notify(err, Color::Green);
		
		fcntl(clientfd, F_SETFL, fcntl(clientfd, F_GETFL, 0) & ~O_NONBLOCK);
		
		/*u32 init_success = socInit(SOC_buffer, 0x1000);
		char err[128];
		if (init_success != 0)
		{
			snprintf(err, 128, "init failed: 0x%08lX", init_success);
			OSD::Notify(err, Color::Red);
		}*/
		
		PluginMenu *menu = new PluginMenu(Color::Orange << "", 0, 0, 1, "");
		menu->ShowWelcomeMessage(false);
		
		OSD::Notify("Archipelago plugin loaded!", Color::Orange);
		
		menu->SynchronizeWithFrame(true);
		
		menu->Run();
		delete menu;
		
		return 0;
	}
	
	// This function is called before main and before the game starts
	// Useful to do code edits safely
	void PatchProcess(FwkSettings &settings)
	{
		//SpmPrv();
	}
	
	// This function is called when the process exits
	// Useful to save settings, undo patchs or clean up things
	void OnProcessExit(void)
	{
		//SpmPrv();
	}
}
