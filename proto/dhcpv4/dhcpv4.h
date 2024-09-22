// Coraltium InfiniRoute - Version 1.0.1 - DHCPv4 Protocol Data Structures

#ifndef _DHCPV4_H_
#define _DHCPV4_H_

/*
 *      DHCPv4 Option Code Definitions
 */

// Vendor Extensions - Per RFC 1497 (BOOTP Vendor Information Extensions)

#define D4OPT_PAD                                       0
#define D4OPT_SUBNET_MASK                               1
#define D4OPT_TIME_OFFSET                               2
#define D4OPT_ROUTER                                    3
#define D4OPT_TIME_SERVER                               4
#define D4OPT_NAME_SERVER                               5
#define D4OPT_DOMAIN_NAME_SERVER                        6
#define D4OPT_LOG_SERVER                                7
#define D4OPT_COOKIE_SERVER                             8
#define D4OPT_LPR_SERVER                                9
#define D4OPT_IMPRESS_SERVER                            10
#define D4OPT_RESOURCE_LOCATION_SERVER                  11
#define D4OPT_HOST_NAME                                 12
#define D4OPT_BOOT_FILE_SIZE                            13
#define D4OPT_MERIT_DUMP_FILE                           14
#define D4OPT_DOMAIN_NAME                               15
#define D4OPT_SWAP_SERVER                               16
#define D4OPT_ROOT_PATH                                 17
#define D4OPT_EXTENSIONS_PATH                           18

// Per-Host IP Layer Parameters

#define D4OPT_IP_FORWARDING                             19
#define D4OPT_NONLOCAL_SOURCE_ROUTING                   20
#define D4OPT_POLICY_FILTER                             21
#define D4OPT_MAX_DGRAM_REASSEMBLY_SIZE                 22
#define D4OPT_DEFAULT_IP_TTL                            23
#define D4OPT_PMTU_AGING_TIMEOUT                        24
#define D4OPT_PMTU_PLATEAU_TABLE                        25

// Per-Interface IP Layer Parameters

#define D4OPT_INTERFACE_MTU                             26
#define D4OPT_ALL_SUBNETS_ARE_LOCAL                     27
#define D4OPT_BROADCAST_ADDRESS                         28
#define D4OPT_PERFORM_MASK_DISCOVERY                    29
#define D4OPT_MASK_SUPPLIER                             30
#define D4OPT_PERFORM_ROUTER_DISCOVERY                  31
#define D4OPT_ROUTER_SOLICITATION_ADDRESS               32
#define D4OPT_STATIC_ROUTE                              33

// Per-Interface Link-Layer Parameters

#define D4OPT_TRAILER_ENCAPSULATION                     34
#define D4OPT_ARP_CACHE_TIMEOUT                         35
#define D4OPT_ETHERNET_ENCAPSULATION                    36

// TCP Protocol Parameters

#define D4OPT_TCP_DEFAULT_TTL                           37
#define D4OPT_TCP_KEEPALIVE_INTERVAL                    38
#define D4OPT_TCP_KEEPALIVE_GARBAGE                     39

// Application and Service Parameters

#define D4OPT_NIS_DOMAIN                                40
#define D4OPT_NIS_SERVERS                               41
#define D4OPT_NTP_SERVERS                               42
#define D4OPT_VENDOR_SPECIFIC                           43
#define D4OPT_NBT_NAME_SERVER                           44
#define D4OPT_NBT_DGRAM_DISTRIBUTION_SERVER             45
#define D4OPT_NBT_NODE_TYPE                             46
#define D4OPT_NBT_SCOPE                                 47
#define D4OPT_X_SYSTEM_FONT_SERVER                      48
#define D4OPT_X_SYSTEM_DISPLAY_MANAGER                  49

// DHCP Extensions

#define D4OPT_REQUESTED_IP_ADDRESS                      50
#define D4OPT_IP_ADDRESS_LEASE_TIME                     51
#define D4OPT_OVERLOAD                                  52
#define D4OPT_DHCP_MESSAGE_TYPE                         53
#define D4OPT_SERVER_IDENTIFIER                         54
#define D4OPT_PARAMETER_REQUEST_LIST                    55
#define D4OPT_MESSAGE                                   56
#define D4OPT_MAX_DHCP_MESSAGE_SIZE                     57
#define D4OPT_RENEWAL_TIME_VALUE                        58
#define D4OPT_REBINDING_TIME_VALUE                      59
#define D4OPT_VENDOR_CLASS_IDENTIFIER                   60
#define D4OPT_CLIENT_IDENTIFIER                         61
#define D4OPT_NWIP_DOMAIN_NAME                          62
#define D4OPT_NWIP_SUB_OPT                              63

#define D4OPT_NIS_PLUS_DOMAIN                           64
#define D4OPT_NIS_PLUS_SERVERS                          65

// Application and Service Parameters - Continued

#define D4OPT_MOBILE_IP_HOME_AGENT                      68
#define D4OPT_SMTP_SERVER                               69
#define D4OPT_POP3_SERVER                               70
#define D4OPT_NNTP_SERVER                               71
#define D4OPT_DEFAULT_WWW_SERVER                        72
#define D4OPT_DEFAULT_FINGER_SERVER                     73
#define D4OPT_DEFAULT_IRC_SERVER                        74
#define D4OPT_STREETTALK_SERVER                         75
#define D4OPT_STDA_SERVER                               76

#define D4OPT_USER_CLASS                                77
#define D4OPT_FQDN                                      81
#define D4OPT_AGENT_OPTIONS                             82

#define D4OPT_AUTHENTICATE                              90
#define D4OPT_CLIENT_LAST_TRANSACTION_TIME              91
#define D4OPT_ASSOCIATED_IP                             92
#define D4OPT_IPV6_ONLY_PREFER                          108
#define D4OPT_SUBNET_SELECTION                          118
#define D4OPT_DOMAIN_SEARCH                             119
#define D4OPT_VIVCO_SUB_OPTIONS                         124
#define D4OPT_VIVSO_SUB_OPTIONS                         125

#define D4OPT_END                                       255

#endif
