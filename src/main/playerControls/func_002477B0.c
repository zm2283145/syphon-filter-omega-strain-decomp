/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

extern int std_vector_imp_cTargetZRotationStackSlot_insert(Pair8Vec* v, Pair8* pos, int n, Pair8* value);

int cHumanMotionParams_GetTargetZRotation_TopOfStackId(ControlsUnk5C* self) {
    return self->unk5C + -1;
}

/* push_back on a vector of 8-byte elements. */
int cArray_cTargetZRotationStackSlot_PushBackActual(Pair8Vec* v, Pair8* value) {
    return std_vector_imp_cTargetZRotationStackSlot_insert(v, v->data + v->count, 1, value);
}

OptFloat* cHumanMotionParams_cTargetZRotationStackSlot_ctor(OptFloat* self, float value) {
    self->set = 1;
    self->value = value;
    return self;
}
