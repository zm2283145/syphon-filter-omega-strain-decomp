/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x77: GetAimPercent. */
float cNPC_GetAimPercent(cNPC* self) {
    return self->aimPercent;
}
