/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern void Tree_Compare(int*, int, int);

/* Tree iterator dereference: value stored at node +0x40. */
char* func_0018C700(Iter* it) {
    return (char*)it->p + 64;
}

int func_0018C710(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_0018C730(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Tree lookup wrapper returning the found iterator through out. */
void func_0018C740(int* out) {
    int it[1];
    int a1, a2;

    Tree_Compare(it, a1, a2);
    *out = it[0];
}
