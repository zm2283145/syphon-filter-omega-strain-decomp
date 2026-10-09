/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x28. */
int cNPC_v28(cNPC* self, unsigned char i) {
    return self->unk17C[i].unk00;
}

/* vtable slot 0x27. */
signed char cNPC_v27(cNPC* self) {
    return self->unk13C;
}

/* vtable slot 0x34. */
float cNPC_v34(cNPC* self) {
    return self->unk060;
}
