/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

int* func_001E5220(PtrVec* v) {
    return v->data + v->count;
}

void func_001E5240(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* func_001E5250(PtrVec* v) {
    return v->data;
}

float func_001E5260(AnimScalar* self) {
    return self->unk0C;
}

/* Reset the timer from the definition's duration (+0x10). */
void AnimScalar_RestartTimer(AnimScalar* self) {
    self->timer = self->def->duration;
}
