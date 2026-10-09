/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "materialProperties_types.h"

extern void func_004097A0(MatIter* out, int a1, int a2);

/* &v->data[i] */
MaterialProps* func_00409480(MaterialVec* v, int i) {
    return &v->data[i];
}

/* Iterator dereference. */
int* func_004094A0(MatIter* it) {
    return &it->node->value;
}

int func_004094B0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_004094D0(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Forwards to func_004097A0 through a temporary iterator. */
void func_004094E0(MatIter* out, int a1, int a2) {
    MatIter tmp;

    func_004097A0(&tmp, a1, a2);
    out->node = tmp.node;
}

int* func_00409510(int* self, int value) {
    *self = value;
    return self;
}
