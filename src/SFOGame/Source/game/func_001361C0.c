/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_imp_cCollisionFace_reserve(int, int);

int std_vector_cCollisionFace_reserve(int a0, int a1) {
    return std_vector_imp_cCollisionFace_reserve(a0, a1);
}

int cArrayCapacity_Int(char* self) {
    return *(int*)(self + 0);
}

Rel* std_vector_cCollisionFace_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
