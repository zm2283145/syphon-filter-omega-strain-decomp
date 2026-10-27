/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern void std_tree_pair_int_value_compare_find_intR(int*, int, int);
extern int std_tree_pair_int_value_compare_erase_tree(void*, int*);

/* Erase by key: pass a local copy of the key to the tree erase routine. */
int cAssocArray_int_netSystemField_Erase(void* map, int* key) {
    int k[1];

    k[0] = *key;
    return std_tree_pair_int_value_compare_erase_tree(map, k);
}

int cAssocArray_int_netSystemField_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Tree lookup wrapper returning the found iterator through out. */
void cAssocArray_int_netSystemField_Find(int* out) {
    int it[1];
    int a1, a2;

    std_tree_pair_int_value_compare_find_intR(it, a1, a2);
    *out = it[0];
}

void cAssocArray_int_netSystemField_End(Iter* out, Tree* t) {
    out->p = &t->header;
}
