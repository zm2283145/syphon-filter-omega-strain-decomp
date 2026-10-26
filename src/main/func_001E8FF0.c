/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_001E9010(Iter* it) {
    it->p++;
    return it;
}

int func_001E9030(Word* w) {
    return w->value;
}

void cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001E9060(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int RelNode_HasChildren(Node* n) {
    return !(n->count == 0);
}
