typedef struct { int port; int state; int arg; int err; int user; } Info;
typedef struct {
    int f0; void (*f4)(Info *); int f8; char * fC; void * f10; char * f14; void * f18; int f1C; int f20; int f24;
    char pad28[0x4C]; int f74;
} Cfg;
typedef struct { int f0; int f4; int f8; } Res;
typedef struct {
    char pad0[0x400]; int x400; char pad404[0x24]; char * x428; void * x42C; char * x430; void * x434;
    int x438; int x43C; int x440; int x444; int x448; int x44C;
} Ctx;
extern void (*D_0048C468)(Info *);
extern int D_0048C46C;
extern unsigned char D_0048C4AC;
extern int D_0048C4B0;
extern int DisconnectFailedConnections(void);
extern int NetCreateConnInfo(int, Ctx **);
extern int NetCreateClientInfo(int, int, int *);
extern int NetSetSessionMasterClientIndex(int, int);
/* pure: gives the call a REG_EH_REGION nothrow note so reorg's liveness scan
   continues past it, letting the bnez delay slot be non-annulled (retail). */
extern int NetIEnableUDP(void) __attribute__((pure));
extern int rt_p2p_set_max_peers(int, int);
extern int NetStreamMediaEnableOnConnection(int, int, int *);
extern int NetStreamMediaDisableOnConnection(int);
extern int rt_p2p_host(int, int *);
extern void MyClientConnectsPeerToPeer(int, int, int, int, int);
extern void *memset(void *, int, unsigned int);

int NetIHostPeerToPeer(Cfg *cfg, Res *res)
{
    Info cb;
    Ctx *ctx;
    int conn;
    int r;
    int e;
    int ver;
    int one;

    r = 0;
    ctx = 0;
    conn = 0;
    if (res == 0) return 0x17;
    res->f4 = 0x1D;
    res->f0 = 1;
    e = DisconnectFailedConnections();
    if (e != 0) return e;
    one = 1;
    if (cfg == 0) goto bad;
    if (cfg->f0 != one) {
        res->f4 = 0x26;
        return 0x26;
    }
    if (cfg->f1C == 0) {
    bad:
        res->f4 = 0x17;
        return 0x17;
    }
    e = NetCreateConnInfo(0, &ctx);
    res->f4 = e;
    if (e != 0) return e;
    if (ctx == 0) return e;
    e = NetCreateClientInfo(0, 0, &conn);
    res->f4 = e;
    if (e != 0) return e;
    if (conn == 0) return e;
    NetSetSessionMasterClientIndex(0, 0x100);
    ctx->x43C = one;
    ctx->x444 = cfg->f1C;
    ctx->x448 = cfg->f74;
    D_0048C468 = cfg->f4;
    D_0048C46C = cfg->f8;
    res->f8 = 0;
    ctx->x428 = cfg->fC;
    ctx->x42C = cfg->f10;
    ctx->x430 = cfg->f14;
    ctx->x434 = cfg->f18;
    ctx->x438 = 2;
    ctx->x400 = 0x100;
    if (D_0048C4AC == 0) r = NetIEnableUDP();
    if (rt_p2p_set_max_peers(D_0048C4B0, ctx->x444) != 0) return 0x25;
    if (r == 0 && cfg->f24 == 1) r = NetStreamMediaEnableOnConnection(0, cfg->f1C, &cfg->f20);
    if (r != 0) {
        NetStreamMediaDisableOnConnection(0);
        ctx->x438 = 3;
        if (D_0048C468 != 0) {
            memset(&cb, 0, sizeof cb);
            cb.state = 3;
            cb.arg = 1;
            cb.port = 0;
            cb.err = r;
            cb.user = D_0048C46C;
            D_0048C468(&cb);
        }
        res->f4 = r;
        if (r != 0) return r;
    }
    if (rt_p2p_host(D_0048C4B0, &ctx->x400) == 0) {
        MyClientConnectsPeerToPeer(0, ctx->x400, one, one, 0);
        res->f4 = 0;
    } else {
        MyClientConnectsPeerToPeer(0, 0x100, 0, 0, 1);
        res->f4 = 3;
    }
    return res->f4;
}