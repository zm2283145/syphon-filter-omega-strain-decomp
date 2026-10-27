#pragma cplusplus on
#include "alloc_guard.h"
#include "types.h"
typedef struct { int size; long long* base; unsigned int limit; unsigned int start; unsigned int cur; int count; int pad18; unsigned char open; char pad1D[3]; } B375E50;
typedef struct {
    B375E50* cur[3]; B375E50 bufs[2][3];
    B375E50* last0; B375E50* lastA; B375E50* lastB; int aD8; int idx0; int idxA; int idxB; int size0; int sizeA; int sizeB;
} S375E50;
extern "C" {
extern char D_004BC160[];
extern void sceDmaReset(int);
extern void* memset(void*, int, unsigned int);
extern void FlushCache(int);
extern void* cMemMan_Allocate(int, int, char*, int);
extern void cDmaMan_Reset(S375E50*);
}
static inline void SetupBuf(B375E50* b)
{
    b->limit = (unsigned int)(b->base + b->size);
    b->start = ((int)b->base + 0x7F) / 128 * 128;
    b->cur = b->start;
    b->start |= 0x20000000;
    b->limit |= 0x20000000;
    b->cur |= 0x20000000;
    FlushCache(0);
}
static inline void* AllocBuf(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004BC160, line);
}
extern "C" void cDmaMan_Init(S375E50* o, int sz0, int sz1, int sz2)
{
    int i;
    sceDmaReset(1);
    memset(o->bufs, 0, sizeof(o->bufs));
    for (i = 0; i < 2; i++) {
        if (sz0) {
            B375E50* b = &o->bufs[i][0];
            b->size = sz0 / 8;
            b->size = 0x800;
            b->base = (long long*)0x70000000;
            SetupBuf(b);
        }
        if (sz1) {
            B375E50* b = &o->bufs[i][1];
            b->size = sz1 / 8;
            b->base = (long long*)AllocBuf(b->size * 8, 0x53);
            SetupBuf(b);
        }
        if (sz2) {
            B375E50* b = &o->bufs[i][2];
            b->size = sz2 / 8;
            b->base = (long long*)AllocBuf(b->size * 8, 0x65);
            SetupBuf(b);
        }
    }
    o->idx0 = 1;
    o->idxA = 1;
    o->idxB = 1;
    o->cur[0] = &o->bufs[1][0];
    o->cur[1] = &o->bufs[1][1];
    o->cur[2] = &o->bufs[1][2];
    o->last0 = &o->bufs[0][0];
    o->lastA = &o->bufs[0][1];
    o->lastB = &o->bufs[0][2];
    cDmaMan_Reset(o);
}




