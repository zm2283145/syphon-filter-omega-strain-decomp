/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cRayMatrix_ctor_void(void* self) {
    return self;
}

void std_vector_cCollisionFace_clear(char* self) {
    *(int*)(self + 4) = 0;
}
