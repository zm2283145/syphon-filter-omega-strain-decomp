#include "types.h"
#pragma peephole off

typedef struct Obj40 {
    char pad[0x30];
    Q q;
} Obj40;

extern void Mtx_SetRow0(Obj40*);
extern void Mtx_SetRow1(Obj40*, int);
extern void Mtx_SetRow2(Obj40*, int);

/* Constructor: base init, two setters, then copies a vector to +0x30. */
Obj40* func_00131F00(Obj40* o, int unused, int a, int b, Q* q) {
    Mtx_SetRow0(o);
    Mtx_SetRow1(o, a);
    Mtx_SetRow2(o, b);
    o->q = *q;
    return o;
}
