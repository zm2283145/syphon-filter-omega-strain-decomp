/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

void* cMovement_PrevTransform(char* self) {
    return self + 16;
}

unsigned char cMovement_WasMovingLastFrame(unsigned char* self) {
    return self[0];
}

int cGOBJ_GetMovementInfo(Unk001827A0* self) {
    return self->unk54;
}

int cArray_cGOBJPtr_Iterator_opMul(Word* w) {
    return w->value;
}
