#pragma cplusplus on

#include "net_transfer_types.h"
#include "alloc_guard.h"

extern "C" {
extern RbTree D_00582700;
extern char D_00582730[];
extern char D_004BFB00[];
extern char D_004D9300[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_0042F650(TransferReferenceInsertResult* result, RbTree* tree,
                   const TransferReferenceValue* value);
void Event_Construct(TransferNotice* event, const void* descriptor);
void Event_Send(TransferNotice* event, cGOBJ* object, int flags);
void cMessage_dtor(TransferNotice* event, int flags);
void func_0042EEF0(TransferReferenceIterator* result, RbTree* tree, const GobjId* id);
TransferReferenceIterator func_0042DA20(RbTree* tree);
void func_0042DA10(TransferReferenceIterator* result, const TransferReferenceIterator& source);
void func_0042F510(RbTree* tree, TransferReferenceIterator* position);
}

static inline const GobjId& reference_id(cGOBJ* object, GobjId& invalid)
{
    if (object)
        return ((GobjEntry*)object)->id;
    invalid.word = -1;
    return invalid;
}

/* Register an object reference and send its notice unless the controller handles it. */
extern "C" void func_0042D790(cGOBJ* object)
{
    TransferReferenceInsertResult result;
    TransferReferenceValue value;
    TransferNotice notice;
    if (!((TransferObjectMethods*)object)->is_registered()) {
        TransferReference* reference;
        {
            AllocGuard guard;
            reference = (TransferReference*)Mem_Alloc(0, sizeof(TransferReference), D_004BFB00, 0x1BA);
        }
        GobjId invalid;
        if (reference) {
            reference->id.word = -1;
            reference->object = object;
            reference->id.word = reference_id(object, invalid).word;
        }
        value.id.word = ((GobjEntry*)object)->id.word;
        value.reference = reference;
        func_0042F650(&result, &D_00582700, &value);
        bool handled = false;
        if (object->attached && ((TransferController*)object->attached)->manages_transfer())
            handled = true;
        if (!handled) {
            Event_Construct(&notice, D_00582730);
            notice.vtable = D_004D9300;
            notice.enabled = 1;
            notice.action = 2;
            Event_Send(&notice, object, 1);
            notice.vtable = D_004D9300;
            cMessage_dtor(&notice, 0);
        }
    }
}

/* Release a registered object reference and erase its map entry. */
extern "C" void NetObjectMgr_Remove(cGOBJ* object)
{
    GobjId key;
    TransferReferenceIterator end;
    TransferReferenceIterator found;
    key.word = ((GobjEntry*)object)->id.word;
    func_0042EEF0(&found, &D_00582700, &key);
    TransferReferenceNode* node = found.node;
    func_0042DA10(&end, func_0042DA20(&D_00582700));
    if ((node == end.node) ^ 1) {
        TransferReference* reference = node->reference;
        {
            AllocGuard guard;
            Mem_Free(0, reference, D_004BFB00, 0x1A7);
        }
        TransferReferenceIterator position;
        position.node = node;
        func_0042F510(&D_00582700, &position);
    }
}
