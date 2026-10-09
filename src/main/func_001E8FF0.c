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

int func_001E9030(Word* w) {
    return w->value;
}

void func_001E9040(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001E9060(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int RelNode_HasChildren(Node* n) {
    return !(n->count == 0);
}
