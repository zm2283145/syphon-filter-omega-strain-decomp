/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x2A: returns the AI controller. */
NpcAi* cNPC_v2A(cNPC* self) {
    return self->ai;
}
