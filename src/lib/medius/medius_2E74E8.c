/*
 * lib/medius: 3 files, 002E74E8-002E7670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E74E8 */
typedef struct { int f0; int f4; int f8; } Ent;
typedef struct { char pad[0x400]; int f400; } Ctx;
typedef struct { unsigned char a; char pad; unsigned short b; } Pk;
extern unsigned int D_0048C450;
extern int D_005983E0;
extern int NetIGetObject(unsigned int *, unsigned short);
extern int NetGetConnInfo(unsigned int, Ctx **);
extern int RemoteObjectUpdate(int, unsigned short, int);
extern unsigned char NetClientIndexToClientIndexPacket(int);
extern int NetSendDmeMessage(int, int, int, int, int, Pk *);
int RequestOwnershipPacketHandler(int a, int b, int c, unsigned short *idp)
{
    Pk pk;
    unsigned int e[1];
    Ctx *ctx[1];
    unsigned short id;
    ctx[0] = 0;
    e[0] = 0;
    if (idp == 0) return -1;
    if (D_0048C450 >= 4) return -1;
    id = *idp;
    if (id >= 0x1000) return -1;
    NetIGetObject(e, id);
    if (e[0] == 0) return -1;
    if (NetGetConnInfo(D_0048C450, ctx) || ctx[0] == 0) return -1;
    if (((Ent *)e[0])->f8 != ctx[0]->f400 || ((Ent *)e[0])->f4 != -1) return 2;
    ((Ent *)e[0])->f4 = c;
    RemoteObjectUpdate(((Ent *)e[0])->f4, id, -2);
    pk.a = NetClientIndexToClientIndexPacket(c);
    pk.b = id;
    NetSendDmeMessage(0x50, a, -1, D_005983E0, 4, &pk);
    return 2;
}
/* merge_units: end func_002E74E8 */

/* merge_units: begin func_002E7608 */
#if 0 /* merge_units */
extern int NetIGetObject(int **, unsigned int);
#endif /* merge_units */
#define NetIGetObject(a0, a1) (NetIGetObject((unsigned int *)(a0), (unsigned short)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void RemoteObjectUpdate(int, unsigned int, int);
#endif /* merge_units */
#define RemoteObjectUpdate(a0, a1, a2) ((void)RemoteObjectUpdate((a0), (unsigned short)(a1), (a2))) /* merge_units */

int GrantOwnershipPacketHandler(int a, int b, int c, unsigned char *k)
{
    int *p;
    unsigned char v;
    if (k == 0) return -1;
    v = k[0];
    NetIGetObject(&p, *(unsigned short *)(k + 2));
    if (p) {
        p[1] = v;
        RemoteObjectUpdate(p[1], *(unsigned short *)(k + 2), -2);
    }
    return 4;
}
#undef NetIGetObject /* merge_units */
#undef RemoteObjectUpdate /* merge_units */
/* merge_units: end func_002E7608 */

/* merge_units: begin func_002E7670 */
#if 0 /* merge_units */
extern int NetIGetObject(int **, unsigned int);
#endif /* merge_units */
#define NetIGetObject(a0, a1) (NetIGetObject((unsigned int *)(a0), (unsigned short)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void RemoteObjectUpdate(int, unsigned int, int);
#endif /* merge_units */
#define RemoteObjectUpdate(a0, a1, a2) ((void)RemoteObjectUpdate((a0), (unsigned short)(a1), (a2))) /* merge_units */

int ReleaseOwnershipPacketHandler(int a, int b, int c, unsigned short *k)
{
    int *p;
    if (k == 0) return -1;
    NetIGetObject(&p, *k);
    if (p == 0) return 2;
    p[1] = -1;
    RemoteObjectUpdate(p[1], *k, -2);
    return 2;
}
#undef NetIGetObject /* merge_units */
#undef RemoteObjectUpdate /* merge_units */
/* merge_units: end func_002E7670 */
