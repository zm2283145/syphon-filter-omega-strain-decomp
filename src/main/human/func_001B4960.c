#include "types.h"
#pragma peephole off

typedef struct { char pad[0x40]; Q q; } Obj40;

/* Copies a 16-byte vector into the object at +0x40. */
void ActorNode_SetPosition(Obj40* self, Q* src)
{
    self->q = *src;
}
