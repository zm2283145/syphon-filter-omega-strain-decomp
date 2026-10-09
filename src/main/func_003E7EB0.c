/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern float func_003D08B0(int, int);

void func_003E7EB0(Unk3E7EB0* self, int value) {
    self->unk78 = value;
}

float func_003E7EC0(Unk3E7EB0* self, int a1) {
    return func_003D08B0(self->unk74, a1);
}
