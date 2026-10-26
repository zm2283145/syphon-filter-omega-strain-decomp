typedef struct Name16 {
    int d[4];
} Name16;
typedef struct Blk {
    int used;
    int f4;
    int size;
    int fC;
    Name16 name;
    int f20;
    int f24;
    int f28;
    int self;
    char pad30[0x3C - 0x30];
    int f3C;
} Blk;
typedef struct Ctx {
    int err;
    int f4;
    int max;
    char padC[0x18 - 0xC];
    int total;
    char *base;
    char pad20[0x2C - 0x20];
    char *remote;
    char pad30[0x3C - 0x30];
    int cur;
} Ctx;
typedef struct Obj {
    char pad0[0x24];
    Ctx *ctx;
} Obj;
extern void FlushCache(int a);
extern int libnetb_block_create_space(Ctx *p, int size, int *avail, unsigned char *out);
extern int libnetb_trans_data(void *a, void *b, int n);
extern void *memcpy(void *d, const void *s, unsigned int n);

int IopRing_Send(Obj *o, void *src, int size, int p3, Name16 *p4, int p5, int *out, int *err)
{
    unsigned char ready;
    int avail;
    Ctx *c;
    Blk *b;
    int cur;
    int off;
    int n;
    int r;

    ready = 0;
    if (out == 0) return 2;
    *out = 0;
    if (src == 0) return 2;
    if (size <= 0) return 2;
    if (p4 == 0) return 2;
    if (err == 0) return 2;
    if (o == 0) return 2;
    c = o->ctx;
    if (c == 0) return 2;
    if (c->max < size) return 2;
    if (size >= c->total - 0x40) return 2;
    FlushCache(0);
    if (c->err < 0) {
        *err = c->err;
        return 1;
    }
    r = libnetb_block_create_space(c, size, &avail, &ready);
    if (r != 0)
        return r;
    if (ready == 1) {
        cur = c->cur;
        n = avail - 0x40;
        off = cur + 0x40;
        b = (Blk *)(c->base + cur);
        b->used = ready;
        b->f4 = 0;
        b->size = avail - 0x40;
        b->fC = size;
        b->name = *p4;
        b->f20 = p5;
        b->f24 = p3;
        b->f3C = ready;
        b->self = (int)b;
        memcpy((char *)b + 0x40, src, size);
        r = libnetb_trans_data((char *)b + 0x40, c->remote + off, n);
        if (r != 0)
            return r;
        r = libnetb_trans_data(b, c->remote + cur, 0x40);
        if (r != 0)
            return r;
        c->cur = c->cur + avail;
        if (c->cur >= c->total)
            c->cur = 0;
        *out = size;
    } else {
        *out = 0;
    }
    *err = *out;
    return 0;
}


