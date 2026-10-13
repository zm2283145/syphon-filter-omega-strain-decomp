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
extern void FlushCache(int a);
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

