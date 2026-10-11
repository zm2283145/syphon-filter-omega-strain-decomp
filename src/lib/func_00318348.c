#include "types.h"
typedef struct { char pad0[0x20]; short x; short y; char pad24[4]; short dirty; } S318348B;
typedef struct { char pad0[0x48]; S318348B* b; } S318348A;
void func_00318348(S318348A* a, float v)
{
    S318348B* b = a->b;
    b->dirty = 1;
    b->y = v / 15.625f;
}