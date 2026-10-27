/*
 * Libs/SFOLib/Source/NetObjectMgr: 1 file, 0042D360
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042D360 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "transfer_cleanup_types.h"
#include "alloc_guard.h"

extern "C" {
extern RbTree D_005826E0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
cGOBJ* nGobjManager_LookupGOBJ_cObjectIdR(const GobjId* id);
void std_tree_pair_int_value_compare_find_uintR(PendingTransferIterator* result, RbTree* tree, const GobjId* id);
PendingTransferIterator std_map_int_cMessagePtr_end(RbTree* tree);
void cAssocArray_int_cMessagePtr_Iterator_ctor(PendingTransferIterator* result, const PendingTransferIterator& source);
void func_0042F2C0(RbTree* tree, const PendingTransferIterator& position);
int cNetObj_SendMessage_int_cMessageR_int_int(unsigned int id, TransferMessage* message, int flags, short peer);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
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
    cMemMan_Deallocate(0, message, "NetObjectMgr.cc", line);
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
    cGOBJ* object = nGobjManager_LookupGOBJ_cObjectIdR(id);
    if (object && object->attached && controller(object)->is_ready()) {
        key.word = id->word;
        std_tree_pair_int_value_compare_find_uintR(&found, &D_005826E0, &key);
        PendingTransferNode* node = found.node;
        pending_end(&end);
        if ((node == end.node) ^ 1) {
            TransferMessage* message = node->message;
            cNetObj_SendMessage_int_cMessageR_int_int(id->word, message, 0, (short)peer);
            {
                AllocGuard guard;
                release_message(message, 0x202);
            }
            erase_pending(node);
        } else if (object && controller(object)->is_ready() &&
                   controller(object)->can_create_message()) {
            TransferMessage* message = controller(object)->create_message();
            if (message)
                cNetObj_SendMessage_int_cMessageR_int_int(id->word, message, 0, (short)peer);
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
                    cNetObj_SendMessage_int_cMessageR_int_int(id->word, message, 0, (short)peer);
            }
            {
                AllocGuard guard;
                release_message(message, 0x22F);
            }
        }
        cNPCInfoObject_dtor(&shared, -1);
    }
}
static inline void merge_flush_func_0042D360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042D360 */
