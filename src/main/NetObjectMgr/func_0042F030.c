#pragma cplusplus on
#pragma inline_depth(8)
#pragma peephole off
#pragma optimization_level 3
#pragma opt_propagation on

#include "transfer_tree_mutations.h"

extern "C" {
char D_004BFBB8[] = "allocator.hh";
extern unsigned char D_00494210;
extern unsigned char D_00494218;
TransferObjectNode* std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_3(RbTree* tree, TransferTreeNode* parent,
                                 bool left, bool leftmost, const TransferObjectValue* value);
}

/* Unlink an owned-object node and advance the minimum iterator when needed. */
extern "C" void std_tree_pair_int_value_compare_erase_tree_3(RbTree* tree, TransferObjectIterator* position)
{
    transfer_tree_erase<D_004BFBB8>(tree, &position->node);
}

#pragma optimization_level 4
#pragma peephole on

/* Insert an owned-object ID or return its existing map entry. */
extern "C" void std_tree_pair_int_value_compare_insert_one_pairR_2(TransferObjectInsertResult* result, RbTree* tree,
                             const TransferObjectValue* value)
{
    TransferTreeInsert<TransferObjectNode, TransferObjectValue, TransferObjectInsertResult,
                       std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_3, &D_00494210, &D_00494218>::insert(result, tree, value);
}
