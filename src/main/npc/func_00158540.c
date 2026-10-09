/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

/* Returns the word at +0x30 (the owning actor if this is a cNPC). */
NpcActor* func_00158540(cNPC* self) {
    return self->actor;
}
