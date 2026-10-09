/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern float func_00142170(int arg);
extern int func_0016DC60(int arg);

int func_002D4640(Controller2D* self) {
    func_00142170(self->owner->unk3524);
    return func_0016DC60(self->unk1AC);
}
