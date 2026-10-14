/*
 * lib/libnet: 6 files, 0034BE80-0034C3D8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034BE80 */
typedef struct { int type; int f4; int id; int mode; } NetIf_E80;
typedef struct { int f0; int f4; int f8[6]; int f20; } NetCfg_E80;
extern int Net_AllocZeroed(NetIf_E80 **pp, int size);
extern int func_0034CF80(NetIf_E80 *o);
extern int func_002FB3C0(NetIf_E80 **pp);
extern int func_0034ACC8(void *cd, int *buf, void *src);
extern int func_0034D028(NetIf_E80 *o);
int func_0034BE80(void *cd, int *buf, NetIf_E80 **out, NetCfg_E80 *cfg)
{
    NetIf_E80 *o;
    int r;
    if (out == 0 || cfg == 0) return -0x200;
    *out = 0;
    o = 0;
    if (Net_AllocZeroed(&o, 0x28) != 0 || o == 0) return -0x1F5;
    o->type = cfg->f8[0];
    o->f4 = cfg->f20;
    if (o->type == 0) o->mode = cfg->f0;
    else if (o->type == 3) o->mode = 4;
    else o->mode = 0;
    if (func_0034CF80(o) != 0) {
        func_002FB3C0(&o);
        return -0x1F5;
    }
    r = func_0034ACC8(cd, buf, cfg->f8);
    if (r < 0) {
        func_0034D028(o);
        func_002FB3C0(&o);
        return r;
    }
    o->id = r;
    *out = o;
    return 0;
}
/* merge_units: end func_0034BE80 */

/* merge_units: begin func_0034BFA8 */
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
/* merge_units: end func_0034BFA8 */

/* merge_units: begin func_0034C168 */
typedef struct { int a; int b; int id; } NetObj_168;
extern int sceSifMCallRpc(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *edata);
#if 0 /* merge_units */
extern int func_0034D028(NetObj_168 *p);
#endif /* merge_units */
#define func_0034D028(a0) (func_0034D028((NetIf_E80 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_002FB3C0(NetObj_168 **pp);
#endif /* merge_units */
#define func_002FB3C0(a0) (func_002FB3C0((NetIf_E80 * *)(a0))) /* merge_units */

int func_0034C168(void *cd, int *buf, NetObj_168 *p, int x)
{
    NetObj_168 *q;
    int r;
    if (p == 0) return -0x200;
    buf[0] = p->id;
    buf[1] = x;
    q = p;
    r = sceSifMCallRpc(cd, 0x66, 0, buf, 16, buf, 16, 0, 0);
    if (func_0034D028(q) != 0 || func_002FB3C0(&q) != 0) return -0x1F5;
    return r < 0 ? -0x1F5 : 0;
}
#undef func_0034D028 /* merge_units */
#undef func_002FB3C0 /* merge_units */
/* merge_units: end func_0034C168 */

/* merge_units: begin func_0034C200 */
typedef struct { void *a; void *b; int n; int z; } NetReq_200;
typedef struct { int avail; int f4; int f8; int fC; char pad[0xC]; char *base; void *f20; int pos; } NetCtx_200;
typedef struct { char pad[0x20]; NetCtx_200 *ctx; } NetObj_200;
extern void FlushCache(int a);
extern int sceSifSetDma(NetReq_200 *req, int n);
extern int sceSifDmaStat(int h);
extern void printf(const char *s);
extern void *memcpy(void *d, const void *s, unsigned int n);
extern int func_0034C8E0(NetObj_200 *o, int *out);
int func_0034C200(void *cd, int *buf, NetObj_200 *o, void *dst, int len, int *out)
{
    NetCtx_200 *c;
    NetReq_200 req;
    int l = 0;
    int r;
    int n;
    int h;
    if (o == 0) return -0x200;
    c = o->ctx;
    FlushCache(0);
    if (c->fC != 0) {
        r = func_0034C8E0(o, &l);
        if (r != 0) return r;
        if (l == 0) return 0;
    }
    *out = c->f4;
    if (c->avail <= 0) return c->avail;
    n = len;
    if (c->avail < n) n = c->avail;
    memcpy(dst, c->base + c->pos, n);
    c->avail -= n;
    if (c->avail != 0) {
        c->pos += n;
    } else {
        c->pos = 0;
        FlushCache(0);
        req.b = c->f20; req.a = c; req.n = 4; req.z = 0;
        h = sceSifSetDma(&req, 1);
        if (h == 0) printf("Error DMAing data to IOP memory!!!
");
        while (sceSifDmaStat(h) >= 0) ;
    }
    return n;
}
/* merge_units: end func_0034C200 */

/* merge_units: begin func_0034C348 */
extern int func_0034CA38(int a, int b, int c, int d, int e, int g, int *out, int *err);
int func_0034C348(void *cd, void *buf, int a, int b, int c, int d, int e, int g, int h)
{
    int out;
    int err = -0x1F5;
    if (cd == 0 || h < -1 || buf == 0) return -0x1F5;
    if (c == 0) return 0;
    if (func_0034CA38(a, b, c, d, e, g, &out, &err) == 0) return out;
    return err ? err : -0x1F5;
}
/* merge_units: end func_0034C348 */

/* merge_units: begin func_0034C3D8 */
extern int func_0034CC60(int a, int b, int c, int *out, int *err);
int func_0034C3D8(void *cd, void *buf, int a, int b, int c)
{
    int out = 0;
    int err = -0x1F5;
    if (cd == 0) return -0x1F5;
    if (func_0034CC60(a, b, c, &out, &err) == 0) return out;
    return err ? err : -0x1F5;
}
/* merge_units: end func_0034C3D8 */
