#pragma cplusplus on

#include "transfer_cleanup_types.h"
#include "alloc_guard.h"

extern "C" {
extern RbTree D_005826A0;
extern RbTree D_00582700;
extern char D_004BFB00[];
void func_0042EDF0(TransferObjectIterator* result, RbTree* tree, const GobjId* id);
TransferObjectIterator func_0042DF10(RbTree* tree);
void func_0042DF00(TransferObjectIterator* result, const TransferObjectIterator& source);
void func_0042F030(RbTree* tree, TransferObjectIterator* position);
void func_0042EEF0(TransferReferenceIterator* result, RbTree* tree, const GobjId* id);
TransferReferenceIterator func_0042DA20(RbTree* tree);
void func_0042DA10(TransferReferenceIterator* result, const TransferReferenceIterator& source);
void func_0042F510(RbTree* tree, TransferReferenceIterator* position);
void Mem_Free(int pool, void* allocation, char* file, int line);
}

static inline void erase_object(TransferObjectNode* node)
{
    TransferObjectIterator position;
    position.node = node;
    func_0042F030(&D_005826A0, &position);
}

static inline void assign_end(TransferObjectIterator* result, RbTree* tree)
{
    func_0042DF00(result, func_0042DF10(tree));
}

static inline void assign_end(TransferReferenceIterator* result, RbTree* tree)
{
    func_0042DA10(result, func_0042DA20(tree));
}

static inline void object_end(TransferObjectIterator* result)
{
    assign_end(result, &D_005826A0);
}

static inline void reference_end(TransferReferenceIterator* result)
{
    assign_end(result, &D_00582700);
}

static inline void erase_reference(TransferReferenceNode* node)
{
    TransferReferenceIterator position;
    position.node = node;
    func_0042F510(&D_00582700, &position);
}

/* Remove the owned entry, then release its separately registered reference. */
extern "C" void NetObjectMgr_Erase(const GobjId* id)
{
    GobjId key;
    TransferObjectIterator end;
    GobjId referenceKey;
    TransferReferenceIterator referenceEnd;
    TransferObjectIterator found;
    key.word = id->word;
    func_0042EDF0(&found, &D_005826A0, &key);
    TransferObjectNode* node = found.node;
    object_end(&end);
    if ((node == end.node) ^ 1) {
        TransferObjectEntry* entry = node->entry;
        erase_object(node);
        TransferReference* reference = entry->reference;
        {
            AllocGuard guard;
            Mem_Free(0, reference, D_004BFB00, 0x119);
        }
        {
            AllocGuard guard;
            Mem_Free(0, entry, D_004BFB00, 0x11A);
        }
        TransferReferenceIterator referenceFound;
        referenceKey.word = id->word;
        func_0042EEF0(&referenceFound, &D_00582700, &referenceKey);
        TransferReferenceNode* referenceNode = referenceFound.node;
        reference_end(&referenceEnd);
        if ((referenceNode == referenceEnd.node) ^ 1) {
            TransferReference* registered = referenceNode->reference;
            {
                AllocGuard guard;
                Mem_Free(0, registered, D_004BFB00, 0x121);
            }
            erase_reference(referenceNode);
        }
    }
}
