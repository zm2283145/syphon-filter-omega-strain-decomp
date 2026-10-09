/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "NetObjectMgr_types.h"

extern void func_0042FC50(RbTree* tree, void* node);

/* Clears the tree: erases all nodes from the root down, then resets the header. */
void func_0042F4D0(RbTree* tree) {
    if (tree->root != 0) {
        func_0042FC50(tree, tree->root);
        tree->count = 0;
        tree->root = 0;
        tree->leftmost = &tree->root;
    }
}
