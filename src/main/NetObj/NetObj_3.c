/*
 * main/NetObj: 3 files, 003FC080-003FC200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FC080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "NetObj_types.h"

extern void std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_3(RbTree* tree, void* node);

/* Clears the tree: erases all nodes from the root down, then resets the header. */
void std_tree_pair_int_value_compare_cAllocator_pair_clear_void(RbTree* tree) {
    if (tree->root != 0) {
        std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_3(tree, tree->root);
        tree->count = 0;
        tree->root = 0;
        tree->leftmost = &tree->root;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003FC080 */

/* merge_units: begin func_003FC0C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_erase_iter.h"

extern "C" { char D_004BE3A0[] = "allocator.hh"; }
DEFINE_TREE_ERASE_ITER(std_tree_pair_int_value_compare_cAllocator_pair_erase, std_red_black_tree_1_balance_erase, D_004BE3A0, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_003FC0C0 */

/* merge_units: begin func_003FC200 */
#pragma push /* merge_units */
extern void std_tree_pair_int_value_compare_destroy_nodeP_2(RbTree* tree, void* node);

/* Clears the tree: erases all nodes from the root down, then resets the header. */
void NetMap_Clear(RbTree* tree) {
    if (tree->root != 0) {
        std_tree_pair_int_value_compare_destroy_nodeP_2(tree, tree->root);
        tree->count = 0;
        tree->root = 0;
        tree->leftmost = &tree->root;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003FC200 */
