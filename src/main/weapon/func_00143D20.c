/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern signed char D_00489D60[];

/* Maps a weapon id through definition byte +0x30 and the D_00489D60 table. */
int func_00143D20(int id) {
    WeaponDef* def = WeaponDb_Get(D_004FFD30, id);

    return D_00489D60[def->unk30];
}
