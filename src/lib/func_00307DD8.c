typedef struct { int state; char pad4[0x30]; char q34[0x50]; int f84; char pad88[8]; } RtPeer;
typedef struct {
    int f0; RtPeer *peers; int f8; char q[0x20]; unsigned int npeers;
} RtUdp;
typedef struct {
    unsigned char flags; unsigned char b1;
    unsigned short len; unsigned int seq4; unsigned int seq;
} RtHdr;
extern int func_002FABD0(void *list, void **pkt);
extern char *func_002FAED0(void *pkt);
extern int func_002FAEE8(void *pkt);
extern void *func_002FAF00(void *pkt);
extern void func_002FA830(void *list, void *pkt);
extern void *memcpy(void *d, const void *s, unsigned int n);
int RtUdp_Read(RtUdp *r, unsigned int idx, void *dst, unsigned int max, unsigned int *out)
{
    void *p = 0;
    RtHdr h;
    RtPeer *e;
    int ret = 1;
    if (r == 0) return ret;
    if (dst == 0) return ret;
    if (max == 0) return ret;
    if (out == 0) return ret;
    *out = 0;
    if (idx == (unsigned)-2) {
        if (func_002FABD0(r->q, &p) != 0) return 10;
        if (p == 0 || func_002FAEE8(p) == 0) { *out = 0; return 0; }
        memcpy(&h, func_002FAED0(p) + 0x12, sizeof(h));
        *out = (h.len >= max) ? max : h.len;
        memcpy(dst, func_002FAED0(p) + 0x1E, *out);
        func_002FA830(r->q, p);
        return 0;
    }
    if (idx < r->npeers) {
    e = &r->peers[idx];
    if (e->state != 12) return 4;
    if (func_002FABD0(e->q34, &p) != 0) return 10;
    while (p != 0) {
        if (func_002FAEE8(p) != 0) {
            memcpy(&h, func_002FAED0(p), sizeof(h));
            if ((*(unsigned int *)&h & 6) == 6 || (h.flags & 4)) {
                if (h.seq == e->f84 + 1 || e->f84 == 0) {
                *out = (h.len >= max) ? max : h.len;
                memcpy(dst, func_002FAED0(p) + 0xC, *out);
                func_002FA830(e->q34, p);
                e->f84 = h.seq;
                if (e->f84 == (unsigned)-1) e->f84 = 0;
                return 0;
                }
            } else {
            *out = (h.len >= max) ? max : h.len;
            memcpy(dst, func_002FAED0(p) + 0xC, *out);
            func_002FA830(e->q34, p);
            return 0;
            }
        }
        p = func_002FAF00(p);
    }
    *out = 0;
    return 0;
    }
    return 1;
}

