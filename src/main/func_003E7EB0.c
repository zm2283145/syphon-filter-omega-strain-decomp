/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern float TextObj_SetText(int, int);

void IeElement_SetData(Unk3E7EB0* self, int value) {
    self->unk78 = value;
}

float IeElement_SetText(Unk3E7EB0* self, int a1) {
    return TextObj_SetText(self->unk74, a1);
}
