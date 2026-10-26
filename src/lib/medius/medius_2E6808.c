/*
 * lib/medius: 9 files, 002E6808-002E6ED8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E6808 */
extern int D_0048C4B0;
extern int rt_p2p_get_peer_buffer_stats(int, int, int *, int *, int *, int *);
int NetIGetClientBufferStatus(unsigned int a, int b, int *o0, int *o1, int *o2, int *o3)
{
    int v[4];
    if (a != 0xFFFF && a != 0) return 0xF;
    if (rt_p2p_get_peer_buffer_stats(D_0048C4B0, b, &v[0], &v[1], &v[2], &v[3])) return 0x25;
    if (o0) *o0 = v[0];
    if (o2) *o2 = v[2];
    if (o1) *o1 = v[1];
    if (o3) *o3 = v[3];
    return 0;
}
/* merge_units: end func_002E6808 */

/* merge_units: begin func_002E68C0 */
extern char D_0058C178[];
int GetFreeNetObjectBlock(int n)
{
    int i, j, k, ok;
    if ((unsigned)n >= 0x1000) return 0x100;
    for (i = 0; i < 0x1000 - n; i++) {
        if (D_0058C178[i] == 0) {
            ok = 1;
            for (j = i + 1; j < i + n; j++) {
                if (D_0058C178[j] != 0) { ok = 0; break; }
            }
            if (ok) {
                for (k = i; k < i + n; k++) D_0058C178[k] = 1;
                return i;
            }
        }
    }
    return -1;
}
/* merge_units: end func_002E68C0 */

/* merge_units: begin func_002E69B8 */
extern int NetIGetDataStream(unsigned char **, unsigned int);
int FindFreeDataStreamBlock(int n)
{
    unsigned char *b;
    int i, j, ok;
    if ((unsigned int)n >= 0x800) return -1;
    for (i = 0; i < 0x800 - n; i++) {
        NetIGetDataStream(&b, i);
        if (*b == 0) {
            ok = 1;
            for (j = i + 1; j < i + n; j++) {
                NetIGetDataStream(&b, j);
                if (*b) { ok = 0; break; }
            }
            if (ok) return i;
        }
    }
    return -1;
}
/* merge_units: end func_002E69B8 */

/* merge_units: begin func_002E6AA8 */
typedef struct { signed char f0; unsigned char f1; char name[6]; char f8[8]; } Q;
typedef struct { char pad[0x400]; int f400; } Ctx;
extern char D_00588074[];
extern unsigned short D_0058D178, D_0058C0B0;
extern int NetGetConnInfo(int, Ctx **);
extern int Net_IpToString(char *, char *);
extern int strcmp(const char *, const char *);
extern int DmeToRtMsgConnectionIndex(int);
extern int KM_SetPublicKey(int, int, char *);
extern int RemoteClientConnects(int, int, char *, int);
int ClientConnectsPacketHandler(int h, int b, int c, Q *q)
{
    char name[16];
    Ctx *ctx[1];
    int h2 = h;
    ctx[0] = 0;
    if (q == 0) return -1;
    if (NetGetConnInfo(h, ctx) || ctx[0] == 0) return -1;
    Net_IpToString(name, q->name);
    if (q->f0 == 0) h2 = 0;
    if (strcmp(name, D_00588074) != 0 || q->f1 != ctx[0]->f400) {
        if (h == 0xFFFF) KM_SetPublicKey(-1, q->f1, q->f8);
        else if (h == 0) KM_SetPublicKey(0, q->f1, q->f8);
        else KM_SetPublicKey(DmeToRtMsgConnectionIndex(h), q->f1, q->f8);
    }
    RemoteClientConnects(h2, q->f1, name, D_0058D178 == 0 ? D_0058C0B0 : D_0058D178);
    return 0x48;
}
/* merge_units: end func_002E6AA8 */

/* merge_units: begin func_002E6BC0 */
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, char **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((int)(a0), (Ctx * *)(a1))) /* merge_units */

extern char *strncpy(char *, const char *, unsigned int);
int ServerVersionPacketHandler(unsigned int a, int b, int c, const char *name)
{
    char *p[1];
    p[0] = 0;
    if (name == 0) return -1;
    if (a >= 4) return 0x10;
    if (NetGetConnInfo(a, p) || p[0] == 0) return -1;
    strncpy(p[0] + 0x418, name, 0x10);
    return 0x10;
}
#undef NetGetConnInfo /* merge_units */
/* merge_units: end func_002E6BC0 */

