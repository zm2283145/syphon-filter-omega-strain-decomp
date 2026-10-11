#include "types.h"
typedef struct { int pad0[3]; long long* start; long long* end; int count; int pad18; unsigned char open; char pad1D[3]; } B375650;
typedef struct {
    int pad0; B375650* curA; B375650* curB; char padC[0x20]; char bufs[0xA4];
    B375650* lastA; B375650* lastB; int aD8; int padDC; int idxA; int idxB; int padE8; int sizeA; int sizeB;
} S375650;
extern void func_00375770(S375650* o, int a);
extern void func_0036C960(void);
void func_00375650(S375650* o)
{
    B375650* p;
    func_00375770(o, 1);
    o->sizeA = (o->curA->end - o->curA->start) * 8;
    o->lastA = o->curA;
    o->idxA ^= 1;
    o->curA = (B375650*)((char*)o + o->idxA * 96 + 0x2C);
    p = o->curA;
    p->end = p->start;
    p->count = 0;
    p->open = 0;
    o->sizeB = (o->curB->end - o->curB->start) * 8;
    o->lastB = o->curB;
    o->idxB ^= 1;
    o->curB = (B375650*)((char*)o + o->idxB * 96 + 0x4C);
    p = o->curB;
    p->end = p->start;
    p->count = 0;
    p->open = 0;
    func_0036C960();
    if (o->aD8 >= 0) o->aD8 = -1;
}


