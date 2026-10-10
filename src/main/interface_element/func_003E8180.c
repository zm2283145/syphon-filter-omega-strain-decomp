#include "types.h"
#pragma peephole off

typedef struct { char pad[0x20]; Q v; } Obj20;

/* Copies a quadword into the object's field at +0x20. */
void func_003E8180(Obj20* obj, Q* v)
{
    obj->v = *v;
}
