/*
 * main/mem: range (4 files, 0036C4F0-0036C960)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_0036C4F0 */
#pragma push /* merge_units */
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
extern void printf(char* fmt, ...);
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
                        printf(D_004BBF50, it);
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0036C4F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0036C4F0 */

/* merge_units: begin func_0036C810 */
#pragma push /* merge_units */
typedef struct G6N36 { unsigned int size : 28; unsigned int flags : 4; int x; struct G6N36* next; struct G6N36* prev; } G6N36;
typedef struct { G6N36 bins[128]; G6N36* last; } G6H36;
unsigned int func_0036C810(G6H36* h)
{
    G6N36* n;
    unsigned int max;
    G6N36* end;
    G6N36* b;
    end = h->last;
    b = h->bins;
    max = 0;
    for (; b <= end; b++) {
        for (n = b->next; n != b; n = n->next) {
            if (n->size > max) max = n->size;
        }
    }
    return max;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0036C810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0036C810 */

/* merge_units: begin func_0036C880 */
#pragma push /* merge_units */
int func_0036C880(G6H36* h, char* lo, int hi)
{
    char* e;
    G6N36* n;
    unsigned int w;
    G6N36* b;
    G6N36* end;
    end = h->last;
    for (b = h->bins; b <= end; b++) {
        for (n = b->next; n != b; n = n->next) {
            w = *(unsigned int*)n;
            if (w & 0x80000000) {
                if ((int)n < hi && lo < (char*)n + (w & 0x0FFFFFFF)) return 1;
            } else {
                if ((int)n < hi && lo < (char*)(n + 1)) return 1;
                e = (char*)n + (w & 0x0FFFFFFF);
                if ((unsigned)(e - 4) < hi && lo < e) return 1;
            }
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0036C880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0036C880 */

/* merge_units: begin func_0036C960 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Free every pending deferred heap block (heap index in the block header). */
struct Heap36C960 { char b[0x818]; };
extern "C" {
extern int D_00533C90;
extern char* D_00533890[];
extern Heap36C960 D_00533CB0[];
extern char D_004BBE50[];
void Mem_HeapFree(Heap36C960* heap, void* p, char* file, int line);
void Mem_PumpDeferredFrees(void);
}
void Mem_PumpDeferredFrees(void)
{
    while (D_00533C90) {
        char* p;
        D_00533C90--;
        p = D_00533890[D_00533C90];
        {
            AllocGuard guard;
            if (p) {
                char heap = p[-12] & 0xF;
                Mem_HeapFree(&D_00533CB0[heap], p, D_004BBE50, 0x46);
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0036C960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0036C960 */
