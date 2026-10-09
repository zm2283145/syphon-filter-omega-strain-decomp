/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

extern char D_004E0800[];  /* IfModelItem vtable */
extern int func_003F2020(RawVec* v, char* pos, int n, int value);

/* Clears the three vector words. */
OwnedVec* func_003F1BF0(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

/* IfModelItem constructor. */
IfModelItem* func_003F1C10(IfModelItem* self) {
    self->vtable = D_004E0800;
    self->unk04 = 0;
    self->unk08 = -1.0f;
    self->unk0C = -1.0f;
    self->unk10 = 0;
    self->unk14 = 0;
    return self;
}

/* push_back on a vector of bytes. */
int func_003F1C40(RawVec* v, int value) {
    return func_003F2020(v, v->data + v->count, 1, value);
}
