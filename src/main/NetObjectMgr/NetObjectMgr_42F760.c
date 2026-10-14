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
void func_0042FC50(RbTree* tree, TransferTreeNode* node);
void func_0042FF30(RbTree* tree, TransferTreeNode* node);
void func_00430210(RbTree* tree, TransferTreeNode* node);
void* func_00431310(RbTree* tree);
void func_00431300(void* allocator, GobjId* value);
void* func_004312F0(RbTree* tree);
void func_00431250(void* allocator, TransferTreeNode* node, int count);
void func_004311A0(TransferTreeNode* node, int pool, int flags, char* file, int line);

extern char D_004BFB98[];
void* func_00431020(RbTree* tree);
void func_00431010(void* allocator, GobjId* value);
void* func_00431000(RbTree* tree);
void func_00430F60(void* allocator, TransferTreeNode* node, int count);
void func_00430EB0(TransferTreeNode* node, int pool, int flags, char* file, int line);

extern char D_004BFBA8[];
void* func_00430D30(RbTree* tree);
void func_00430D20(void* allocator, GobjId* value);
void* func_00430D10(RbTree* tree);
void func_00430C70(void* allocator, TransferTreeNode* node, int count);
void func_00430BC0(TransferTreeNode* node, int pool, int flags, char* file, int line);

extern char D_004BFBB8[];
void* func_004307D0(RbTree* tree);
void func_004307C0(void* allocator, GobjId* value);
void* func_004307B0(RbTree* tree);
void func_00430710(void* allocator, TransferTreeNode* node, int count);
void func_00430660(TransferTreeNode* node, int pool, int flags, char* file, int line);
}

/* Destroy timer-map nodes in postorder through the original allocator layers. */
extern "C" void func_0042F970(RbTree* tree, TransferTreeNode* node)
{
    TransferTreeDestroy<func_0042F970, func_00431310, func_00431300, func_004312F0,
                        func_00431250, func_004311A0, D_004BFB88>::destroy(tree, node);
}

/* Destroy reference-map nodes without releasing the separately owned references. */
extern "C" void func_0042FC50(RbTree* tree, TransferTreeNode* node)
{
    TransferTreeDestroy<func_0042FC50, func_00431020, func_00431010, func_00431000,
                        func_00430F60, func_00430EB0, D_004BFB98>::destroy(tree, node);
}

/* Destroy pending-message map nodes after their messages have been released. */
extern "C" void func_0042FF30(RbTree* tree, TransferTreeNode* node)
{
    TransferTreeDestroy<func_0042FF30, func_00430D30, func_00430D20, func_00430D10,
                        func_00430C70, func_00430BC0, D_004BFBA8>::destroy(tree, node);
}

/* Destroy owned-object map nodes after the entry allocations have been released. */
extern "C" void func_00430210(RbTree* tree, TransferTreeNode* node)
{
    TransferTreeDestroy<func_00430210, func_004307D0, func_004307C0, func_004307B0,
                        func_00430710, func_00430660, D_004BFBB8>::destroy(tree, node);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0042F970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0042F970 */
