/* best 002E0760: 7 diffs (sched/reg-alloc of 0x100 const + global luis at 0xd0-0xf8, DD268 arg-load order at 0x14c/0x154, trailing pad nop) */
typedef struct { char c[0x40]; } B40;
typedef struct Info_ Info;
typedef struct {
    int f0; int f4; char pad8[0x38]; B40 blk; char pad80[0x24];
    void (*fA4)(Info *); int fA8; int fAC; int fB0; int fB4; int fB8; int fBC; int fC0; int fC4; int fC8;
    int fCC; int fD0; char padD4[0x4C]; int f120;
} Cfg;
typedef struct { int type; char addr[0x10]; unsigned short port; } LEnt;
enum NE { NE0, NE1, NE2 }; typedef struct { enum NE n; LEnt e[2]; } List;
typedef struct { int f0; int f4; int f8; } Res;
typedef struct {
    char pad0[0x400]; int x400; char pad404[0x24]; int x428; int x42C; int x430; int x434;
    int x438; int x43C; int x440; int x444; int x448; int x44C;
} Ctx;
struct Info_ { int port; int state; int arg; int err; int user; };
typedef struct { char pad[0x40]; char a[16]; char b[16]; unsigned short pa; unsigned short pb; } UpnpInfo;
extern void (*D_0048C468)(Info *);
extern int D_0048C46C;
extern int D_0048C470;
extern int D_0048C474;
extern unsigned char D_0048C4AC;
extern int D_0048C4B0;
extern unsigned short D_0058C0B0;
extern int NetCreateConnInfo(unsigned int, Ctx **);
extern int NetSetSessionMasterClientIndex(unsigned int, int);
extern int NetSetPeerToPeerHostChangeCallback(int, int);
int __attribute__((weak, section(".dtors_drop"))) NetIEnableUDP(void) { return 0; }
extern int rt_p2p_set_max_peers(int, int);
extern int NetStreamMediaEnableOnConnection(int, int, int *);
extern int NetStreamMediaDisableOnConnection(int);
extern void *memset(void *, int, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern int rt_p2p_connect(int, UpnpInfo *, void *);
extern void p2p_connect_cb(void);
extern int NetIGetLocalTime(unsigned int *);
extern int NetIUpdate(void);

int NetConnect_PeerToPeerUDP(Cfg *cfg, List *list, Res *res)
{
    UpnpInfo info;
    Info cb;
    Ctx *ctx;
    unsigned int t;
    int r;
    unsigned int i;
    unsigned int deadline;
    int ver;
    int r0;
    int n, fa, f4, ta, tb;
    Ctx *c;

    ctx = 0;
    if (res == 0) return 0x17;
    res->f4 = 3;
    res->f0 = 1;
    if (cfg == 0 || list == 0) {
        res->f4 = 0x17;
        return 0x17;
    }
    ver = cfg->f0;
    if (ver != 1) {
        res->f4 = 0x26;
        return 0x26;
    }
    if (cfg->f4 <= 0 || list->n != 2) {
        res->f4 = 0x17;
        return 0x17;
    }
    r0 = NetCreateConnInfo(0, &ctx);
    res->f4 = r0;
    if (r0 != 0) return r0;
    if (ctx == 0) return r0;
    NetSetSessionMasterClientIndex(0, 0x100);
    c = ctx;
    c->x43C = ver;
    f4 = cfg->f4;
    c->x400 = 0x100;
    c->x444 = f4;
    c->x44C = list->n;
    c->x448 = cfg->f120;
    D_0048C468 = cfg->fA4;
    D_0048C46C = cfg->fA8;
    D_0048C470 = cfg->fAC;
    D_0048C474 = cfg->fB0;
    res->f8 = 0;
    ta = cfg->fB8;
    tb = cfg->fB4;
    c->x42C = ta;
    c->x428 = tb;
    ta = cfg->fC0;
    tb = cfg->fBC;
    c->x434 = ta;
    c->x430 = tb;
    {
        int y = cfg->fC8;
        /* scheduling barrier (emits no code): loads fC8 before fC4 */
        __asm__ volatile("" ::: "memory");
        r = NetSetPeerToPeerHostChangeCallback(cfg->fC4, y);
    }
    if (r == 0 && D_0048C4AC == 0) r = NetIEnableUDP();
    if (rt_p2p_set_max_peers(D_0048C4B0, ctx->x444) != 0) return 0x25;
    if (r == 0 && cfg->fD0 == 1) r = NetStreamMediaEnableOnConnection(0, cfg->f4, &cfg->fCC);
    if (r != 0) {
        NetStreamMediaDisableOnConnection(0);
        ctx->x438 = 3;
        if (D_0048C468 != 0) {
            memset(&cb, 0, sizeof cb);
            cb.arg = 1;
            cb.port = 0;
            cb.state = 3;
            cb.err = 3;
            cb.user = D_0048C46C;
            D_0048C468(&cb);
        }
        res->f4 = r;
        if (r != 0) return r;
    }
    ctx->x438 = 2;
    memset(&info, 0, sizeof info);
    *(B40 *)&info = cfg->blk;
    for (i = 0; i < 2; i++) {
        if (list->e[i].type == 2) {
            strncpy(info.a, list->e[i].addr, 0x10);
            info.pa = list->e[i].port;
        }
        if (list->e[i].type == 1) {
            strncpy(info.b, list->e[i].addr, 0x10);
            info.pb = list->e[i].port;
        }
    }
    if (info.pa == 0) info.pa = D_0058C0B0;
    if (info.pb == 0) info.pb = D_0058C0B0;
    if (rt_p2p_connect(D_0048C4B0, &info, p2p_connect_cb) != 0) return 0x25;
    if (cfg->fA4 != 0) goto ok;
    NetIGetLocalTime(&t);
    deadline = t + 30000;
    while (ctx->x438 == 2) {
        NetIGetLocalTime(&t);
        if (deadline < t) {
            res->f4 = 0xE;
            ctx->x438 = 0;
            return 0xE;
        }
        NetIUpdate();
    }
    if (ctx->x400 == 0x100 || ctx->x438 == 3) {
        res->f4 = 3;
        return 3;
    }
ok:
    res->f4 = 0;
    return 0;
}



