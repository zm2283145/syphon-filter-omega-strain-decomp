/*
 * Libs/SFOLib/Source/mem: 5 files, 0036C4F0-0036CA70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036C4F0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

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
extern void cMemChunk_SetPrev(Blk* b, Blk* v);
extern void cMemChunk_SetNext(Blk* b, Blk* v);
extern Blk* cMemChunk_GetNext(Blk* b);
extern Blk* cMemBin_FindBin(Heap* h, unsigned int size);
extern unsigned int cMemChunk_GetSize(Blk* b);
unsigned long long cMemBin_Consolidate(Heap* h)
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
                tgt = cMemBin_FindBin(h, cMemChunk_GetSize(b));
                it = tgt;
                sz = cMemChunk_GetSize(b);
                while (cMemChunk_GetNext(it) != tgt && cMemChunk_GetSize(cMemChunk_GetNext(it)) < sz) {
                    if ((char*)cMemChunk_GetNext(it) < h->base || (char*)cMemChunk_GetNext(it) > h->cur) {
                        printf(D_004BBF50, it);
                        cMemChunk_SetNext(it, tgt);
                        break;
                    }
                    it = cMemChunk_GetNext(it);
                }
                cMemChunk_SetPrev(b, it);
                cMemChunk_SetNext(b, cMemChunk_GetNext(it));
                cMemChunk_SetPrev(cMemChunk_GetNext(it), b);
                cMemChunk_SetNext(it, b);
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
unsigned int cMemBin_GetTotalFreeMem(G6H36* h)
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
int cMemBin_HaveAllocationInRange(G6H36* h, char* lo, int hi)
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
void cMemBin_Deallocate(Heap36C960* heap, void* p, char* file, int line);
void DELETE_DELAYS(void);
}
void DELETE_DELAYS(void)
{
    while (D_00533C90) {
        char* p;
        D_00533C90--;
        p = D_00533890[D_00533C90];
        {
            AllocGuard guard;
            if (p) {
                char heap = p[-12] & 0xF;
                cMemBin_Deallocate(&D_00533CB0[heap], p, D_004BBE50, 0x46);
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0036C960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0036C960 */

/* merge_units: begin func_0036CA70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (code lies between the mem.cc
 * and hog.cc ranges); functions are named by address until real names are known.
 */

#include "loose03_types.h"

#if 0 /* merge_units */
extern int D_00533890[256];     /* list storage (ends at the counter) */
#endif /* merge_units */
#define D_00533890 ((int*)&D_00533890) /* merge_units */


/* Append a value to the global list. */
void DELAY_DELETE_ARRAY(int value) {
    D_00533890[D_00533C90] = value;
    D_00533C90 = D_00533C90 + 1;
}

int cHogFile_GetStream(char* self) {
    return *(int*)(self + 344);
}
#undef D_00533890 /* merge_units */
static inline void merge_flush_func_0036CA70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036CA70 */
