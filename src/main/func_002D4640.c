/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern float cWeapon_SetAmmoNpcDeath(int arg);
extern int cAITarget_dtor(int arg);

int func_002D4640(Controller2D* self) {
    cWeapon_SetAmmoNpcDeath(self->owner->unk3524);
    return cAITarget_dtor(self->unk1AC);
}
