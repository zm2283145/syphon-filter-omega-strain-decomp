/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2(int*, int, int);
extern int std_vector_imp_cTimedEvent_insert(PtrVec*, char*, int, int);

/* Tree iterator dereference: value stored at node +0x30. */
char* cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(Iter* it) {
    return (char*)it->p + 48;
}

/* Tree lookup wrapper returning the found iterator through out. */
void cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(int* out) {
    int it[1];
    int a1, a2;

    std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2(it, a1, a2);
    *out = it[0];
}

/* push_back for a vector of 20-byte elements. */
int cArray_cTimedEvent_PushBackActual(PtrVec* v, int value) {
    char* data = (char*)v->data;
    int count = v->count;

    return std_vector_imp_cTimedEvent_insert(v, data + count * 20, 1, value);
}

int* cSkaAnimEvent_ctor_char_cSystemR(int* pair, int first, int second) {
    pair[0] = first;
    pair[1] = second;
    return pair;
}
