/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "NetObjectMgr_types.h"

extern void func_0042F970(RbTree* tree, void* node);

/* Clears the tree: erases all nodes from the root down, then resets the header. */
void std_tree_pair_int_value_compare_clear_void_5(RbTree* tree) {
    if (tree->root != 0) {
        func_0042F970(tree, tree->root);
        tree->count = 0;
        tree->root = 0;
        tree->leftmost = &tree->root;
    }
}
