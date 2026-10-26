/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cQuaternion_ctor_void(void* self) {
    return self;
}

int Root_GetParent(char* self) {
    return *(int*)(self + 176);
}
