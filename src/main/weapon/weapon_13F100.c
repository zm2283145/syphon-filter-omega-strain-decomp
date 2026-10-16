/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern void Tree_Successor(Iter* it);

int func_0013F100(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_0013F120(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* ++it on a tree iterator. */
Iter* TreeIter_Increment(Iter* it) {
    Tree_Successor(it);
    return it;
}

/* Value part of the current tree node (+0x10). */
char* func_0013F160(Iter16* it) {
    return it->p + 16;
}

void func_0013F170(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

/* Build a (float, int) pair from pointers. */
FloatIntPair* func_0013F180(FloatIntPair* p, float* f, int* i) {
    p->f = *f;
    p->i = *i;
    return p;
}
