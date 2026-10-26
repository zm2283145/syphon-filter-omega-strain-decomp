/*
 * lib/medius: 4 files, 002DD488-002DD8A8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DD488 */
extern void *memset(void *, int, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern int D_0048C458;
extern char D_00588074[];
int NetIGetMyIpAddress(char *p)
{
    if (p == 0) return 0x17;
    memset(p, 0, 0x10);
    if (D_0048C458 == 0) return 0x11;
    strncpy(p, D_00588074, 0x10);
    return 0;
}
/* merge_units: end func_002DD488 */

/* merge_units: begin func_002DD4E8 */
extern int NetGetConnInfo(unsigned int, char **);
extern int NetGetClientInfo(unsigned int, unsigned int, unsigned char **);
int NetIGetClientIpAddress(char *dst, unsigned int a, unsigned int b)
{
    char *p = 0;
    unsigned char *q = 0;
    int r;
    if (dst == 0) return 0x17;
    memset(dst, 0, 0x10);
    if (b >= 0x100) return 0x17;
    if (a >= 4) return 0x17;
    r = NetGetConnInfo(a, &p);
    if (r) return r;
    if (p == 0) return 0xF;
    r = NetGetClientInfo(a, b, &q);
    if (r) return r;
    if (q == 0) return 8;
    if (q[0x28] == 0) return 8;
    strncpy(dst, (char *)q, 0x10);
    return 0;
}
/* merge_units: end func_002DD4E8 */

/* merge_units: begin func_002DD5B8 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { unsigned char b0, b1; char x2[6]; char x8[0x40]; } M2DD5B8;
typedef struct { int slot; int id; int q; int x14; int zero; int x42C; } S2DD5B8;
extern int D_00598414;
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, void **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((a0), (char * *)(a1))) /* merge_units */

extern int NetCreateClientInfo(unsigned int, unsigned int, void **);
#if 0 /* merge_units */
extern int NetGetClientInfo(unsigned int, unsigned int, void **);
#endif /* merge_units */
#define NetGetClientInfo(a0, a1, a2) (NetGetClientInfo((a0), (a1), (unsigned char * *)(a2))) /* merge_units */

extern void SendMyClientStatus(unsigned int, int);
extern int NetStreamMediaIsEnabledOnConnection(unsigned int);
extern int NetStreamMediaRemoteClientConnects(unsigned int, unsigned int);
extern unsigned char NetClientIndexToClientIndexPacket(unsigned int);
extern void NetIIpStringToBinary(char *, void *);
extern int KM_GetLocalPublicKey(int, char *);
extern void NetSendDmeMessage(int, unsigned int, int, int, int, M2DD5B8 *);
extern void NetIGetSessionMasterClientIndex(int *, unsigned int);
extern void NetGetClientPingInfo(unsigned int, void **);
extern void rt_time_get_time_stamp(char *);
void RemoteClientConnects(unsigned int slot, unsigned int id, char *name, unsigned short port)
{
    void *x7C;
    int x78 = 0x100;
    void *p = 0;
    void *q = 0;
    M2DD5B8 m;
    S2DD5B8 st;
    if (id >= 0x100) return;
    if (slot >= 4) return;
    if (NetGetConnInfo(slot, &p) != 0) return;
    if (p == 0) return;
    if (NetCreateClientInfo(slot, id, &q) != 0) return;
    if (q == 0) return;
    if (F(q, unsigned char, 0x28) == 1) {
        if (F(p, int, 0x44C) == 4) return;
        SendMyClientStatus(slot, id);
        return;
    }
    if (F(p, int, 0x440) != 0) F(p, int, 0x440)--;
    strncpy((char *)q, name, 0x10);
    F(q, unsigned short, 0x10) = port;
    F(q, unsigned char, 0x28) = 1;
    if (NetGetClientInfo(slot, F(p, int, 0x400), &q) != 0) return;
    if (q == 0) return;
    if (F(q, unsigned char, 0x28) != 0) {
        if (NetStreamMediaIsEnabledOnConnection(slot) == 1) {
            if (NetStreamMediaRemoteClientConnects(slot, id) != 0) return;
        }
        if (F(p, int, 0x44C) == 4) {
            if (NetGetClientInfo(slot, id, &q) != 0) return;
            if (q == 0) return;
            F(q, int, 0x14) = 2;
            F(q, int, 0x18) = 0;
            F(q, int, 0x1C) = 0;
            F(q, int, 0x24) = 0;
            memset(&st, 0, 0x18);
            st.slot = slot;
            st.id = id;
            st.q = (int)q;
            st.x14 = (int)F(q, void *, 0x14);
            st.zero = 0;
            st.x42C = (int)F(p, void *, 0x42C);
            ((void (*)(S2DD5B8 *))F(p, int, 0x428))(&st);
            F(q, unsigned char, 0x2A) = 1;
        }
    }
    if (F(p, int, 0x438) != 1) return;
    if (F(p, int, 0x44C) == 4) return;
    m.b1 = NetClientIndexToClientIndexPacket(F(p, int, 0x400));
    if (NetGetClientInfo(slot, m.b1, &q) != 0) return;
    if (q == 0) return;
    NetIIpStringToBinary(m.x2, q);
    m.b0 = slot;
    KM_GetLocalPublicKey(0, m.x8);
    NetSendDmeMessage(0x50, slot, id, D_00598414, 0x48, &m);
    SendMyClientStatus(slot, id);
    NetIGetSessionMasterClientIndex(&x78, slot);
    if (slot != 0) return;
    if (F(p, int, 0x400) != x78) return;
    x7C = 0;
    NetGetClientPingInfo(id, &x7C);
    if (x7C == 0) return;
    rt_time_get_time_stamp((char *)x7C + 0x198);
}
#undef NetGetConnInfo /* merge_units */
#undef NetGetClientInfo /* merge_units */
/* merge_units: end func_002DD5B8 */

/* merge_units: begin func_002DD8A8 */
#if 0 /* merge_units */
extern int NetGetClientInfo(unsigned int, unsigned int, char **);
#endif /* merge_units */
#define NetGetClientInfo(a0, a1, a2) (NetGetClientInfo((a0), (a1), (unsigned char * *)(a2))) /* merge_units */

void RemoteClientDisconnects(unsigned int a, unsigned int b)
{
    char *p = 0;
    char *q = 0;
    if (a >= 4) return;
    if (b >= 0x100) return;
    if (NetGetConnInfo(a, &p)) return;
    if (p == 0) return;
    if (NetGetClientInfo(a, b, &q)) return;
    if (q) memset(q, 0, 0x2C);
}
#undef NetGetClientInfo /* merge_units */
/* merge_units: end func_002DD8A8 */
