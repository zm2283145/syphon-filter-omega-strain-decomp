#include "types.h"

typedef struct { char pad[0x40]; float f40; } NpcState;
typedef struct { char pad[0x30]; NpcState* state; } NpcObj;

/* Returns the NPC state float at +0x40 truncated to int. */
int cNPC_v5A(NpcObj* self)
{
    return (int)self->state->f40;
}
