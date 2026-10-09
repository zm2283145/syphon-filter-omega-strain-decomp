/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "humanIk_types.h"

extern void func_001DE2D0(IkIter* out, int a1, int a2);

/* Iterator equality. */
int func_001DB940(IkIter* a, IkIter* b) {
    return (unsigned int)(a->node ^ b->node) < 1u;
}

void func_001DB960(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Forwards to func_001DE2D0 through a temporary iterator. */
void func_001DB970(IkIter* out, int a1, int a2) {
    IkIter tmp;

    func_001DE2D0(&tmp, a1, a2);
    out->node = tmp.node;
}
