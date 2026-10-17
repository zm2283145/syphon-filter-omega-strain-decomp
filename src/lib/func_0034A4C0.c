typedef struct Blk {
    int used;
    int f4;
    int f8;
    int fC;
    char pad10[0x2C - 0x10];
    char* self;
    char pad30[0x3C - 0x30];
    int f3C;
} Blk;

typedef struct Heap {
    char pad0[0x18];
    int total;
    char* base;
    char pad20[0x2C - 0x20];
    char* base2;
    char pad30[0x3C - 0x30];
    int cur;
} Heap;

int func_0034A458(Blk* b, int size, unsigned int* out);
int func_0034C9A0(void* dst, void* src, int n);

int func_0034A4C0(Heap* h, int size, unsigned int* outSize, char* outFlag)
{
    unsigned int need;
    unsigned int got;
    Blk* b;
    int avail;
    register int ret asm("$2");

    got = 0;
    ret = 2;
    if (h != 0 && outSize != 0 && outFlag != 0) {
        need = size + 0x40;
        if (need & 0x3F)
            need = need - (need & 0x3F) + 0x40;
        *outSize = need;
        ret = 1;
        if (h->cur < h->total) {
            b = (Blk*)(h->base + h->cur);
            if (b->used != 0 || b->f3C != 0) {
                goto fail;
            } else {
                avail = h->total - h->cur;
                ret = func_0034A458(b, avail, &got);
                if (ret == 0) {
                    if (got < need && avail - got < 0x40 && b != (Blk*)h->base) {
                        int v = avail - 0x40;
                        b->used = 1;
                        b->f4 = 1;
                        b->f8 = v;
                        b->fC = v;
                        b->f3C = 1;
                        b->self = b;
                        ret = func_0034C9A0(b, h->base2 + h->cur, 0x40);
                        if (ret == 0) {
                            h->cur = 0;
                            ret = func_0034A4C0(h, size, outSize, outFlag);
                        }
                    } else if (got < need) {
                        goto fail;
                    } else {
                        if (need < got) {
                            Blk* n = (Blk*)(h->base + h->cur + need);
                            int v;
                            n->used = 0;
                            n->f4 = 0;
                            v = got - need - 0x40;
                            n->f3C = 0;
                            n->f8 = v;
                            n->fC = v;
                            ret = func_0034C9A0(h->base + h->cur + need, h->base2 + h->cur + need, 0x40);
                            if (ret != 0)
                                goto out;
                        }
                        {
                            int v = need - 0x40;
                            b = (Blk*)(h->base + h->cur);
                            b->f3C = 0;
                            b->used = 0;
                            b->f4 = 0;
                            b->f8 = v;
                            b->fC = v;
                            ret = func_0034C9A0(h->base + h->cur, h->base2 + h->cur, 0x40);
                            if (ret == 0) {
                                *outFlag = 1;
                                goto ret0;
                            }
                        }
                    }
                }
            }
        }
    }
goto out;
fail:
    *outFlag = 0;
ret0:
    ret = 0;
out:
    return ret;
}



