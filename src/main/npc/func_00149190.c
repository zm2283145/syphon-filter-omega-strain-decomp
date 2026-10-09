/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x76: GetDarkness (read from the owning actor). */
int cNPC_GetDarkness(cNPC* self) {
    return self->actor->darkness;
}
