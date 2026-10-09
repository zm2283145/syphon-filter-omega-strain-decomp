/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x42: SetAggressiveness. */
void cNPC_SetAggressiveness(cNPC* self, float value) {
    self->aggressiveness = value;
}
