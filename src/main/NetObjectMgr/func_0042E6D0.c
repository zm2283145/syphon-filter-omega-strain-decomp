#pragma cplusplus on

#include "transfer_cleanup_types.h"
#include "alloc_guard.h"

extern "C" {
extern RbTree D_005826A0;
extern RbTree D_005826C0;
extern RbTree D_005826E0;
extern RbTree D_00582700;
extern RbTree D_00582720;
extern char D_004BFB00[];
void func_0042EB10(TransferObjectIterator* result, RbTree* tree);
TransferObjectIterator func_0042DF10(RbTree* tree);
void func_0042DF00(TransferObjectIterator* result, const TransferObjectIterator& source);
PendingTransferIterator func_0042EB00(RbTree* tree);
PendingTransferIterator func_0042D780(RbTree* tree);
void func_0042D770(PendingTransferIterator* result, const PendingTransferIterator& source);
void func_0042EAF0(TransferReferenceIterator* result, RbTree* tree);
TransferReferenceIterator func_0042DA20(RbTree* tree);
void func_0042DA10(TransferReferenceIterator* result, const TransferReferenceIterator& source);
void Tree_Successor(void* iterator);
void func_0042EFF0(RbTree* tree);
void func_0042F240(RbTree* tree);
void func_0042F280(RbTree* tree);
void func_0042F4D0(RbTree* tree);
void func_0042F720(RbTree* tree);
void Mem_Free(int pool, void* allocation, char* file, int line);
}

/* Release owned references and pending messages, then clear their transfer maps. */
extern "C" void func_0042E6D0(void)
{
    TransferObjectIterator object;
    PendingTransferIterator pending;
    TransferReferenceIterator reference;
    TransferObjectIterator objectEnd;
    PendingTransferIterator pendingBegin;
    PendingTransferIterator pendingEnd;
    TransferReferenceIterator referenceEnd;
    TransferObjectIterator objectBegin;
    func_0042EB10(&objectBegin, &D_005826A0);
    object.node = objectBegin.node;
    while (func_0042DF00(&objectEnd, func_0042DF10(&D_005826A0)),
           (object.node == objectEnd.node) ^ 1) {
        TransferObjectEntry* entry = object.node->entry;
        TransferReference* owned = entry->reference;
        {
            AllocGuard guard;
            Mem_Free(0, owned, D_004BFB00, 0x61);
        }
        {
            AllocGuard guard;
            Mem_Free(0, entry, D_004BFB00, 0x62);
        }
        Tree_Successor(&object);
    }
    func_0042EFF0(&D_005826A0);
    func_0042F240(&D_005826C0);
    func_0042D770(&pendingBegin, func_0042EB00(&D_005826E0));
    pending = pendingBegin;
    while (func_0042D770(&pendingEnd, func_0042D780(&D_005826E0)),
           (pending.node == pendingEnd.node) ^ 1) {
        TransferMessage* message = pending.node->message;
        {
            AllocGuard guard;
            message->~TransferMessage();
            Mem_Free(0, message, D_004BFB00, 0x6B);
        }
        Tree_Successor(&pending);
    }
    func_0042F280(&D_005826E0);
    TransferReferenceIterator referenceBegin;
    func_0042EAF0(&referenceBegin, &D_00582700);
    reference.node = referenceBegin.node;
    while (func_0042DA10(&referenceEnd, func_0042DA20(&D_00582700)),
           (reference.node == referenceEnd.node) ^ 1) {
        TransferReference* registered = reference.node->reference;
        {
            AllocGuard guard;
            Mem_Free(0, registered, D_004BFB00, 0x75);
        }
        Tree_Successor(&reference);
    }
    func_0042F4D0(&D_00582700);
    func_0042F720(&D_00582720);
}
