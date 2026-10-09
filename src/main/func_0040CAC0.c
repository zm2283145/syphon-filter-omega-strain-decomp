/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern void func_0040CD10(Tree* t, int root);

/* Erases every node of the tree and resets it to empty. */
void func_0040CAC0(Tree* t) {
    if (t->header != 0) {
        func_0040CD10(t, t->header);
        t->unk0 = 0;
        t->header = 0;
        t->leftmost = &t->header;
    }
}
