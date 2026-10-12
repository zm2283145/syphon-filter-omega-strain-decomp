#pragma cplusplus on
#pragma inline_depth(8)
#pragma peephole off
#pragma optimization_level 3
#pragma opt_propagation on

#include "transfer_tree_mutations.h"

extern "C" {
char D_004BFBA8[] = "allocator.hh";
extern unsigned char D_00494200;
extern unsigned char D_00494208;
PendingTransferNode* func_00430A50(RbTree* tree, TransferTreeNode* parent,
                                  bool left, bool leftmost, const PendingTransferValue* value);
}

/* Unlink a pending-message node and advance the minimum iterator when needed. */
extern "C" void func_0042F2C0(RbTree* tree, PendingTransferIterator* position)
{
    transfer_tree_erase<D_004BFBA8>(tree, &position->node);
}

#pragma optimization_level 4
#pragma peephole on

/* Insert a pending-message ID or return its existing map entry. */
extern "C" void func_0042F400(PendingTransferInsertResult* result, RbTree* tree,
                             const PendingTransferValue* value)
{
    TransferTreeInsert<PendingTransferNode, PendingTransferValue, PendingTransferInsertResult,
                       func_00430A50, &D_00494200, &D_00494208>::insert(result, tree, value);
}
