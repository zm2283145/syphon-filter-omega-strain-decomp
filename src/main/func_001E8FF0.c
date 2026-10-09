/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001E8FF0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_001E9010(Iter* it) {
    it->p++;
    return it;
}

int func_001E9030(char* self) {
    return *(int*)(self + 0);
}

void func_001E9040(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001E9060(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int func_001E9070(Node* n) {
    return !(n->count == 0);
}
