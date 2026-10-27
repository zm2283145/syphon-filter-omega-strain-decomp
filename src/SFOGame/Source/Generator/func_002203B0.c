/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "Generator_types.h"

Word* cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_3(GenListPos* a, GenListPos* b) {
    return 0u < (unsigned int)((int)a->node ^ (int)b->node);
}

void cLList_cSafePtr_cGOBJ_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Iterator increment. */
GenListPos* cLListIterator_cSafePtr_cGOBJ_opInc(GenListPos* it) {
    it->node = it->node->next;
    return it;
}
