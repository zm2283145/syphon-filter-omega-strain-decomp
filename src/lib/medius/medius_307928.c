/*
 * lib/medius: 2 files, 00307928-003079E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00307928 */
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
/* merge_units: end func_00307928 */

/* merge_units: begin func_003079E0 */
typedef struct { int type; char pad[0x18]; int f1C; int f20; int f24; int f28; int f2C; int f30; int f34; int f38; int f3C; char pad2[0x4C]; int f8C; } ScfEnt;
typedef struct { int f0; ScfEnt *ent; char pad[0x24]; unsigned int count; } ScfTbl;
int func_003079E0(ScfTbl *t, unsigned int idx, int val)
{
    int ret = 2;
    if (t == 0) return ret;
    if (idx >= t->count) return 3;
    t->ent[idx].f8C = val;
    return 0;
}
/* merge_units: end func_003079E0 */
