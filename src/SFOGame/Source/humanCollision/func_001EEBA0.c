/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F5000[];
extern void __destroy_array(int, int, int, int);
extern int cCollisionProbe_Ray_dtor(int, int);

void* std_vector_deleter_cCollisionFace_data_void(char* self) {
    return self + 8;
}

void func_001EEBB0(void) {
    __destroy_array((int)D_004F5000, (int)cCollisionProbe_Ray_dtor, 112, 7);
}
