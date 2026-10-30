typedef struct {
    unsigned char type;
    unsigned char cli;
    unsigned char b2;
    unsigned char b3;
    unsigned short h4;
    char pad6[2];
    int f8;
    int fC;
} Pkt;
typedef struct {
    char pad0[0x14];
    int f14;
    int f18;
    int f1C;
    short f20;
    char pad22[2];
    int f24;
    unsigned char f28;
    char pad29;
    unsigned char f2A;
} Cl;
typedef struct {
    int f0;
    int f4;
    Cl *f8;
    int fC;
    void *f10;
    void *f14;
} Ev;
typedef struct {
    char pad0[0x400];
    unsigned int x400;
    char pad404[0x24];
    Cl *x428; /* callback; typed like Ev.f8 so its load aliases the ev.f8 store (keeps cl live -> t0) */
    void *x42C;
} Ctx;
typedef struct { char a; char b; char c; char d; } Msg;
extern int D_005983E4;
extern int NetGetConnInfo(unsigned int, Ctx **);
extern int NetGetClientInfo(unsigned int, unsigned int, Cl **);
extern void NetSetSessionMasterClientIndex(unsigned int, unsigned int, int, Cl *);
extern char NetClientIndexToClientIndexPacket(unsigned int);
extern void NetSendDmeMessage(int, unsigned int, unsigned int, int, int, Msg *);
extern void ElectSessionMaster(unsigned int, unsigned int, unsigned int, unsigned int);
extern void AcceptClientIntoGame(unsigned int, unsigned int, unsigned int, unsigned int);
extern void *memset(void *, int, unsigned int);

int UpdateClientStatusPacketHandler(unsigned int idx, int a1, unsigned int len, Pkt *p)
{
    Ev ev;
    Msg msg;
    Ctx *ctx = 0;
    Cl *cl = 0;
    Cl *me = 0;
    unsigned char st;
    int t;

    if (p == 0) return -1;
    if (idx >= 4) return 0x10;
    if (len >= 0x100) return 0x10;
    if (NetGetConnInfo(idx, &ctx) != 0) return -1;
    if (ctx == 0) goto fail;
    if (NetGetClientInfo(idx, p->cli, &cl) != 0) return -1;
    if (cl == 0) {
    fail:
        return -1;
    }
    st = cl->f28;
    if (st != 1) return 0x10;
    if (ctx->x400 >= 0x100) return 0x10;
    if (NetGetClientInfo(idx, ctx->x400, &me) != 0) return 0x10;
    {
        Cl *c = cl;
        if (c == 0) return 0x10;
        t = p->type;
        c->f14 = t;
        c->f18 = p->b2;
        c->f1C = p->b3;
        c->f20 = p->h4;
        if (t == 5) NetSetSessionMasterClientIndex(idx, p->cli, 5, c);
    }
    if (ctx->x428 != 0 && cl->f2A == 0) {
        memset(&ev, 0, sizeof ev);
        {
        Cl *c = cl;
        Ctx *x = ctx;
        int (*fn)(Ev *) = (int (*)(Ev *))x->x428; /* int return: call sets v0, sched2 order */
        int ci = p->cli;
        void *pf = (void *)p->fC;
        int fv = c->f14;
        void *xk = x->x42C;
        ev.f4 = ci;
        ev.fC = fv;
        ev.f14 = xk;
        ev.f10 = pf;
        ev.f0 = idx;
        ev.f8 = c;
        fn(&ev);
        }
        cl->f2A = st;
        if (me->f14 == 3) {
            Ctx *y = ctx;
            cl->f14 = 0;
            msg.a = 3;
            msg.b = NetClientIndexToClientIndexPacket(y->x400);
            msg.c = me->f18;
            msg.d = me->f1C;
            NetSendDmeMessage(0x50, idx, p->cli, D_005983E4, 4, &msg);
            return 0x10;
        }
    }
    {
    Cl *m = me;
    if (p->f8 != 0) cl->f24 = p->f8;
    switch (m->f14) {
    case 0:
    case 1:
    case 2:
    case 4:
        break;
    case 3:
        ElectSessionMaster(idx, p->cli, p->b2, p->b3);
        break;
    case 5:
        if (p->type == 3) AcceptClientIntoGame(idx, p->cli, p->b2, p->b3);
        break;
    }
    }
    return 0x10;
}