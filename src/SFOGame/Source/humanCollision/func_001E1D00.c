#include "types.h"
#pragma peephole off

typedef struct { char pad[0x30]; Q v; } Obj30;

/* Copies a quadword into the object's field at +0x30. */
void cCollisionFace_SetUnitNormal(Obj30* obj, Q* v)
{
    obj->v = *v;
}
