#include "types.h"
typedef struct { char pad0[0x20]; short x; short y; char pad24[4]; short dirty; } S318318B;
typedef struct { char pad0[0x48]; S318318B* b; } S318318A;
void func_00318318(S318318A* a, float v)
{
    S318318B* b = a->b;
    b->dirty = 1;
    b->x = v / 15.625f;
}