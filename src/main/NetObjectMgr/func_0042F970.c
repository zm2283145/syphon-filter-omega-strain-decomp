#pragma cplusplus on
#pragma inline_depth(8)

#include "transfer_tree_destroy.h"

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
