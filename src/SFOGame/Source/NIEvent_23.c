/*
 * SFOGame/Source/NIEvent: 1 file, 0023DA80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023DA80 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0023DA80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023DA80 */
