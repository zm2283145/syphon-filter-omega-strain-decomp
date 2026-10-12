/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern float WeaponInv_RandomizeDroppedAmmo(int arg);
extern int NpcPerception_Clear(int arg);

int func_002D4640(Controller2D* self) {
    WeaponInv_RandomizeDroppedAmmo(self->owner->unk3524);
    return NpcPerception_Clear(self->unk1AC);
}
