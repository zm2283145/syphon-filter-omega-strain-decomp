/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(int*, int, int);

/* Tree iterator dereference: value stored at node +0x40. */
char* cAssocArray_cString16N_3_int_ConstIterator_opMul(Iter* it) {
    return (char*)it->p + 64;
}

int cAssocArray_cString16N_3_int_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void cAssocArray_cString16N_3_int_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Tree lookup wrapper returning the found iterator through out. */
void cAssocArray_cString16N_3_int_Find(int* out) {
    int it[1];
    int a1, a2;

    std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(it, a1, a2);
    *out = it[0];
}
