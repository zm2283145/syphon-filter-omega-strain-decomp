/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* cArray_cGameGOBJPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

int cArray_cGameGOBJPtr_Size(char* self) {
    return *(int*)(self + 4);
}

void* std_vector_pod_int_data(char* self) {
    return self + 8;
}
