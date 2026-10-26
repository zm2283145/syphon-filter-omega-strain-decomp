/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int std_vector_pod_int_size(char* self) {
    return *(int*)(self + 4);
}

int std_vector_imp_cNIEventBasePtr_1_size(char* self) {
    return *(int*)(self + 4);
}
