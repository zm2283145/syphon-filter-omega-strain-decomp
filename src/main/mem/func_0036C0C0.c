#include "types.h"
typedef struct Blk {
    unsigned int size : 28;
    unsigned int flags : 4;
    struct Blk* f4;
    struct Blk* f8;
    short line;
    short fE;
} Blk;
typedef struct Heap {
    Blk bins[128];
    Blk* last;
    char* base;
    char* cur;
    unsigned int limit;
    unsigned int gran;
} Heap;
extern char D_004BBEC0[];
extern char D_004BBEF0[];
extern char D_004BBF40[];
extern char D_004BBF50[];
extern int sprintf(char* buf, const char* fmt, ...);
extern void func_00127358(char* fmt, ...);
extern void func_0036C030(Blk* b, Blk* v);
extern void func_0036C040(Blk* b, Blk* v);
extern Blk* func_0036C050(Blk* b);
extern Blk* func_0036C060(Heap* h, unsigned int size);
extern unsigned int func_0036C0B0(Blk* b);
extern unsigned long long func_0036C4F0(Heap* h);

static inline unsigned char Blk_Valid(Blk* b)
{
    unsigned int s = b->size;
    if (s == 0 || s != *(unsigned int*)((char*)b + s - 4)) return 0;
    return 1;
}

char* Mem_HeapAlloc(Heap* h, unsigned int size, char* file, int line)
{
    char buf[0x80];
    Blk* bin;
    Blk* b;
    unsigned char found;
    int tries;
    Blk* start;
    Blk* nb;
    Blk* tgt;
    Blk* it;
    unsigned int sz2;
    unsigned int n;
    unsigned int sz;
    unsigned int v;
    char* p;
    unsigned int rem;

    if (h->gran) n = h->gran * (size / h->gran + 1);
    else n = size;
    found = 0;
    tries = 0;
    sz = (n + 0x23) & ~0xF;
    start = h->bins;
    v = sz;
    while (v >= 0x28) {
        v >>= 1;
        start += 4;
    }
    start += (v - 0x14) >> 2;
    bin = start;
    while (!(found & 0xFF) && tries < 2) {
        b = bin->f4;
        while (b != bin) {
            if (!Blk_Valid(b)) {
                func_00127358(D_004BBEC0);
                tries = 0;
                b->f4->f8 = b->f8;
                b->f8->f4 = b->f4;
                break;
            }
            if (b->size >= sz) {
                found = 1;
                b->f4->f8 = b->f8;
                b->f8->f4 = b->f4;
                break;
            }
            b = b->f4;
        }
        if (!found) {
            bin++;
            if (h->last < bin) {
                if (tries == 0) {
                    if (func_0036C4F0(h) == 0) tries++;
                    bin = start;
                }
                tries++;
            }
        }
    }
    if (!found) {
        p = h->cur;
        if (p + sz >= h->base + h->limit) {
            sprintf(buf, D_004BBEF0, h->base, p, sz, 0);
            func_00127358(D_004BBF40, buf);
            p = 0;
        } else {
            *(unsigned int*)(p + sz - 4) = sz;
            *(unsigned int*)p = sz;
            h->cur += sz;
        }
        b = (Blk*)p;
        if (p) found = 1;
    }
    if (found) {
        rem = b->size - sz;
        nb = 0;
        if (rem > 0x14) {
            nb = (Blk*)((char*)b + sz);
            *(unsigned int*)((char*)nb + rem - 4) = rem;
            *(unsigned int*)nb = rem;
            ((unsigned int*)nb)[-1] = sz;
            *(unsigned int*)b = sz;
        }
        if (nb) {
            tgt = func_0036C060(h, func_0036C0B0(nb));
            it = tgt;
            sz2 = func_0036C0B0(nb);
            while (func_0036C050(it) != tgt && func_0036C0B0(func_0036C050(it)) < sz2) {
                if ((char*)func_0036C050(it) < h->base || (char*)func_0036C050(it) > h->cur) {
                    func_00127358(D_004BBF50, it);
                    func_0036C040(it, tgt);
                    break;
                }
                it = func_0036C050(it);
            }
            func_0036C030(nb, it);
            func_0036C040(nb, func_0036C050(it));
            func_0036C030(func_0036C050(it), nb);
            func_0036C040(it, nb);
            if (h->last < tgt) h->last = tgt;
        }
        b->line = line;
        b->fE = 0;
        *(unsigned int*)b |= 0x80000000;
        { unsigned int t = ((sz - 0x14 - size) & 0xF) << 4; *((signed char*)b + 4) = t + (*((signed char*)b + 4) & 0xF); }
        return (char*)b + 0x10;
    }
    return 0;
}




