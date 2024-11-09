# Coraltium InfiniRoute - Standard Edition
Coraltium InfiniRoute SE is a work in progress project to build a complete FOSS Linux-based router operating system for enterprise networking which aims to rival similar proprietary Router platforms, like Cisco IOS, Juniper Junos and Netgate TNSR, to name examples. InfiniRoute SE is currently being developed for usage with Debian GNU/Linux as its underlying operating system, though this is not set in stone. It is being designed to support IPv6 and IPv4 routing, along with other features present on the opposing solutions mentioned prior. The full list of features will be listed below.

This specific project was renamed to "InfiniRoute Standard Edition (SE)" due to its intended usage being somewhat general. Expect to see more use case-specific derivatives of the project in the future for use in i.e. Service Provider networks, Data Center networks, and possibly even Ethernet switching firmware. The Standard Edition will still be more than adequate to handle extensive network traffic and large routing tables.

# Features - Routing Protocols
The following routing protocols are to be implemented:

* Babel
* BGP-4
* EIGRP (Partial)
* IS-IS
* MRT
* OpenFabric
* OSPFv2
* OSPFv3
* PIM
* RIPv1
* RIPv2
* RIPng

# Features - Routing Services

* Policy-Based Routing
* Segment Routing
* BFD
* MPLS/LDP
* VRFs, Network Namespaces

# Features - Link-Layer Services

* IEEE 802.1Q VLANs
* Spanning Tree: 802.1D CST, 802.1w RST, 802.1s MST
* TRILL
* IEEE 802.1AE MACsec
* IEEE 802.1ad Q-in-Q
* IEEE 802.1ah MAC-in-MAC Provider Backbone Bridge
* PPPoE Server
* Private VLANs
* VLAN ACLs
* ARP ACLs
* LLDP

# Features - General Network Services

* DHCP Client/Server
* DHCPv6 Client/Server/Prefix Delegation
* SLAAC + RDNSS
* DNS Client/Server
* Dynamic DNS Client
* CARP
* VRRP
* IPv4: NAT44, NAT46
* IPv6: NAT66, NAT64, 464XLAT, MAP, 6RD, Teredo, SIIT

# Features - Security

* AAA Services: RADIUS/TACACS+/Diameter/LDAP
* ACLs for Stateless Filtering
* Stateful Firewall Rules
* Support for DNSSEC/DNSKEY

# Features - VPN and Tunneling

* WireGuard
* OpenVPN
* IPsec
* L2TP
* PPTP
* OpenConnect
* Tailscale/Headscale
* ZeroTier
* GRE, DMVPN
