/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "NetObjectMgr_types.h"

extern void std_tree_pair_int_value_compare_destroy_nodeP_3(RbTree* tree, void* node);

/* Clears the tree: erases all nodes from the root down, then resets the header. */
void func_0042F4D0(RbTree* tree) {
    if (tree->root != 0) {
        std_tree_pair_int_value_compare_destroy_nodeP_3(tree, tree->root);
        tree->count = 0;
        tree->root = 0;
        tree->leftmost = &tree->root;
    }
}
