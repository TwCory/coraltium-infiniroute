// Minimal Clixon backend plugin: apply hostname on commit.
// Builds: libclixon_backend_voltos.so
#define _GNU_SOURCE
#include <clixon/clixon_backend.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static int write_etc_hostname(const char *name){
    FILE *f = fopen("/etc/hostname","w");
    if (!f) return -1;
    int rc = (fprintf(f, "%s\n", name) < 0) ? -1 : 0;
    fclose(f);
    return rc;
}

/* Find /vsys:system/hostname in the candidate datastore and return a pointer.
   We only scan a couple levels (top-level container + leaf) to keep this tiny. */
static const char* candidate_hostname_get(clicon_handle h){
    cxobj *cand = clicon_candidate_config(h);
    if (!cand) return NULL;

    cxobj *x = NULL;
    while ((x = xml_child_each(cand, x, CX_ELMNT)) != NULL){
        if (strcmp(xml_name(x), "system") == 0){
            const char *v = xml_find_value(x, "hostname");
            if (v && v[0]) return v;
            return NULL; /* present but empty/default */
        }
    }
    return NULL; /* no system container */
}

/* Called when user commits candidate -> running.
   We read the candidate value and apply to OS. */
static int be_commit(clicon_handle h, transaction_data *tx){
    const char *hn = candidate_hostname_get(h);
    if (!hn) return 0; /* nothing to do */

    /* Apply immediately: sethostname() and persist /etc/hostname
       (Requires root; ok for a router OS.) */
    if (sethostname(hn, strlen(hn)) != 0){
        clicon_err(OE_CFG, 0, "sethostname('%s') failed", hn);
        return -1;
    }
    if (write_etc_hostname(hn) != 0){
        clicon_err(OE_CFG, 0, "Failed to write /etc/hostname");
        return -1;
    }
    return 0;
}

clixon_plugin_api *clixon_plugin_init(clicon_handle h){
    static clixon_plugin_api api = {0};
    api.ca_commit = be_commit;
    return &api;
}

int clixon_plugin_exit(clicon_handle h){
    return 0;
}
