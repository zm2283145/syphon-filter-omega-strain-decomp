/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cBone_Xform(void* self) {
    return self;
}

/* Address of 464-byte skeleton node i. */
char* cArray_cBone_opIndex_int(PtrVec* v, int i) {
    char* data = (char*)v->data;

    return data + i * 464;
}
