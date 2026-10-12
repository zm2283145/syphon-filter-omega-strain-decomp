typedef struct { int state; char pad[0x8C]; } Ent7928;
typedef struct { char pad[4]; Ent7928 *ents; char pad2[0x24]; unsigned int count; } Pool7928;
extern int RtUdp_BuildHeader(Pool7928 *p, Ent7928 *e, int kind, unsigned char *hdr);
extern int RtUdp_CopyPacket(Ent7928 *e, unsigned char *hdr, void *body, int n);
int func_00307928(Pool7928 *p, unsigned int idx)
{
    unsigned char hdr[12];
    Ent7928 *e;
    int r;
    if (p == 0) return 2;
    if (idx >= p->count) return 3;
    e = &p->ents[idx];
    if (e->state == 12 || e->state == 3) {
        e->state = 5;
        r = RtUdp_BuildHeader(p, e, 4, hdr);
        if (r != 0) return r;
        hdr[0] |= 0x10;
        r = RtUdp_CopyPacket(e, hdr, 0, 0);
        if (r != 0) return r;
    } else {
        e->state = 4;
    }
    return 0;
}
