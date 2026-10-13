#include "types.h"
#pragma peephole off

typedef struct { char pad[0x10]; Q v; } Obj10;

/* Copies a quadword into the object's field at +0x10. */
void LosResult_SetPoint(Obj10* obj, Q* v)
{
    obj->v = *v;
}
