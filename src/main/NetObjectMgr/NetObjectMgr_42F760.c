/*
 * main/NetObjectMgr: range (2 files, 0042F760-0042F970)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "transfer_tree_mutations.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "transfer_tree_destroy.h"
#pragma pop

/* merge_units: begin func_0042F760 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#pragma peephole off
#pragma optimization_level 3
#pragma opt_propagation on

extern "C" {
char D_004BFB88[] = "allocator.hh";
extern unsigned char D_004941E0;
extern unsigned char D_004941E8;
TransferTimerNode* std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_5(RbTree* tree, TransferTreeNode* parent,
                                bool left, bool leftmost, const TransferTimerValue* value);
}

/* Unlink a timer node and advance the minimum iterator when needed. */
extern "C" void std_tree_pair_int_value_compare_erase_tree_5(RbTree* tree, TransferTimerIterator* position)
{
    transfer_tree_erase<D_004BFB88>(tree, &position->node);
}

#pragma optimization_level 4
#pragma peephole on

/* Insert a timer ID or return its existing map entry. */
extern "C" void std_tree_pair_int_value_compare_insert_one_pairR_4(TransferInsertResult* result, RbTree* tree,
                             const TransferTimerValue* value)
{
    TransferTreeInsert<TransferTimerNode, TransferTimerValue, TransferInsertResult,
                       std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_5, &D_004941E0, &D_004941E8>::insert(result, tree, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0042F760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0042F760 */

/* merge_units: begin func_0042F970 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

extern "C" {
extern char D_004BFB88[];
void func_0042F970(RbTree* tree, TransferTreeNode* node);
void std_tree_pair_int_value_compare_destroy_nodeP_3(RbTree* tree, TransferTreeNode* node);
void std_tree_pair_int_value_compare_destroy_nodeP_4(RbTree* tree, TransferTreeNode* node);
void std_tree_pair_int_value_compare_destroy_nodeP_5(RbTree* tree, TransferTreeNode* node);
void* std_tree_pair_int_value_compare_alloc_void_4(RbTree* tree);
void cAllocator_pair_int_destroy_pairP_6(void* allocator, GobjId* value);
void* std_tree_pair_int_value_compare_node_alloc_void_4(RbTree* tree);
void cAllocator_node_deallocate_nodeP_uint_16(void* allocator, TransferTreeNode* node, int count);
void opDelete_nodeP_int_bool_charP_etc_16(TransferTreeNode* node, int pool, int flags, char* file, int line);

extern char D_004BFB98[];
void* std_tree_pair_int_value_compare_alloc_void_3(RbTree* tree);
void cAllocator_pair_int_destroy_pairP_5(void* allocator, GobjId* value);
void* std_tree_pair_int_value_compare_node_alloc_void_3(RbTree* tree);
void cAllocator_node_deallocate_nodeP_uint_15(void* allocator, TransferTreeNode* node, int count);
void opDelete_nodeP_int_bool_charP_etc_15(TransferTreeNode* node, int pool, int flags, char* file, int line);

extern char D_004BFBA8[];
void* std_tree_pair_short_value_compare_alloc(RbTree* tree);
void std_allocator_pair_short_destroy(void* allocator, GobjId* value);
void* std_tree_pair_short_value_compare_node_alloc(RbTree* tree);
void func_00430C70(void* allocator, TransferTreeNode* node, int count);
void opDelete_nodeP_int_bool_charP_etc_14(TransferTreeNode* node, int pool, int flags, char* file, int line);

extern char D_004BFBB8[];
void* std_tree_pair_int_value_compare_alloc_void_2(RbTree* tree);
void cAllocator_pair_int_destroy_pairP_4(void* allocator, GobjId* value);
void* std_tree_pair_int_value_compare_node_alloc_void_2(RbTree* tree);
void cAllocator_node_deallocate_nodeP_uint_14(void* allocator, TransferTreeNode* node, int count);
void opDelete_nodeP_int_bool_charP_etc_13(TransferTreeNode* node, int pool, int flags, char* file, int line);
}

/* Destroy timer-map nodes in postorder through the original allocator layers. */
extern "C" void func_0042F970(RbTree* tree, TransferTreeNode* node)
{
    TransferTreeDestroy<func_0042F970, std_tree_pair_int_value_compare_alloc_void_4, cAllocator_pair_int_destroy_pairP_6, std_tree_pair_int_value_compare_node_alloc_void_4,
                        cAllocator_node_deallocate_nodeP_uint_16, opDelete_nodeP_int_bool_charP_etc_16, D_004BFB88>::destroy(tree, node);
}

/* Destroy reference-map nodes without releasing the separately owned references. */
extern "C" void std_tree_pair_int_value_compare_destroy_nodeP_3(RbTree* tree, TransferTreeNode* node)
{
    TransferTreeDestroy<std_tree_pair_int_value_compare_destroy_nodeP_3, std_tree_pair_int_value_compare_alloc_void_3, cAllocator_pair_int_destroy_pairP_5, std_tree_pair_int_value_compare_node_alloc_void_3,
                        cAllocator_node_deallocate_nodeP_uint_15, opDelete_nodeP_int_bool_charP_etc_15, D_004BFB98>::destroy(tree, node);
}

/* Destroy pending-message map nodes after their messages have been released. */
extern "C" void std_tree_pair_int_value_compare_destroy_nodeP_4(RbTree* tree, TransferTreeNode* node)
{
    TransferTreeDestroy<std_tree_pair_int_value_compare_destroy_nodeP_4, std_tree_pair_short_value_compare_alloc, std_allocator_pair_short_destroy, std_tree_pair_short_value_compare_node_alloc,
                        func_00430C70, opDelete_nodeP_int_bool_charP_etc_14, D_004BFBA8>::destroy(tree, node);
}

/* Destroy owned-object map nodes after the entry allocations have been released. */
extern "C" void std_tree_pair_int_value_compare_destroy_nodeP_5(RbTree* tree, TransferTreeNode* node)
{
    TransferTreeDestroy<std_tree_pair_int_value_compare_destroy_nodeP_5, std_tree_pair_int_value_compare_alloc_void_2, cAllocator_pair_int_destroy_pairP_4, std_tree_pair_int_value_compare_node_alloc_void_2,
                        cAllocator_node_deallocate_nodeP_uint_14, opDelete_nodeP_int_bool_charP_etc_13, D_004BFBB8>::destroy(tree, node);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0042F970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0042F970 */
