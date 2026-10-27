/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "humanIk_types.h"

extern void std_tree_pair_cWeaponSlotPair_value_compare_find(IkIter* out, int a1, int a2);

/* Iterator equality. */
int cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_opEq(IkIter* a, IkIter* b) {
    return (unsigned int)(a->node ^ b->node) < 1u;
}

void cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Forwards to std_tree_pair_cWeaponSlotPair_value_compare_find through a temporary iterator. */
void cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Find(IkIter* out, int a1, int a2) {
    IkIter tmp;

    std_tree_pair_cWeaponSlotPair_value_compare_find(&tmp, a1, a2);
    out->node = tmp.node;
}
