/*
 * lib/libnet: 3 files, 0034C9A0-0034CC60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034C9A0 */
typedef struct { void *a; void *b; int n; int z; } NetReq_9A0;
extern void FlushCache(int a);
extern int sceSifSetDma(NetReq_9A0 *req, int n);
extern int sceSifDmaStat(int h);
int func_0034C9A0(void *a, void *b, int n)
{
    NetReq_9A0 req;
    int h;
    int ret = 2;
    if (a == 0) return ret;
    if (b == 0) return ret;
    if (n == 0) return ret;
    FlushCache(0);
    req.a = a; req.b = b; req.n = n; req.z = 0;
    h = sceSifSetDma(&req, 1);
    ret = 4;
    if (h == 0) return ret;
    while (sceSifDmaStat(h) >= 0) ;
    return 0;
}
/* merge_units: end func_0034C9A0 */

/* merge_units: begin func_0034CA38 */
typedef struct Name16 {
    int d[4];
} Name16;
typedef struct Blk {
    int used;
    int f4;
    int size;
    unsigned int fC;
    Name16 name;
    int f20;
    int f24;
    int f28;
    int remote;
    char pad30[0x3C - 0x30];
    int f3C;
} Blk;
typedef struct Ctx {
    char pad0[0x18];
    int total;
    char *base;
    char pad20[0x3C - 0x20];
    int cur;
} Ctx;
typedef struct Obj {
    char pad0[0x20];
    Ctx *ctx;
} Obj;
extern int func_0034A360(Ctx *p, unsigned char a, unsigned char b, unsigned char *out);
extern int func_0034C9A0(void *a, void *b, int n);
extern void *memcpy(void *d, const void *s, unsigned int n);

int func_0034CA38(Obj *o, void *dst, int size, int *p3, Name16 *p4, int *p5, int *p6, int *p7)
{
    unsigned char ready;
    Ctx *c;
    Blk *b;
    unsigned int n;
    int more;
    int ret;
    int r;

    ret = 2;
    ready = 0;
    if (p6 != 0) {
        *p6 = 0;
        if (dst != 0 && size > 0 && p3 != 0) {
            *p3 = 0;
            if (p4 != 0 && p5 != 0 && p7 != 0) {
                *p7 = 0;
                if (o != 0) {
                    c = o->ctx;
                    if (c != 0) {
                        FlushCache(0);
                        r = func_0034A360(c, 1, 0, &ready);
                        if (r != 0)
                            return r;
                        if (ready == 0) {
                            *p6 = 0;
                            *p3 = 0;
                            *p7 = 0;
                            return r;
                        }
                        b = (Blk *)(c->base + c->cur);
                        more = b->f4 != 0;
                        if (!more) {
                            n = b->fC < (unsigned int)size ? b->fC : size;
                            if (n != 0)
                                memcpy(dst, (char *)b + 0x40, n);
                            *p4 = b->name;
                            *p3 = b->f24;
                            *p5 = b->f20;
                            *p6 = n;
                            *p7 = b->f28;
                        }
                        b->used = 0;
                        b->fC = b->size;
                        b->f3C = 0;
                        b->f4 = 0;
                        r = func_0034C9A0(b, (void *)b->remote, 0x40);
                        if (r != 0)
                            return r;
                        c->cur = c->cur + b->size + 0x40;
                        if (c->cur >= c->total)
                            c->cur = 0;
                        if (more == 1) {
                            r = func_0034CA38(o, dst, size, p3, p4, p5, p6, p7);
                            if (r != 0)
                                return r;
                        }
                        ret = 0;
                    }
                }
            }
        }
    }
    return ret;
}
/* merge_units: end func_0034CA38 */

/* merge_units: begin func_0034CC60 */
#if 0 /* merge_units */
extern int func_0034CA38(int a, int b, int c, int *d, int e, int *g, int *h, int *err);
#endif /* merge_units */
#define func_0034CA38(a0, a1, a2, a3, a4, a5, a6, a7) (func_0034CA38((Obj *)(a0), (void *)(a1), (a2), (a3), (Name16 *)(a4), (a5), (a6), (a7))) /* merge_units */

int func_0034CC60(int a, int b, int c, int *out, int *err)
{
    int l0;
    int l4;
    int l8;
    int ret = 2;
    l8 = 0;
    l0 = 0;
    if (out == 0) return ret;
    *out = 0;
    if (b == 0) return ret;
    if (c == 0) return ret;
    if (err == 0) return ret;
    *err = 0;
    if (a == 0) return ret;
    ret = func_0034CA38(a, b, 2, &l0, c, &l4, &l8, err);
    if (l8 == 2) *out = 1;
    return ret;
}
#undef func_0034CA38 /* merge_units */
/* merge_units: end func_0034CC60 */
