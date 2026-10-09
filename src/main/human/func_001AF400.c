/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_001AF400(char* self) {
    return self + 368;
}

int func_001AF410(char* self) {
    return *(int*)(self + 0);
}

/* end() over 464-byte nodes. */
void func_001AF420(Iter16* out, PtrVec* v) {
    int count = v->count;
    char* data = (char*)v->data;

    out->p = data + count * 464;
}

void func_001AF450(Iter* out, PtrVec* v) {
    out->p = v->data;
}
