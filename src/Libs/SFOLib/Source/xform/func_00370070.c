#include "types.h"
#pragma peephole off

typedef struct { char pad[0x40]; Q v; } Obj40;

/* Copies a quadword into the object's field at +0x40. */
void cXform_SetTranslation_ParentRelative(Obj40* obj, Q* v)
{
    obj->v = *v;
}
