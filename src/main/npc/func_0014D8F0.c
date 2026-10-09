/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int func_0014D900(cNPC* npc, int a1, int a2, float f12);

/* vtable slot 0x52: RequestAction. */
int cNPC_RequestAction(cNPC* self, int a1, int a2) {
    return func_0014D900(self, a1, a2, 0.0f);
}
