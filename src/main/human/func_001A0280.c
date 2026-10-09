/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void* RootCollection_FindByKey(void*, int);

int func_001A0280(char* self) {
    return *(int*)(self + 176);
}

/* back(): address of the last element. */
int* PtrVec_Back(PtrVec* v) {
    return v->data + v->count - 1;
}

/* Find in the root collection at +0xB0. */
void* func_001A02B0(char* self, int key) {
    return RootCollection_FindByKey(self + 176, key);
}
