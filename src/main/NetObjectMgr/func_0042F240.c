/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "NetObjectMgr_types.h"

extern void std_tree_pair_int_value_compare_destroy_nodeP_4(RbTree* tree, void* node);
extern void std_tree_pair_short_value_compare_destroy(RbTree* tree, void* node);

/* Clears the tree: erases all nodes from the root down, then resets the header. */
void std_tree_pair_short_value_compare_clear(RbTree* tree) {
    if (tree->root != 0) {
        std_tree_pair_short_value_compare_destroy(tree, tree->root);
        tree->count = 0;
        tree->root = 0;
        tree->leftmost = &tree->root;
    }
}

/* Clears the tree: erases all nodes from the root down, then resets the header. */
void std_tree_pair_int_value_compare_clear_void_3(RbTree* tree) {
    if (tree->root != 0) {
        std_tree_pair_int_value_compare_destroy_nodeP_4(tree, tree->root);
        tree->count = 0;
        tree->root = 0;
        tree->leftmost = &tree->root;
    }
}
