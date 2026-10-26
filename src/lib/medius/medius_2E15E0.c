typedef struct { char pad[0x400]; unsigned int f400; char pad2[0x34]; int f438; char pad3[4]; int f440; int f444; char pad4[4]; int f44C; } S;
typedef enum { ST0, ST1, ST2, ST3, ST4, ST5 } State;
typedef struct { char pad[0x14]; State f14; int f18; int f1C; char pad2[4]; int f24; unsigned char f28; } P;
typedef struct { char pad[6]; short f6; short f8; short fA; short fC; char name[0xB]; char f19; } E;
typedef struct { int f0; unsigned int f4; char name[0xC]; unsigned int f14; unsigned int f18; int f1C; int f20; int f24; int f28; int f2C; int f30; int f34; } R;
extern int D_0058DF88;
extern int D_0048C478;
extern int D_0058DF8C;
extern int D_0048C47C;
extern int D_0048C488;
extern int D_0048C48C;
extern int D_0048C464;
extern unsigned int D_0048C450;
extern int D_0048C45C;
extern int D_0058DF90;
extern unsigned int D_005983E4;
extern char D_0048C454;
extern unsigned char D_0048C440;
extern int NetIsValidConnectionIndex(unsigned int);
extern int NetGetConnInfo(unsigned int, S **);
extern E *NetCreateClient(unsigned int, unsigned int);
extern int NetGetClientInfo(unsigned int, unsigned int, P **);
extern char *strncpy(char *, const char *, unsigned int);
extern unsigned char NetClientIndexToClientIndexPacket(unsigned int);
extern void NetSendDmeMessage(int, unsigned int, unsigned int, unsigned int, int, void *);
extern int NetSetSessionMasterClientIndex(unsigned int, unsigned int);
extern void MyClientJoins(unsigned int, unsigned int);
extern int NetISetMyClientReceiveBroadcast(unsigned int, int);
/* weak never-linked stub (discarded section): callee was defined in this TU in the original */
void __attribute__((weak, section(".dtors_drop"))) NetIGetLocalTime(unsigned int *p) { }
extern int NetIUpdate(void);
extern void SendMyClientStatus(unsigned int, int);
extern int NetILeave(unsigned int);

int NetJoin2(R *r)
{
    unsigned char b[4];
    S *s;
    P *p;
    P *q;
    P *q2;
    unsigned int t0;
    unsigned int t1;
    E *e;
    unsigned int n;
    int i;
    int cnt;
    int ret;

    s = 0;
    p = 0;
    if (r == 0) return 0x17;
    if (r->f0 != 1) return 0x26;
    if (NetIsValidConnectionIndex(r->f4) != 1) return 0x17;
    if (r->f14 > 0x1000) return 0x17;
    if (r->f18 > 0x800) return 0x17;
    { int r1 = NetGetConnInfo(r->f4, &s);
    if (r1 != 0) return r1;
    if (s == 0) return r1; }
    if (s->f44C == 4) return 0xF;
    if (s->f438 != 1) return 0x17;
    D_0058DF88 = r->f20;
    D_0048C478 = r->f24;
    D_0058DF8C = r->f28;
    D_0048C47C = r->f2C;
    D_0048C488 = r->f30;
    D_0048C48C = r->f34;
    D_0048C464 = 0;
    D_0048C450 = r->f4;
    D_0058DF90 = r->f1C;
    D_0048C45C = 0;
    e = NetCreateClient(r->f4, s->f400);
    if (e == 0) return 0x16;
    n = s->f400;
    if (n >= 0x100) return 8;
    ret = NetGetClientInfo(r->f4, n, &p);
    if (ret != 0) return ret;
    if (p == 0) return ret;
    p->f14 = 3;
    for (i = 0; i < s->f444; i++) {
        int e2 = NetGetClientInfo(r->f4, i, &p);
        if (e2 != 0) return e2;
        if (p != 0 && p->f28 == 1 && i != n) p->f14 = 0;
    }
    e->f6 = 0x1000;
    e->f8 = r->f14;
    e->fA = 0x800;
    e->fC = r->f18;
    strncpy(e->name, r->name, 0xB);
    e->f19 = 0;
    ret = NetGetClientInfo(r->f4, n, &p);
    if (ret != 0) return ret;
    q = p;
    if (q == 0) return 0;
    i = 0;
    cnt = 0;
    q->f18 = r->f14;
    q->f1C = r->f18;
    b[0] = 3;
    b[1] = NetClientIndexToClientIndexPacket(s->f400);
    b[2] = r->f14;
    b[3] = r->f18;
    for (; i < s->f444; i++) {
        int e2 = NetGetClientInfo(r->f4, i, &p);
        if (e2 != 0) return e2;
        if (p != 0 && p->f28 == 1 && i != n) {
            cnt++;
            NetSendDmeMessage(0x50, r->f4, i, D_005983E4, 4, b);
        }
    }
    ret = NetGetClientInfo(r->f4, n, &p);
    if (ret != 0) return ret;
    q2 = p;
    if (q2 == 0) return 0;
    if (cnt == 0 && s->f440 == 0) {
        q2->f24 = 1;
        q2->f14 = 5;
        { int r3 = NetSetSessionMasterClientIndex(r->f4, n);
        if (r3 != 0) return r3; }
        e->f6 = 0;
        e->fA = 0;
        D_0048C454 = 1;
        MyClientJoins(r->f4, n);
        NetISetMyClientReceiveBroadcast(r->f4, 1);
    }
    if (D_0058DF88 == 0) {
        NetIGetLocalTime(&t0);
        t0 += 30000;
        while (D_0048C440 == 0) {
            NetIUpdate();
            NetIGetLocalTime(&t1);
            if (t1 > t0) goto timeout;
        }
        return D_0048C440 ? 0 : 7;
timeout:
        p->f14 = 2;
        SendMyClientStatus(r->f4, -1);

        NetILeave(r->f4);
        return 0xE;
    }
    return 0;
}
