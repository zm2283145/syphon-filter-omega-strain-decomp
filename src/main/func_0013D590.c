/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back(value). */
int func_0013D590(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return PtrVec_Insert(v, data + count, 1, value);
}

Unk0013D5B0* func_0013D5B0(Unk0013D5B0* self) {
    self->unk10 = 3658;
    return self;
}
