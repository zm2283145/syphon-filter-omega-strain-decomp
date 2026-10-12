typedef struct Blk {
    int used;
    int f4;
    int size;
    int fC;
    char pad10[0x2C - 0x10];
    struct Blk *self;
    char pad30[0x3C - 0x30];
    int f3C;
} Blk;
typedef struct Ctx {
    char pad0[0x18];
    unsigned int total;
    char *base;
    char pad20[0x2C - 0x20];
    char *remote;
    char pad30[0x3C - 0x30];
    unsigned int cur;
} Ctx;


int func_0034A6E8(Ctx *c, Blk **out, unsigned char *flag)
{
    unsigned int off;
    Blk *b;
    int ret = 2;

    if (c != 0 && out != 0) {
        *out = 0;
        if (flag != 0) {
            *flag = 0;
            off = c->cur;
            b = (Blk *)(c->base + off);
            while (b->f4 == 1) {
                off = off + b->size + 0x40;
                if (off >= c->total)
                    off = 0;
                b = (Blk *)(c->base + off);
                if (off == c->cur) {
                    *out = 0;
                    *flag = 0;
                    return 0;
                }
            }
            if (b->used == 1 && b->f3C == 1) {
                *out = b;
                *flag = 1;
            } else {
                *out = 0;
                *flag = 0;
            }
            ret = 0;
        }
    }
    return ret;
}
