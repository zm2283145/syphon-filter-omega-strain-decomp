/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_cBone_Size(char* self) {
    return *(int*)(self + 4);
}

void* cSkeleton_GetBoneList(char* self) {
    return self + 24;
}
