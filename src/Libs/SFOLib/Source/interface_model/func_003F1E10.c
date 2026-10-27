/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

/* Setter for field +0x1C. */
void func_003F1E10(char* self, int value) {
    *(int*)(self + 0x1C) = value;
}

int* func_003F1E20(PtrVec* v, int i) {
    return v->data + i;
}

/* Getter for field +0x04 (vector count). */
int func_003F1E30(PtrVec* v) {
    return v->count;
}
