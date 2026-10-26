/*
 * lib/medius: 2 files, 00315818-003158D8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00315818 */
typedef struct { int a; int b; int c; int d; int e; int f; int g; } Arg5818;
typedef struct { int h; char pad[2]; unsigned char b6; } Ent5818;
typedef struct {
    int id;
    char pad0[8];
    int xC;
    char pad1[0xA9 - 0x10];
    unsigned char mode;
    char pad2[2];
    int xAC;
    int xB0;
    int xB4;
    int xB8;
    int xBC;
} Obj5818;
extern int D_00598428;
extern int NetStreamMediaIsValidInfo(Obj5818 *o);
extern int NetSendDmeMessage(int op, int id, int h, int k, int len, Arg5818 *a);
int NetStreamMediaSendAddressInfo(Obj5818 *o, Ent5818 *e)
{
    Arg5818 a;
    int m, r;
    if (NetStreamMediaIsValidInfo(o) != 1) return 0x17;
    if (e == 0) return 0x17;
    m = o->mode;
    if (m != 1) return 0x17;
    a.a = o->id;
    a.b = o->xC;
    a.c = o->xB0;
    a.d = o->xB8;
    a.e = o->xAC;
    a.f = o->xB4;
    a.g = o->xBC;
    r = NetSendDmeMessage(0x50, o->id, e->h, D_00598428, 0x1C, &a);
    if (r == 0) e->b6 = m;
    return r;
}
/* merge_units: end func_00315818 */

/* merge_units: begin func_003158D8 */
typedef struct {
    char pad0[0xFC];
    int ids[0x40];
    char pad1FC[0x208 - 0x1FC];
    unsigned char state;
    char pad209[7];
    unsigned int idx;
    int x214;
} Obj58D8;
extern int NetStreamMediaFindValidInfo(int id, Obj58D8 **out);
int NetStreamMediaEnumChannelCallback(int id, int unused, unsigned short *msg)
{
    Obj58D8 *o = 0;
    Obj58D8 *p;
    unsigned int i;
    if (msg == 0) return 0;
    if (NetStreamMediaFindValidInfo(id, &o) != 0) return 0;
    p = o;
    i = p->idx;
    if (i >= 0x40) return 0;
    if (p->state != 1) return 1;
    if (p->ids[i] == msg[0]) {
        p->x214 = msg[1];
        p->state = 0;
        return 0;
    }
    return 1;
}
/* merge_units: end func_003158D8 */
