#include "types.h"
#pragma peephole off

typedef struct { char pad[0x40]; Q v; } Obj40;

/* Copies a quadword into the object's field at +0x40. */
void func_00370070(Obj40* obj, Q* v)
{
    obj->v = *v;
}
