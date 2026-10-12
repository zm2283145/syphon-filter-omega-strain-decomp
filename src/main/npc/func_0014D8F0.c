/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int NpcAi_RequestAction(cNPC* npc, int a1, int a2, float f12);

/* vtable slot 0x52: RequestAction. */
int cNPC_RequestAction(cNPC* self, int a1, int a2) {
    return NpcAi_RequestAction(self, a1, a2, 0.0f);
}
