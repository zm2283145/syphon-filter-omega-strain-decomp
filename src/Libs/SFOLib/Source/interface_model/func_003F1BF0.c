/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

extern char D_004E0800[];  /* IfModelItem vtable */
extern int std_vector_pod_AnimType_insert(RawVec* v, char* pos, int n, int value);

/* Clears the three vector words. */
OwnedVec* std_vector_imp_cAnimatorPtr_1_ctor(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

/* IfModelItem constructor. */
IfModelItem* cAnimator_ctor(IfModelItem* self) {
    self->vtable = D_004E0800;
    self->unk04 = 0;
    self->unk08 = -1.0f;
    self->unk0C = -1.0f;
    self->unk10 = 0;
    self->unk14 = 0;
    return self;
}

/* push_back on a vector of bytes. */
int std_vector_AnimType_push_back(RawVec* v, int value) {
    return std_vector_pod_AnimType_insert(v, v->data + v->count, 1, value);
}
