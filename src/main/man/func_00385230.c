/*
 * Matched functions (byte-identical with the retail executable).
 * True when equipment slot 0 is occupied.
 */

#include "types.h"
#include "man_types.h"

int func_00385230(ManEquipOwner* self) {
    return (unsigned int)self->slots[0] > 0u;
}
