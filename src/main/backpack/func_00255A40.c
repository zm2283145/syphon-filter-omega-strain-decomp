/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack flag setter.
 */

#include "types.h"
#include "backpack_types.h"

void cBackpack_SetHasTakenPlayerItems(cBackpack* backpack) {
    backpack->unk30C = 1;
}
