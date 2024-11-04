// SPDX-License-Identifier: GPL-2.0+

/*
 *  Coraltium InfiniRoute NOS - Standard:
 *
 *  Standard ACL Definitions (src/acl/acl-standard.h):
 *  
 *  
 *  Version:    1.0.3       2024-11-03
 *
 *  Author(s):
 *  -> Cory Voltz, voltzc@twchl.net
 *
 *  Disclaimer:
 *      Coraltium InfiniRoute is a free and open source project, and can thus be redistributed and/or modified
 *      under the terms of the GPL.
 */

#ifndef _CT_ACL_STANDARD_H_
#define _CT_ACL_STANDARD_H_

#define STD_ACL_MAX_ENTRIES              10000

#define STD_ACL_NUM_MIN_1                1
#define STD_ACL_NUM_MAX_1                99
#define STD_ACL_NUM_MIN_2                1300
#define STD_ACL_NUM_MAX_2                1999

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    int std_acl_number;
    int std_acl_entry_action;
    char std_acl_source[16];
    int std_acl_source_mask;

} Standard_ACL_Entry;

void add_std_acl_entry(int acl_number, int acl_action, const char *source, int source_mask);
void apply_std_acl();

#endif /* _CT_ACL_STANDARD_H_ */
