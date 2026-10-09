/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int func_00147CD0(WeaponRec24Vec* v, WeaponRec24* pos, int n, WeaponRec24* value);

/* push_back on a vector of 24-byte elements. */
int func_00147600(WeaponRec24Vec* v, WeaponRec24* value) {
    return func_00147CD0(v, v->data + v->count, 1, value);
}
