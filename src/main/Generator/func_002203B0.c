/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "Generator_types.h"

Word* func_002203B0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int func_002203C0(GenListPos* a, GenListPos* b) {
    return 0u < (unsigned int)((int)a->node ^ (int)b->node);
}

void func_002203E0(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Iterator increment. */
GenListPos* func_002203F0(GenListPos* it) {
    it->node = it->node->next;
    return it;
}
