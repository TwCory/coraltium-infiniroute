// SPDX-License-Identifier: GPL-2.0+

/*
 *  Coraltium InfiniRoute NOS - Standard:
 *
 *  Linux Netlink Routing Functions (include/netlink-routing.h):
 *  
 *  
 *  Version:    1.0.3      2024-11-07
 *
 *  Author(s):
 *  -> Cory Voltz, voltzc@twchl.net
 *
 *  Disclaimer:
 *      Coraltium InfiniRoute is a free and open source project, and can thus be redistributed and/or modified
 *      under the terms of the GPL.
 */

#ifndef _CT_NETLINK_ROUTING_H_
#define _CT_NETLINK_ROUTING_H_

#include <netlink/netlink.h>
#include <netlink/msg.h>
#include <netlink/attr.h>
#include <netlink/route/route.h>
#include <netlink/route/addr.h>
#include <netlink/route/link.h>
#include <netlink/route/rule.h>
#include <netlink/route/neighbour.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Netlink Routing: Create, Read, Update, and Delete (CRUD) Operations */
typedef enum {

    NL_ROUTE_CREATE,                                // Netlink Route: CREATE Operation
    NL_ROUTE_READ,                                  // Netlink Route: READ Operation
    NL_ROUTE_UPDATE,                                // Netlink Route: UPDATE Operation
    NL_ROUTE_DELETE,                                // Netlink Route: DELETE Operation

} nl_route_action_t;

/* Netlink Routing: Kernel Protocol IDs */
typedef enum {

    RTPROT_UNSPEC = 0,                              // Route Source: NULL
    RTPROT_REDIRECT = 1,                            // Route Source: ICMP Redirect
    RTPROT_KERNEL = 2,                              // Route Source: Linux Kernel
    RTPROT_BOOT = 3,                                // Route Source: Startup
    RTPROT_STATIC = 4,                              // Route Source: Administrator
    RTPROT_GATED = 8,                               // Route Source: Gateway Daemon (GateD)
    RTPROT_RA = 9,                                  // Route Source: Neighbor Discovery Protocol (NDP) Router Advertisement (RA)
    RTPROT_MRT = 10,                                // Route Source: Multi-Threaded Routing Toolkit (MRT)
    RTPROT_ZEBRA = 11,                              // Route Source: GNU Zebra Daemon
    RTPROT_BIRD = 12,                               // Route Source: BIRD Internet Routing Daemon (BIRD)
    RTPROT_DNROUTED = 13,                           // Route Source: DECnet Routing Daemon
    RTPROT_XORP = 14,                               // Route Source: eXtensible Open Router Platform (XORP) Daemon
    RTPROT_NTK = 15,                                // Route Source: Netsukuku Peer-to-Peer Routing
    RTPROT_DHCP = 16,                               // Route Source: Dynamic Host Configuration Protocol (DHCP) Client
    RTPROT_MROUTED = 17,                            // Route Source: Multicast Routing Daemon
    RTPROT_KEEPALIVED = 18,                         // Route Source: Keepalive Daemon
    RTPROT_BABEL = 42,                              // Route Source: Babel
    RTPROT_BGP = 186,                               // Route Source: Border Gateway Protocol (BGP)
    RTPROT_OSPF = 188,                              // Route Source: Open Shortest Path First (OSPF)
    RTPROT_RIP = 189,                               // Route Source: Routing Information Protocol (RIP)
    RTPROT_ISIS = 187,                              // Route Source: ISO Intermediate System to Intermediate System (IS-IS)
    RTPROT_EIGRP = 192                              // Route Source: Enhanced Interior Gateway Routing Protocol (EIGRP)

} nl_route_proto_t;

/* Netlink Routing: Address Family Identifiers */
typedef enum {

    NL_ROUTE_IPV4 = AF_INET,                        // Address Family: Internet Protocol Version 4 (TCP/IPv4)
    NL_ROUTE_IPV6 = AF_INET6                        // Address Family: Internet Protocol Version 6 (TCP/IPv6)

} nl_route_afi_t;

/* Netlink Routing: Route Entry Structure */
typedef struct {

    nl_route_afi_t afi;

    union {

        struct in_addr ipv4_dst;
        struct in6_addr ipv6_dst;

    };

    uint8_t dst_prefix_length;

    union {

        struct in_addr ipv4_next_hop;
        struct in6_addr ipv6_next_hop;

    };

    char exit_iface[IFNAMSIZ];
    uint32_t metric_value;
    uint32_t priority_value;
    nl_route_proto_t proto_value;
    uint32_t table_id;

} nl_route_entry_t;



/* Netlink Routing: Netlink Routing Socket Initialization Operation */
struct nl_sock* nl_route_socket_init(void);

/* Netlink Routing: Netlink Routing Socket Close Operation */
void nl_route_socket_close(struct nl_sock* sock);

/* Netlink Routing: Create Route Operation */
int nl_route_create(struct nl_sock* sock, const nl_route_entry_t* route_entry);

/* Netlink Routing: Read Route Operation */
int nl_route_read(struct nl_sock* sock, const nl_route_entry_t* route_entry);

/* Netlink Routing: Update Route Operation */
int nl_route_update(struct nl_sock* sock, const nl_route_entry_t* route_entry);

/* Netlink Routing: Delete Route Operation */
int nl_route_delete(struct nl_sock* sock, const nl_route_entry_t* route_entry);

/* Netlink Routing: Initialize Route Entry Structure from Strings */
int nl_route_entry_init(nl_route_entry_t* route_entry,
                        nl_route_aft_t afi,
                        const char* dst_prefix_length,
                        const char* next_hop,
                        const char* exit_iface,
                        uint32_t metric_value,
                        uint32_t priority_value,
                        nl_route_proto_t proto_value,
                        uint32_t table_id);

/* Netlink Routing: Error Output */
void nl_route_error_print(int error_code);


#endif /* _CT_NETLINK_COMMON_H_ */
