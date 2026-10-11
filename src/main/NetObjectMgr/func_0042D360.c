#pragma cplusplus on

#include "transfer_cleanup_types.h"
#include "alloc_guard.h"

extern "C" {
extern RbTree D_005826E0;
extern char D_004BFB00[];
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
cGOBJ* Object_LookupById(const GobjId* id);
void func_0042EE70(PendingTransferIterator* result, RbTree* tree, const GobjId* id);
PendingTransferIterator func_0042D780(RbTree* tree);
void func_0042D770(PendingTransferIterator* result, const PendingTransferIterator& source);
void func_0042F2C0(RbTree* tree, const PendingTransferIterator& position);
int Transport_Send(unsigned int id, TransferMessage* message, int flags, short peer);
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_0042D790(cGOBJ* object);
void func_00436C00(int* shared);
void func_00436BA0(int* shared, short flags);
}

static inline PendingTransferController* controller(cGOBJ* object)
{
    return (PendingTransferController*)object->attached;
}

static inline void release_message(TransferMessage* message, int line)
{
    message->~TransferMessage();
    Mem_Free(0, message, D_004BFB00, line);
}

static inline bool needs_transfer_update(cGOBJ* object)
{
    return object->unk2D != 0 && object->unk2C != 0 && !(object->unk2E != 0);
}

static inline int is_host(void)
{
    return D_005721C8 ? D_005721C0 : 1;
}

static inline void assign_end(PendingTransferIterator* result, RbTree* tree)
{
    func_0042D770(result, func_0042D780(tree));
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
extern "C" void func_0042D360(const GobjId* id, int peer)
{
    int shared;
    GobjId key;
    PendingTransferIterator end;
    PendingTransferIterator found;
    cGOBJ* object = Object_LookupById(id);
    if (object && object->attached && controller(object)->is_ready()) {
        key.word = id->word;
        func_0042EE70(&found, &D_005826E0, &key);
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
            func_0042D790(object);
        }
    } else {
        func_00436C00(&shared);
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
        func_00436BA0(&shared, -1);
    }
}
