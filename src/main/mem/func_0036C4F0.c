#include "types.h"
typedef struct Blk {
    unsigned int size : 28;
    unsigned int flags : 4;
    struct Blk* f4;
    struct Blk* f8;
    int fC;
} Blk;
typedef struct Heap {
    Blk bins[128];
    Blk* last;
    char* base;
    char* cur;
} Heap;
extern unsigned char D_00492F68;
extern char D_004BBF50[];
extern void func_00127358(char* fmt, ...);
extern void func_0036C030(Blk* b, Blk* v);
extern void func_0036C040(Blk* b, Blk* v);
extern Blk* func_0036C050(Blk* b);
extern Blk* func_0036C060(Heap* h, unsigned int size);
extern unsigned int func_0036C0B0(Blk* b);
unsigned long long func_0036C4F0(Heap* h)
{
    Blk* bin;
    Blk* b;
    unsigned int total;
    Blk* n;
    Blk* p;
    Blk* tgt;
    Blk* it;
    unsigned int sz;
    unsigned char merged;
    unsigned int s;
    bin = h->bins;
    total = 0;
    if (!D_00492F68) return 0;
    for (; bin <= h->last; bin++) {
        n = bin->f8;
        while (n != bin) {
            b = n;
            merged = 0;
            while ((p = (Blk*)((char*)b - ((int*)b)[-1]), !((p != 0) ^ 1)) && !((char*)p < h->base) && !(*(unsigned int*)p & 0x80000000)) {
                merged = 1;
                b->f4->f8 = b->f8;
                b->f8->f4 = b->f4;
                s = p->size + b->size;
                b = p;
                *(unsigned int*)((char*)p + s - 4) = s;
                *(unsigned int*)p = s;
            }
            while ((p = (Blk*)((char*)b + (s = b->size)), !((p != 0) ^ 1)) && (char*)p < h->cur && !(*(unsigned int*)p & 0x80000000)) {
                merged = 1;
                p->f4->f8 = p->f8;
                p->f8->f4 = p->f4;
                s = b->size + p->size;
                *(unsigned int*)((char*)b + s - 4) = s;
                *(unsigned int*)b = s;
            }
            if (merged) {
                total += s;
                b->f4->f8 = b->f8;
                b->f8->f4 = b->f4;
                tgt = func_0036C060(h, func_0036C0B0(b));
                it = tgt;
                sz = func_0036C0B0(b);
                while (func_0036C050(it) != tgt && func_0036C0B0(func_0036C050(it)) < sz) {
                    if ((char*)func_0036C050(it) < h->base || (char*)func_0036C050(it) > h->cur) {
                        func_00127358(D_004BBF50, it);
                        func_0036C040(it, tgt);
                        break;
                    }
                    it = func_0036C050(it);
                }
                func_0036C030(b, it);
                func_0036C040(b, func_0036C050(it));
                func_0036C030(func_0036C050(it), b);
                func_0036C040(it, b);
                if (h->last < tgt) h->last = tgt;
                n = bin->f8;
            } else {
                n = n->f8;
            }
        }
    }
    return total;
}




