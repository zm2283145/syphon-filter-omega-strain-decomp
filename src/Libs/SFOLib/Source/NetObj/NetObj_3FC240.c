/*
 * main/NetObj: range (2 files, 003FC240-003FC520)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tree_erase3.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "tstr_types.h"
#pragma pop

/* merge_units: begin func_003FC240 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_TREE_ERASE3(std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_3, 0xC, func_003FC810, func_003FC7F0, cAllocator_pair_int_destroy_pairP_2, cAllocator_node_deallocate_nodeP_uint_7, opDelete_nodeP_int_bool_charP_etc_6, D_004BE3A0, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_003FC240 */

/* merge_units: begin func_003FC520 */
#pragma push /* merge_units */
#pragma cplusplus on
#ifndef TREE_INSERT_V8X_H
#define TREE_INSERT_V8X_H

/*
 * Red-black tree node insert for an 8-byte value (node: left, right,
 * parent|color, value at +0xC; tree: count, root, -, leftmost): count
 * overflow check, allocate the 0x14-byte node under the allocator guard,
 * placement-copy the value, link it under parent, bump the count and
 * rebalance (rebalanceFn). VT is TIValueFI (float, int) or TIValueII.
 * C++ only (#pragma cplusplus on before including).
 */

struct TIValueFI { float f; int i; };
struct TIValueII { int a; int b; };

#define DEFINE_TREE_INSERT_V8X(name, VT, errSym, allocFile, allocLine, rebalanceFn) \
    struct name##_Node { name##_Node* left; name##_Node* right; unsigned int parentAndColor; VT value; }; \
    struct name##_Tree { unsigned int count; name##_Node* root; int pad; name##_Node* leftmost; }; \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    void rebalanceFn(void* node, void* root);                                 \
    }                                                                         \
    extern "C" name##_Node* name(name##_Tree* tree, name##_Node* parent,      \
                                 int left, int first, const VT* src)          \
    {                                                                         \
        if (tree->count > 0xFFFFFFFFU - 1) {                                  \
            Libc_Fprintf(D_00489738->stream, errSym);                        \
            Libc_Abort();                                                  \
        }                                                                     \
        name##_Node* node = (name##_Node*)TStr_Alloc(sizeof(name##_Node), allocFile, (allocLine)); \
        VT* v = &node->value;                                                 \
        if (v)                                                                \
            *v = *src;                                                        \
        node->right = 0;                                                      \
        node->left = 0;                                                       \
        node->parentAndColor = (unsigned int)parent | (node->parentAndColor & 1); \
        if (left)                                                             \
            parent->left = node;                                              \
        else                                                                  \
            parent->right = node;                                             \
        tree->count++;                                                        \
        rebalanceFn(node, tree->root);                                        \
        if (first)                                                            \
            tree->leftmost = node;                                            \
        return node;                                                          \
    }

#endif /* TREE_INSERT_V8X_H */
struct TIV_003FC520 { int w0; int w1; int w2; };

extern "C" {
char D_004BE370[] = "tree::insert length error\n";
}
extern "C" {
char D_004BE390[] = "allocator.hh";
}
DEFINE_TREE_INSERT_V8X(std_tree_pair_int_value_compare_cAllocator_pair_insert_node_at_nodeP_bool_bool_pairR_3, TIV_003FC520, D_004BE370, D_004BE390, 0x5C, std_red_black_tree_1_balance_insert)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FC520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FC520 */
