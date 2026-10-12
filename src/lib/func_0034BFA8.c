typedef struct NetCtx_FA8 { int f0; int f4; int f8; int state; int f10; int f14; int f18; char *f1C; struct NetCtx_FA8 *f20; char pad[0x10]; int f34; int f38; } NetCtx_FA8;
typedef struct { int f0; int f4; int f8; int fC; char pad[0x10]; NetCtx_FA8 *tx; NetCtx_FA8 *rx; } NetObj_FA8;
extern int func_0034D080(void *cd, NetCtx_FA8 *c);
extern int func_0034D128(void *cd, NetCtx_FA8 *c);
extern int func_0034AD40(void *cd, int *buf, int a, int b);
extern int func_0034C9A0(void *a, void *b, int n);
static __inline__ void ctx_init(NetCtx_FA8 *c, NetObj_FA8 *o, int mode)
{
    c->state = mode;
    c->f1C = (char *)c + 0x40;
    c->f34 = o->f0;
    c->f38 = o->f4;
    c->f10 = o->f8;
    c->f8 = o->fC;
    c->f14 = 0;
    c->f18 = 0x2000;
}
int func_0034BFA8(void *cd, int *buf, NetObj_FA8 *o, int flag)
{
    NetCtx_FA8 *c;
    int skip = 0;
    int mode;
    int r;
    if (o == 0) return -0x200;
    if (flag == 0) skip = (o->f0 == 1);
    if (skip == 1) mode = 2; else mode = 1;
    c = o->tx;
    c->state = mode;
    c->f1C = (char *)c + 0x40;
    c->f34 = o->f0;
    c->f38 = o->f4;
    c->f10 = o->f8;
    c->f8 = o->fC;
    c->f14 = 0;
    c->f18 = 0x2000;
    if (func_0034D080(cd, o->tx) != 0) return -0x1F5;
    ctx_init(o->rx, o, mode);
    if (func_0034D128(cd, o->rx) != 0) return -0x1F5;
    if (!skip) {
        r = func_0034AD40(cd, buf, o->f8, flag);
        if (r == 0 || (r == -0x1F4 && o->f0 == 2)) {
            o->rx->state = 0;
            o->tx->state = 0;
        } else {
            o->rx->state = 3;
            o->tx->state = 3;
        }
        if (func_0034C9A0(o->rx, o->rx->f20, 16) != 0) return -0x1F5;
        if (func_0034C9A0(o->tx, o->tx->f20, 16) != 0) return -0x1F5;
    } else r = 0;
    return r;
}
