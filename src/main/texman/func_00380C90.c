/*
 * Matched functions (byte-identical with the retail executable).
 * List iterator helpers.
 */

#include "types.h"
#include "texman_types.h"

/* Iterator inequality. */
int func_00380C90(TexListIter* a, TexListIter* b) {
    return a->node != b->node;
}

void func_00380CB0(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Post-increment: returns the current node and advances it. */
void func_00380CC0(TexListIter* out, TexListIter* it) {
    TexListNode* node = it->node;

    it->node = node->next;
    out->node = node;
}
