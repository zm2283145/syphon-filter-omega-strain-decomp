/*
 * lib/medius: 8 files, 002DB388-002DB820
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DB388 */
extern int D_0051F0D0;
extern char D_0048C440;
extern void NetFreeClient(unsigned int, int);
void NetFreeClients(unsigned int a)
{
    int i;
    if (a >= 4) return;
    if (D_0051F0D0)
        for (i = 0; i < 0x100; i++) NetFreeClient(a, i);
    D_0048C440 = 0;
}
/* merge_units: end func_002DB388 */

/* merge_units: begin func_002DB3F0 */
#if 0 /* merge_units */
extern void NetFreeClients(int);
#endif /* merge_units */
#define NetFreeClients(a0) (NetFreeClients((unsigned int)(a0))) /* merge_units */

void NetFreeAllClients(void)
{
    int i;
    if (D_0051F0D0)
        for (i = 0; i < 4; i++) NetFreeClients(i);
    D_0048C440 = 0;
}
#undef NetFreeClients /* merge_units */
/* merge_units: end func_002DB3F0 */

/* merge_units: begin func_002DB440 */
#if 0 /* merge_units */
extern int D_0051F0D0[];
#endif /* merge_units */
#define D_0051F0D0 ((int*)&D_0051F0D0) /* merge_units */

extern void DmeFree(int* p);
void NetFreeClientPointers(void)
{
    if (D_0051F0D0[0] != 0)
        DmeFree(D_0051F0D0);
}
#undef D_0051F0D0 /* merge_units */
/* merge_units: end func_002DB440 */

/* merge_units: begin func_002DB470 */
typedef struct { int x0; unsigned short x4, x6, x8, xA, xC; } N2DB470;
extern signed char D_0058C178[];
extern int NetIGetDataStream(unsigned char **, unsigned int);
void ReserveNetObjectsAndDataStreamsForClient(N2DB470 *n)
{
    int i;
    unsigned char *e;
    if (n == 0) return;
    if (n->x6 < 0x1000) {
        for (i = 0; i < n->x8; i++)
            if (D_0058C178[i + n->x6] == 0) D_0058C178[i + n->x6] = 1;
    }
    if (n->xA < 0x800) {
        for (i = 0; i < n->xC; i++) {
            NetIGetDataStream(&e, i + n->xA);
            if (e) *e = 1;
        }
    }
}
/* merge_units: end func_002DB470 */

/* merge_units: begin func_002DB550 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct Ent {
    int f0;
    unsigned short f4, f6, f8, fA, fC;
    char name[1];
} Ent;
typedef struct Msg {
    unsigned char b0;
    char pad1[7];
    unsigned short s8, sA, sC, sE, s10;
    char pad12[4];
    char name[0x12];
} Msg;
extern unsigned int D_0048C450;
extern int D_00598410;
extern int NetGetConnInfo(unsigned int, void **);
extern int NetGetClientInfo(unsigned int, unsigned int, void **);
extern unsigned char NetClientIndexToClientIndexPacket(unsigned int);
extern void NetIGetClient(Ent **, unsigned int, unsigned int);
extern char *Libc_Strcpy(char *, const char *);
extern int NetSendDmeMessage(int, unsigned int, int, int, int, Msg *);
int NetISendMyClientUpdate(unsigned int slot, int who)
{
    Msg m;
    void *p = 0;
    void *q = 0;
    Ent *e;
    int r;
    if ((unsigned int)(who + 1) > 0x100) return 0x17;
    if (slot >= 4) return 0x17;
    r = NetGetConnInfo(slot, &p);
    if (r) return r;
    if (p == 0) return 8;
    r = NetGetClientInfo(slot, F(p, unsigned int, 0x400), &q);
    if (r) return r;
    if (q == 0) return 8;
    NetIGetClient(&e, slot, F(p, unsigned int, 0x400));
    if (e == 0) return 0x15;
    if ((unsigned int)(F(q, int, 0x14) - 4) < 2) {
    m.b0 = NetClientIndexToClientIndexPacket(F(p, unsigned int, 0x400));
    m.s8 = e->f4;
    m.sA = e->f6;
    m.sC = e->f8;
    m.sE = e->fA;
    m.s10 = e->fC;
    Libc_Strcpy(m.name, e->name);
    NetSendDmeMessage(0x50, D_0048C450, who, D_00598410, 0x24, &m);
    return 0;
    }
    return 0x15;
}
/* merge_units: end func_002DB550 */

/* merge_units: begin func_002DB688 */
extern int NetIsValidClientIndex(int);
#if 0 /* merge_units */
extern void NetIGetClient(char **, unsigned int, int);
#endif /* merge_units */
#define NetIGetClient(a0, a1, a2) (NetIGetClient((Ent * *)(a0), (a1), (unsigned int)(a2))) /* merge_units */

