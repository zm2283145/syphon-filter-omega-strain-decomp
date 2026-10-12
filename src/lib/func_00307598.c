typedef struct { int f0; int f4; char name[16]; unsigned short port; char pad[0x76]; } RtPeer;
typedef struct {
    int f0; RtPeer *peers; int f8; char q[0x20]; unsigned int npeers;
} RtUdp;
typedef struct { char name[16]; unsigned char port[2]; } RtAddr;
extern int func_002FABD0(void *list, void **pkt);
extern char *func_002FAED0(void *pkt);
extern char *strncpy(char *d, const char *s, unsigned int n);
int func_00307598(RtUdp *r, unsigned int ep, char *addr, unsigned short *port)
{
    int ret = 2;
    void *pkt = 0;
    RtAddr a;
    if (r == 0) return ret;
    ret = 1;
    if (addr == 0) return ret;
    if (port == 0) return ret;
    if (ep < r->npeers) {
        strncpy(addr, r->peers[ep].name, 16);
        *port = r->peers[ep].port;
        return 0;
    }
    if (ep == (unsigned int)-2) {
    if (func_002FABD0(r->q, &pkt) != 0) return 10;
    a = *(RtAddr *)func_002FAED0(pkt);
    strncpy(addr, a.name, 16);
    *port = *(unsigned short *)a.port;
    return 0;
    }
    return 3;
}