/* merge_units: begin func_002E6C30 */
extern void NetClientLeaves(unsigned int, unsigned int);
int ClientLeavesPacketHandler(unsigned int a, int b, unsigned int c, int d)
{
    if (d == 0) return -1;
    if (a >= 4) return 1;
    if (c >= 0x100) return 1;
    NetClientLeaves(a, c);
    return 1;
}
/* merge_units: end func_002E6C30 */

/* merge_units: begin func_002E6C78 */
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
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, void **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((int)(a0), (Ctx * *)(a1))) /* merge_units */

extern int NetGetClientInfo(unsigned int, unsigned int, void **);
extern void NetIGetClient(Ent **, unsigned int, unsigned int);
extern Ent *NetCreateClient(unsigned int, unsigned int);
extern void NetClientJoins(unsigned int, unsigned int);
extern char *String_Copy(char *, const char *);

int ClientUpdatePacketHandler(unsigned int slot, int a1, int a2, Msg *m)
{
    Ent *e = 0;
    void *p = 0;
    void *q = 0;
    unsigned int id;
    int r;

    if (m == 0) return -1;
    r = 0x24;
    if (NetGetConnInfo(slot, &p) == 0 && p != 0
        && NetGetClientInfo(slot, F(p, unsigned int, 0x400), &q) == 0 && q != 0
        && (unsigned int)(F(q, int, 0x14) - 4) < 2) {
        id = m->b0;
        if (slot >= 4) return r;
        if (id >= 0x100) return r;
        NetIGetClient(&e, slot, id);
        if (e == 0) {
            e = NetCreateClient(slot, id);
            if (e == 0) return r;
        }
        e->f4 = m->s8;
        e->f6 = m->sA;
        e->f8 = m->sC;
        e->fA = m->sE;
        e->fC = m->s10;
        String_Copy(e->name, m->name);
        if (e->f0 == 0) NetClientJoins(slot, id);
    }
    return 0x24;
}
#undef NetGetConnInfo /* merge_units */
/* merge_units: end func_002E6C78 */

/* merge_units: begin func_002E6DC8 */
typedef struct { unsigned char b[4]; } IP4;
typedef struct { int port; IP4 ip; } Addr;
extern int D_0058D17C, D_0058D180, D_005983D8;
extern IP4 D_0058DF80;
extern unsigned short D_0058C0B0;
extern char D_0058808C[];
extern int NetIsPeerToPeerHost(unsigned char *);
extern int NetGetCurrentUDPSourceBinaryIP(char *);
extern int NetIIpStringToBinary(IP4 *, char *);
extern int NetISendMessageByUDPToIP(int, char *, int, int, int, Addr *);
int RequestServersPacketHandler(int a, int b, int c, int *id)
{
    char b1[16];
    char b2[16];
    unsigned char flag[16];
    Addr ad;
    int g;
    flag[0] = 0;
    if (id == 0) return -1;
    if (NetIsPeerToPeerHost(flag)) return 4;
    NetGetCurrentUDPSourceBinaryIP(b2);
    Net_IpToString(b1, b2);
    g = D_0058D17C;
    if (g != 0 || flag[0] != 0) {
        if (*id != D_0058D180) return 4;
        if (g) ad.ip = D_0058DF80;
        else NetIIpStringToBinary(&ad.ip, D_0058808C);
        if (flag[0] == 1) ad.port = D_0058C0B0;
        else ad.port = D_0058D17C;
        NetISendMessageByUDPToIP(0, b2, 0, D_005983D8, 8, &ad);
    }
    return 4;
}
/* merge_units: end func_002E6DC8 */

/* merge_units: begin func_002E6ED8 */
extern void (*D_0058DF84)(char *, int);
#if 0 /* merge_units */
extern void Net_IpToString(char *, int *);
#endif /* merge_units */
#define Net_IpToString(a0, a1) ((void)Net_IpToString((a0), (char *)(a1))) /* merge_units */

int ServerResponsePacketHandler(int a, int b, int c, int *k)
{
    char buf[16];
    if (k == 0) return -1;
    {
        void (**pf)(char *, int) = &D_0058DF84;
        if (*pf != 0) {
            Net_IpToString(buf, k + 1);
            (*pf)(buf, k[0]);
        }
    }
    return 8;
}
#undef Net_IpToString /* merge_units */
/* merge_units: end func_002E6ED8 */
