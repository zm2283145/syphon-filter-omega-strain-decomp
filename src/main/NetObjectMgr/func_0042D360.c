#pragma cplusplus on

#include "transfer_cleanup_types.h"
#include "alloc_guard.h"

extern "C" {
extern RbTree D_005826E0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
cGOBJ* Object_LookupById(const GobjId* id);
void ObjMap_Find_42EE70(PendingTransferIterator* result, RbTree* tree, const GobjId* id);
PendingTransferIterator std_map_int_cMessagePtr_end(RbTree* tree);
void cAssocArray_int_cMessagePtr_Iterator_ctor(PendingTransferIterator* result, const PendingTransferIterator& source);
void func_0042F2C0(RbTree* tree, const PendingTransferIterator& position);
int Transport_Send(unsigned int id, TransferMessage* message, int flags, short peer);
void Mem_Free(int pool, void* allocation, char* file, int line);
void cNetObjectMgr_TerrainActivation(cGOBJ* object);
void cNPCInfoObject_ctor(int* shared);
void cNPCInfoObject_dtor(int* shared, short flags);
}

static inline PendingTransferController* controller(cGOBJ* object)
{
    return (PendingTransferController*)object->attached;
}

static inline void release_message(TransferMessage* message, int line)
{
    message->~TransferMessage();
    Mem_Free(0, message, "NetObjectMgr.cc", line);
}

static inline bool needs_transfer_update(cGOBJ* object)
{
    return object->unk2D != 0 && object->unk2C != 0 && !(object->unk2E != 0);
}

static inline int is_host(void)
{
    return g_IsMultiplayer ? D_005721C0 : 1;
}

static inline void assign_end(PendingTransferIterator* result, RbTree* tree)
{
    cAssocArray_int_cMessagePtr_Iterator_ctor(result, std_map_int_cMessagePtr_end(tree));
}

static inline void pending_end(PendingTransferIterator* result)
{
    assign_end(result, &D_005826E0);
}

static inline void erase_pending(PendingTransferNode* node)
{
    PendingTransferIterator position;
    position.node = node;
    func_0042F2C0(&D_005826E0, position);
}

/* Send queued or newly created transfer state, then update the object's transfer status. */
extern "C" void cNetObjectMgr_TransferRequest(const GobjId* id, int peer)
{
    int shared;
    GobjId key;
    PendingTransferIterator end;
    PendingTransferIterator found;
    cGOBJ* object = Object_LookupById(id);
    if (object && object->attached && controller(object)->is_ready()) {
        key.word = id->word;
        ObjMap_Find_42EE70(&found, &D_005826E0, &key);
        PendingTransferNode* node = found.node;
        pending_end(&end);
        if ((node == end.node) ^ 1) {
            TransferMessage* message = node->message;
            Transport_Send(id->word, message, 0, (short)peer);
            {
                AllocGuard guard;
                release_message(message, 0x202);
            }
            erase_pending(node);
        } else if (object && controller(object)->is_ready() &&
                   controller(object)->can_create_message()) {
            TransferMessage* message = controller(object)->create_message();
            if (message)
                Transport_Send(id->word, message, 0, (short)peer);
            {
                AllocGuard guard;
                release_message(message, 0x211);
            }
        }
        if (needs_transfer_update(object)) {
            controller(object)->set_transferring(1);
            ((TransferObjectMethods*)object)->set_state(0);
            cNetObjectMgr_TerrainActivation(object);
        }
    } else {
        cNPCInfoObject_ctor(&shared);
        if (is_host()) {
            TransferMessage* message = controller(object)->create_message();
            if (message) {
                if (!(short)peer)
                    controller(object)->apply_message(message);
                else
                    Transport_Send(id->word, message, 0, (short)peer);
            }
            {
                AllocGuard guard;
                release_message(message, 0x22F);
            }
        }
        cNPCInfoObject_dtor(&shared, -1);
    }
}
