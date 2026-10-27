/*
 * Libs/SFOLib/Source/dmaman: 1 file, 00375770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00375770 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { int pad0[3]; long long* start; long long* end; int count; int pad18; unsigned char open; char pad1D[3]; } B375770;
typedef struct {
    B375770* cur[3]; char padC[0x20]; char bufs[0xA0];
    B375770* last0; B375770* lastA; B375770* lastB; int aD8; int idx0; int idxA; int idxB; int size0; int sizeA; int sizeB;
} S375770;
extern "C" void FlushCache(int a);
#define R(a) (*(volatile unsigned int*)(a))
static inline void KickVif(unsigned int base, int bit, int tag, int mode)
{
    while (R(base) & 0x100) {
    }
    R(base + 0x20) = 0;
    R(0x1000E020) |= bit;
    R(0x1000E010) = bit;
    if (((unsigned int)tag & 0x70000000) == 0x70000000) {
        R(base + 0x30) = (unsigned int)tag | 0x80000000;
    } else {
        R(base + 0x30) = (unsigned int)tag & 0x0FFFFFFF;
        FlushCache(0);
    }
    int v = 0x185;
    if (mode) v |= 0x40;
    asm volatile ("sync");
    R(base) = v;
}
static inline void KickGif(int tag)
{
    while (R(0x1000A000) & 0x100) {
    }
    R(0x1000A020) = 0;
    R(0x1000E010) = 4;
    if (((unsigned int)tag & 0x70000000) == 0x70000000) {
        R(0x1000A030) = (unsigned int)tag | 0x80000000;
    } else {
        R(0x1000A030) = (unsigned int)tag & 0x0FFFFFFF;
        FlushCache(0);
    }
    asm volatile ("sync");
    R(0x1000A000) = 0x185;
}
static inline void Flip(S375770* o)
{
    B375770* p = o->cur[0];
    o->size0 = (p->end - p->start) * 8;
    o->last0 = o->cur[0];
    o->idx0 ^= 1;
    o->cur[0] = (B375770*)((char*)o + o->idx0 * 96 + 0xC);
    {
        B375770* q = o->cur[0];
        q->end = q->start;
        q->count = 0;
        q->open = 0;
    }
}
extern "C" void cDmaMan_Kick(S375770* o, int ch)
{
    B375770* b;
    if (o->aD8 < 0) {
        b = o->cur[ch];
        if (b->end != b->start) {
            *b->end++ = 0x70000000;
            *b->end++ = 0;
            if (ch == 1) {
                KickVif(0x10009000, 2, (int)b->start, 0x40);
            } else if (ch == 2) {
                KickGif((int)b->start);
            } else if (ch == 0) {
                KickVif(0x10008000, 1, (int)b->start, 0x40);
                Flip(o);
            }
        }
    }
}
static inline void merge_flush_func_00375770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00375770 */
