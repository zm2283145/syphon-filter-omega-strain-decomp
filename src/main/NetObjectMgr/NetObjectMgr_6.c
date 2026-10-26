/*
 * main/NetObjectMgr: 2 files, 004307B0-004307E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004307B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* std_tree_pair_int_value_compare_node_alloc_void_2(char* self) {
    return self + 4;
}

void cAllocator_pair_int_destroy_pairP_4(void) {
}

void* std_tree_pair_int_value_compare_alloc_void_2(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_004307B0 */

/* merge_units: begin func_004307E0 */
#pragma push /* merge_units */
typedef struct Node_7E0 {
    struct Node_7E0* left;
    struct Node_7E0* right;
    int color;
    int val;
} Node_7E0;

void* func_00430A40(void* t);
void* func_00430A20(void* t);
void func_00430A30(void* a, int* v);
void std_allocator_node_deallocate(void* a, Node_7E0* n, int count);
void operator_delete(void* p);
void std_tree_pair_short_value_compare_destroy(void* t, Node_7E0* n);

static inline void Leaf_7E0(void* t, Node_7E0* g)
{
    if (g->left)
        std_tree_pair_short_value_compare_destroy(t, g->left);
    if (g->right)
        std_tree_pair_short_value_compare_destroy(t, g->right);
    func_00430A30(func_00430A40(t), &g->val);
    std_allocator_node_deallocate(func_00430A20(t), g, 1);
}

static inline void Mid_7E0(void* t, Node_7E0* c)
{
    Node_7E0* g;
    if ((g = c->left) != 0)
        Leaf_7E0(t, g);
    if ((g = c->right) != 0)
        Leaf_7E0(t, g);
    func_00430A40(t);
    func_00430A20(t);
    operator_delete(c);
}

void std_tree_pair_short_value_compare_destroy(void* t, Node_7E0* n)
{
    Node_7E0* c;
    if ((c = n->left) != 0)
        Mid_7E0(t, c);
    if ((c = n->right) != 0)
        Mid_7E0(t, c);
    operator_delete(n);
}
#pragma pop /* merge_units */
/* merge_units: end func_004307E0 */
