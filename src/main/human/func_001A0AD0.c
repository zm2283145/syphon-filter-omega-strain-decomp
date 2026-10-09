/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_001A0AD0(char* self) {
    return self + 16;
}

int func_001A0AE0(char* self) {
    return *(int*)(self + 0);
}

/* end() over 384-byte elements. */
void func_001A0AF0(Iter16* out, PtrVec* v) {
    int count = v->count;
    char* data = (char*)v->data;

    out->p = data + count * 384;
}

void func_001A0B10(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_001A0B20(char* self) {
    return self + 160;
}
