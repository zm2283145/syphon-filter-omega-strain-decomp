/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "humanIk_types.h"

IkBytePair* cDrawAndHolsterWeapon_ActionManager_cWeaponSlotPair_ctor(IkBytePair* dst, IkBytePair* src) {
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}
