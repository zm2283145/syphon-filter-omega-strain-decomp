/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float func_001AF320(char* self) {
    return *(float*)(self + 4);
}

/* Address of 464-byte skeleton node i. */
char* func_001AF330(PtrVec* v, int i) {
    char* data = (char*)v->data;

    return data + i * 464;
}

int func_001AF350(char* self) {
    return *(int*)(self + 0);
}

int func_001AF360(char* self) {
    return *(int*)(self + 0);
}

void func_001AF370(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001AF390(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int func_001AF3A0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Iterator ++ over 464-byte nodes. */
Iter16* func_001AF3C0(Iter16* it) {
    it->p = it->p + 464;
    return it;
}
