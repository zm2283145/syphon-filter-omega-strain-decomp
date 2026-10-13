#include "types.h"
typedef struct { int pad0[3]; long long* start; long long* end; int count; int pad18; unsigned char open; char pad1D[3]; } B375770;
typedef struct {
    B375770* cur[3]; char padC[0x20]; char bufs[0xA0];
    B375770* last0; B375770* lastA; B375770* lastB; int aD8; int idx0; int idxA; int idxB; int size0; int sizeA; int sizeB;
} S375770;
extern int func_001037A8(int, int);
void func_00375CD0(S375770* o)
{
    B375770* p;
    func_001037A8(0, 0);
    p = o->cur[0];
    o->size0 = (p->end - p->start) * 8;
    o->last0 = o->cur[0];
    o->idx0 ^= 1;
    o->cur[0] = (B375770*)((char*)o + o->idx0 * 96 + 0xC);
    p = o->cur[0];
    p->end = p->start;
    p->count = 0;
    p->open = 0;
    p = o->cur[1];
    o->sizeA = (p->end - p->start) * 8;
    o->lastA = o->cur[1];
    o->idxA ^= 1;
    o->cur[1] = (B375770*)((char*)o + o->idxA * 96 + 0x2C);
    p = o->cur[1];
    p->end = p->start;
    p->count = 0;
    p->open = 0;
    p = o->cur[2];
    o->sizeB = (p->end - p->start) * 8;
    o->lastB = o->cur[2];
    o->idxB ^= 1;
    o->cur[2] = (B375770*)((char*)o + o->idxB * 96 + 0x4C);
    p = o->cur[2];
    p->end = p->start;
    p->count = 0;
    p->open = 0;
    o->aD8 = -1;
}
