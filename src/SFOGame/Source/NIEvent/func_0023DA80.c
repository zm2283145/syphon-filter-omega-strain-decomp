/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int std_vector_cNIEventBasePtr_size(char* self) {
    return *(int*)(self + 4);
}

int cArray_cNIEventBasePtr_Size(char* self) {
    return *(int*)(self + 4);
}

int* cArray_cNIEventBasePtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

int* std_vector_imp_cNIEventBasePtr_1_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

unsigned char cGOBJ_IsStreaming(unsigned char* self) {
    return self[46];
}
