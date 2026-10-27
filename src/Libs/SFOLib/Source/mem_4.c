/*
 * Libs/SFOLib/Source/mem: 4 files, 0036C030-0036C0C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036C030 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * mem.cc
 */

#include "types.h"
#include "mem_types.h"

/* Setter for unk08. */
void cMemChunk_SetPrev(MemObj* self, int value) {
    self->unk08 = value;
}

/* Setter for unk04. */
void cMemChunk_SetNext(MemObj* self, int value) {
    self->unk04 = value;
}

/* Getter for unk04. */
int cMemChunk_GetNext(MemObj* self) {
    return self->unk04;
}
static inline void merge_flush_func_0036C030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036C030 */

/* merge_units: begin func_0036C060 */
#pragma push /* merge_units */
int cMemBin_FindBin(int a0, int a1) {
    int at, v0;
    int cond;

    v0 = (unsigned int)a1 < (unsigned int)40;
    cond = v0 != 0;
    if (cond) goto L0036C090;
L0036C070:;
    a1 = (unsigned int)a1 >> 1;
    at = (unsigned int)a1 < (unsigned int)40;
    a0 = a0 + 64;
    cond = at == 0;
    if (cond) goto L0036C070;
L0036C090:;
    v0 = a1 + -20;
    v0 = (unsigned int)v0 >> 2;
    v0 = v0 << 4;
    a0 = a0 + v0;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_0036C060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036C060 */

/* merge_units: begin func_0036C0B0 */
#pragma push /* merge_units */
typedef struct { unsigned int val : 28; unsigned int top : 4; } Packed28;
/* Returns the low 28-bit field of the packed word. */
unsigned int cMemChunk_GetSize(Packed28* p) { return p->val; }
static inline void merge_flush_func_0036C0B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036C0B0 */

/* merge_units: begin func_0036C0C0 */
#pragma push /* merge_units */
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
extern void printf(char* fmt, ...);
#if 0 /* merge_units */
extern void cMemChunk_SetPrev(Blk* b, Blk* v);
#endif /* merge_units */
#define cMemChunk_SetPrev(a0, a1) (cMemChunk_SetPrev((MemObj *)(a0), (int)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMemChunk_SetNext(Blk* b, Blk* v);
#endif /* merge_units */
#define cMemChunk_SetNext(a0, a1) (cMemChunk_SetNext((MemObj *)(a0), (int)(a1))) /* merge_units */

#if 0 /* merge_units */
extern Blk* cMemChunk_GetNext(Blk* b);
#endif /* merge_units */
#define cMemChunk_GetNext(a0) ((Blk *)cMemChunk_GetNext((MemObj *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern Blk* cMemBin_FindBin(Heap* h, unsigned int size);
#endif /* merge_units */
#define cMemBin_FindBin(a0, a1) ((Blk *)cMemBin_FindBin((int)(a0), (int)(a1))) /* merge_units */

#if 0 /* merge_units */
extern unsigned int cMemChunk_GetSize(Blk* b);
#endif /* merge_units */
#define cMemChunk_GetSize(a0) (cMemChunk_GetSize((Packed28 *)(a0))) /* merge_units */

extern unsigned long long cMemBin_Consolidate(Heap* h);

static inline unsigned char Blk_Valid(Blk* b)
{
    unsigned int s = b->size;
    if (s == 0 || s != *(unsigned int*)((char*)b + s - 4)) return 0;
    return 1;
}

char* cMemBin_Allocate(Heap* h, unsigned int size, char* file, int line)
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
                printf(D_004BBEC0);
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
                    if (cMemBin_Consolidate(h) == 0) tries++;
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
            printf(D_004BBF40, buf);
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
            tgt = cMemBin_FindBin(h, cMemChunk_GetSize(nb));
            it = tgt;
            sz2 = cMemChunk_GetSize(nb);
            while (cMemChunk_GetNext(it) != tgt && cMemChunk_GetSize(cMemChunk_GetNext(it)) < sz2) {
                if ((char*)cMemChunk_GetNext(it) < h->base || (char*)cMemChunk_GetNext(it) > h->cur) {
                    printf(D_004BBF50, it);
                    cMemChunk_SetNext(it, tgt);
                    break;
                }
                it = cMemChunk_GetNext(it);
            }
            cMemChunk_SetPrev(nb, it);
            cMemChunk_SetNext(nb, cMemChunk_GetNext(it));
            cMemChunk_SetPrev(cMemChunk_GetNext(it), nb);
            cMemChunk_SetNext(it, nb);
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
#undef cMemChunk_SetPrev /* merge_units */
#undef cMemChunk_SetNext /* merge_units */
#undef cMemChunk_GetNext /* merge_units */
#undef cMemBin_FindBin /* merge_units */
#undef cMemChunk_GetSize /* merge_units */
static inline void merge_flush_func_0036C0C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036C0C0 */