extern char *NetCreateClient(unsigned int, int);
#if 0 /* merge_units */
extern void NetISendMyClientUpdate(unsigned int, int);
#endif /* merge_units */
#define NetISendMyClientUpdate(a0, a1) ((void)NetISendMyClientUpdate((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void ReserveNetObjectsAndDataStreamsForClient(char *);
#endif /* merge_units */
#define ReserveNetObjectsAndDataStreamsForClient(a0) (ReserveNetObjectsAndDataStreamsForClient((N2DB470 *)(a0))) /* merge_units */

void MyClientJoins(unsigned int a, int b)
{
    char *p;
    if (NetIsValidClientIndex(b) != 1) return;
    if (a >= 4) return;
    NetIGetClient(&p, a, b);
    if (p == 0) {
        p = NetCreateClient(a, b);
        if (p == 0) return;
    }
    *(unsigned short *)(p + 4) = 0x1000;
    NetISendMyClientUpdate(a, -1);
    ReserveNetObjectsAndDataStreamsForClient(p);
}
#undef NetIGetClient /* merge_units */
#undef NetISendMyClientUpdate /* merge_units */
#undef ReserveNetObjectsAndDataStreamsForClient /* merge_units */
/* merge_units: end func_002DB688 */

/* merge_units: begin func_002DB720 */
extern int D_0058806C;
extern void (*D_0058DF8C)(int *);
int D_0048C47C = 0;
#if 0 /* merge_units */
extern void NetIGetClient(char **, unsigned int, int);
#endif /* merge_units */
#define NetIGetClient(a0, a1, a2) (NetIGetClient((Ent * *)(a0), (a1), (unsigned int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern int NetGetClientInfo(unsigned int, int, char **);
#endif /* merge_units */
#define NetGetClientInfo(a0, a1, a2) (NetGetClientInfo((a0), (unsigned int)(a1), (void * *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void ReserveNetObjectsAndDataStreamsForClient(char *);
#endif /* merge_units */
#define ReserveNetObjectsAndDataStreamsForClient(a0) (ReserveNetObjectsAndDataStreamsForClient((N2DB470 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void NetISendMyClientUpdate(unsigned int, int);
#endif /* merge_units */
#define NetISendMyClientUpdate(a0, a1) ((void)NetISendMyClientUpdate((a0), (a1))) /* merge_units */

void NetClientJoins(unsigned int a, int b)
{
    char *q = 0;
    char *e = 0;
    int t[4];
    int st = NetIsValidClientIndex(b);
    if (st != 1) return;
    if (a >= 4) return;
    NetIGetClient(&e, a, b);
    if (e == 0) e = NetCreateClient(a, b);
    if (NetGetClientInfo(a, b, &q)) return;
    if (q == 0) return;
    *(int *)e = D_0058806C;
    q[0x29] = st;
    ReserveNetObjectsAndDataStreamsForClient(e);
    if (D_0058DF8C) {
        t[0] = 0;
        t[1] = a;
        t[2] = b;
        t[3] = D_0048C47C;
        D_0058DF8C(t);
    }
    NetISendMyClientUpdate(a, b);
}
#undef NetIGetClient /* merge_units */
#undef NetGetClientInfo /* merge_units */
#undef ReserveNetObjectsAndDataStreamsForClient /* merge_units */
#undef NetISendMyClientUpdate /* merge_units */
/* merge_units: end func_002DB720 */

/* merge_units: begin func_002DB820 */
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, char **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((a0), (void * *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void NetIGetClient(char **, unsigned int, int);
#endif /* merge_units */
#define NetIGetClient(a0, a1, a2) (NetIGetClient((Ent * *)(a0), (a1), (unsigned int)(a2))) /* merge_units */

extern int NetIGetObject(char **, unsigned int);
#if 0 /* merge_units */
extern void NetISendMyClientUpdate(unsigned int, int);
#endif /* merge_units */
#define NetISendMyClientUpdate(a0, a1) ((void)NetISendMyClientUpdate((a0), (a1))) /* merge_units */

int NetISetMyClientObject(unsigned int id)
{
    char *p = 0;
    char *q;
    char *e;
    int r;
    if (D_0048C450 >= 4) return 8;
    if (id >= 0x1000) return 0x17;
    r = NetGetConnInfo(D_0048C450, &p);
    if (r) return r;
    NetIGetClient(&q, D_0048C450, *(int *)(p + 0x400));
    if (q == 0) return 0x15;
    NetIGetObject(&e, id);
    if (e == 0) return 0x1E;
    if (*(int *)(e + 4) != *(int *)(p + 0x400)) return 8;
    ((struct { int a; unsigned short id; } *)q)->id = id;
    NetISendMyClientUpdate(D_0048C450, -1);
    return 0;
}
#undef NetGetConnInfo /* merge_units */
#undef NetIGetClient /* merge_units */
#undef NetISendMyClientUpdate /* merge_units */
/* merge_units: end func_002DB820 */
