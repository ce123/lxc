#ifndef _LXC_NETNS_IFADDRS_H
#define _LXC_NETNS_IFADDRS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>
#include <linux/types.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <sys/socket.h>

struct netns_ifaddrs {
	struct netns_ifaddrs *ifa_next;

	/* Can - but shouldn't be - NULL. */
	char *ifa_name;

	/* This field is not present struct ifaddrs. */
	int ifa_ifindex;

	unsigned ifa_flags;

	/* This field is not present struct ifaddrs. */
	int ifa_mtu;

	/* This field is not present struct ifaddrs. */
	int ifa_prefixlen;

	struct sockaddr *ifa_addr;
	struct sockaddr *ifa_netmask;
	union {
		struct sockaddr *ifu_broadaddr;
		struct sockaddr *ifu_dstaddr;
	} ifa_ifu;

	/* If you don't know what this is for don't touch it. */
	void *ifa_data;
};

#define __ifa_broadaddr ifa_ifu.ifu_broadaddr
#define __ifa_dstaddr ifa_ifu.ifu_dstaddr

extern void netns_freeifaddrs(struct netns_ifaddrs *);
extern int netns_getifaddrs(struct netns_ifaddrs **ifap, __s32 netns_id,
			    bool *netnsid_aware);

#ifdef __cplusplus
}
#endif

#endif /* _LXC_NETNS_IFADDRS_H */
