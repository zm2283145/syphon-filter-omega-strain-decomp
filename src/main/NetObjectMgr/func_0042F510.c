#pragma cplusplus on
#pragma inline_depth(8)
#pragma peephole off
#pragma optimization_level 3
#pragma opt_propagation on

#include "transfer_tree_mutations.h"

extern "C" {
char D_004BFB98[] = "allocator.hh";
extern unsigned char D_004941F0;
extern unsigned char D_004941F8;
TransferReferenceNode* std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_4(RbTree* tree, TransferTreeNode* parent,
                                    bool left, bool leftmost, const TransferReferenceValue* value);
}

/* Unlink a reference node and advance the minimum iterator when needed. */
extern "C" void std_tree_pair_int_value_compare_erase_tree_4(RbTree* tree, TransferReferenceIterator* position)
{
    transfer_tree_erase<D_004BFB98>(tree, &position->node);
}

#pragma optimization_level 4
#pragma peephole on

/* Insert a reference ID or return its existing map entry. */
extern "C" void std_tree_pair_int_value_compare_insert_one_pairR_3(TransferReferenceInsertResult* result, RbTree* tree,
                             const TransferReferenceValue* value)
{
    TransferTreeInsert<TransferReferenceNode, TransferReferenceValue, TransferReferenceInsertResult,
                       std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_4, &D_004941F0, &D_004941F8>::insert(result, tree, value);
}
