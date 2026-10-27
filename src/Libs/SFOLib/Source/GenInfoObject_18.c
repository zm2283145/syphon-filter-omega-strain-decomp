/*
 * main/GenInfoObject: range (2 files, 0043B340-0043B410)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tree_insert_unique_u32.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "tree_erase3.h"
#pragma pop

/* merge_units: begin func_0043B340 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
static const unsigned int dat_00497590[2] = { 0x1, 0x0 };
static const unsigned int dat_00497598[2] = { 0x0, 0x0 };
TUNode* std_tree_pair_tGenInfoPtr_value_compare_insert_node_at(TUTree* t, TUNode* parent, bool left, bool first,
                 const unsigned int* v);
}
extern "C" void std_tree_pair_tGenInfoPtr_value_compare_insert_one(TUPair* ret, TUTree* t, const unsigned int* v)
{
    bool left = true;
    bool first = left;
    TUNode* y = 0;
    TUNode* parent = (TUNode*)&t->root;
    TUNode* x = t->root;
    while (x) {
        parent = x;
        if (*v < x->key) {
            x = x->left;
            left = true;
        } else {
            y = x;
            x = x->right;
            left = false;
            first = false;
        }
    }
    if (!y || y->key < *v) {
        ret->it = std_tree_pair_tGenInfoPtr_value_compare_insert_node_at(t, parent, left, first, v);
        ret->ok = (*(bool*)dat_00497590);
    } else {
        ret->it = y;
        ret->ok = (*(bool*)dat_00497598);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0043B340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0043B340 */

/* merge_units: begin func_0043B410 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_TREE_ERASE3(std_tree_pair_tGenInfoPtr_value_compare_destroy, 0xC, std_tree_pair_tGenInfoPtr_value_compare_alloc, std_tree_pair_tGenInfoPtr_value_compare_node_alloc, cAllocator_pair_tGenInfoPtr_destroy, cAllocator_node_deallocate_nodeP_uint_18, opDelete_nodeP_int_bool_charP_etc_18, D_004BFDB0, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0043B410 */
