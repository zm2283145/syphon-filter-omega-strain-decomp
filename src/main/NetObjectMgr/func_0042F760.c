#pragma cplusplus on
#pragma inline_depth(8)
#pragma peephole off
#pragma optimization_level 3
#pragma opt_propagation on

#include "transfer_tree_mutations.h"

extern "C" {
char D_004BFB88[] = "allocator.hh";
extern unsigned char D_004941E0;
extern unsigned char D_004941E8;
TransferTimerNode* func_00431030(RbTree* tree, TransferTreeNode* parent,
                                bool left, bool leftmost, const TransferTimerValue* value);
}

/* Unlink a timer node and advance the minimum iterator when needed. */
extern "C" void func_0042F760(RbTree* tree, TransferTimerIterator* position)
{
    transfer_tree_erase<D_004BFB88>(tree, &position->node);
}

#pragma optimization_level 4
#pragma peephole on

/* Insert a timer ID or return its existing map entry. */
extern "C" void func_0042F8A0(TransferInsertResult* result, RbTree* tree,
                             const TransferTimerValue* value)
{
    TransferTreeInsert<TransferTimerNode, TransferTimerValue, TransferInsertResult,
                       func_00431030, &D_004941E0, &D_004941E8>::insert(result, tree, value);
}
