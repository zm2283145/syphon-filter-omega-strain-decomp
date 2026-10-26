/*
 * lib/medius: 2 files, 002E7118-002E7328
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E7118 */
typedef void (*Cb2E7118)(int, void *, int, int, int, int);
typedef struct {
    int f0;
    unsigned short f4;
    int f8;
    Cb2E7118 fC;
    int f10;
    int f14;
    int f18;
} E2E7118;
typedef struct { int f0; unsigned char b4; unsigned char b5; } P2E7118;
typedef struct { int w0; unsigned char b4; unsigned char b5; char pad[10]; } M2E7118;
extern E2E7118 D_0058D188[];
extern unsigned short D_0058D178;
extern char D_005880A0[];
extern unsigned int D_005983DC;
extern int NetGetClientInfo(unsigned int, int, void **);
extern int NetIGetTime(void *);
extern int NetIGetLocalTime(int *);
extern int Net_IpToString(void *, void *);
extern int Net_SendTyped(signed char, int, int, int, unsigned int, int, void *);
int PingPacketHandler(unsigned int slot, int unused, int id, P2E7118 *p)
{
    M2E7118 m;
    char buf[16];
    void *q;
    int t;
    int dt;
    Cb2E7118 cb;
    if (p == 0) return -1;
    if ((signed char)p->b5 != 0) {
        if (slot >= 4) goto done;
        if (id == 0x100) goto done;
        q = 0;
        if (NetGetClientInfo(slot, id, &q) != 0) goto done;
        if (q == 0) goto done;
        if (*(unsigned char *)((char *)q + 0x28) != 1) goto done;
        NetIGetTime(&m);
        m.b4 = p->b4;
        m.b5 = 0;
        Net_SendTyped(-0x80, slot, id, 0, D_005983DC, 8, &m);
        goto done;
    }
    NetIGetLocalTime(&t);
    cb = D_0058D188[p->b4].fC;
    if (cb == 0) goto done;
    NetIGetLocalTime(&t);
    dt = t - D_0058D188[p->b4].f10;
    Net_IpToString(buf, &D_0058D188[p->b4]);
    Net_IpToString(D_005880A0, &D_0058D188[p->b4]);
    D_0058D178 = D_0058D188[p->b4].f4;
    if (D_0058D188[p->b4].f8 == 1)
        cb(0, buf, dt, p->f0, D_0058D188[p->b4].f14, D_0058D188[p->b4].f18);
    else
        ((void (*)(int, void *, int))cb)(0, buf, dt);
    D_0058D188[p->b4].fC = 0;
done:
    return 8;
}
/* merge_units: end func_002E7118 */

/* merge_units: begin func_002E7328 */
typedef struct { int busy; unsigned int n; int a; int len; char p[0x10]; int tm; unsigned char *map; char *data; } T2E7328;
typedef struct { unsigned char type, sub; unsigned short len; unsigned short x; unsigned short idx; char p[8]; int off; char payload[4]; } H2E7328;
extern int NetFindMultiPacket(int, int, H2E7328 *, T2E7328 **);
extern void *memcpy(void *, const void *, unsigned int);
extern void rt_time_get_local(int *);
extern void NetMsg_GetCallback(unsigned char, unsigned char, void (**)(int, int, int, char *));
extern void DmeFree(void *);
int PacketFragmentPacketHandler(int a, int b, int c, H2E7328 *h)
{
    T2E7328 *t = 0;
    void (*cb)(int, int, int, char *);
    int done = 1;
    unsigned int i;
    if (h == 0) return -1;
    if (NetFindMultiPacket(a, c, h, &t) != 0) return h->len + 0x14;
    if (t == 0) return h->len + 0x14;
    memcpy(t->data + h->off, h->payload, h->len);
    t->len += h->len;
    rt_time_get_local(&t->tm);
    t->map[h->idx] = 1;
    for (i = 0; i < t->n; i++) {
        if (t->map[i] == 0) {
            done = 0;
            break;
        }
    }
    if (done) {
        cb = 0;
        NetMsg_GetCallback(h->type, h->sub, &cb);
        if (cb) cb(a, b, c, t->data);
        if (t->data) {
            DmeFree(&t->data);
            t->data = 0;
        }
        if (t->map) {
            DmeFree(&t->map);
            t->map = 0;
        }
        t->busy = 0;
    }
    return h->len + 0x14;
}
/* merge_units: end func_002E7328 */
