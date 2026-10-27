/*
 * main/NetObjectMgr: 3 files, 0042DF20-0042E6D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042DF20 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "transfer_cleanup_types.h"
#include "alloc_guard.h"

extern "C" {
extern RbTree D_005826A0;
extern RbTree D_00582700;
extern char D_004BFB00[];
void std_tree_pair_int_value_compare_find_intR_3(TransferObjectIterator* result, RbTree* tree, const GobjId* id);
TransferObjectIterator std_map_int_tNetObjectPtr_end(RbTree* tree);
void cAssocArray_int_tNetObjectPtr_Iterator_ctor(TransferObjectIterator* result, const TransferObjectIterator& source);
void std_tree_pair_int_value_compare_erase_tree_3(RbTree* tree, TransferObjectIterator* position);
void std_tree_pair_int_value_compare_find_uintR_2(TransferReferenceIterator* result, RbTree* tree, const GobjId* id);
TransferReferenceIterator std_map_int_tNetActivateTerrainObjectPtr_end(RbTree* tree);
void cAssocArray_int_tNetActivateTerrainObjectPtr_Iterator_ctor(TransferReferenceIterator* result, const TransferReferenceIterator& source);
void std_tree_pair_int_value_compare_erase_tree_4(RbTree* tree, TransferReferenceIterator* position);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}

static inline void erase_object(TransferObjectNode* node)
{
    TransferObjectIterator position;
    position.node = node;
    std_tree_pair_int_value_compare_erase_tree_3(&D_005826A0, &position);
}

static inline void assign_end(TransferObjectIterator* result, RbTree* tree)
{
    cAssocArray_int_tNetObjectPtr_Iterator_ctor(result, std_map_int_tNetObjectPtr_end(tree));
}

static inline void assign_end(TransferReferenceIterator* result, RbTree* tree)
{
    cAssocArray_int_tNetActivateTerrainObjectPtr_Iterator_ctor(result, std_map_int_tNetActivateTerrainObjectPtr_end(tree));
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
    std_tree_pair_int_value_compare_erase_tree_4(&D_00582700, &position);
}

/* Remove the owned entry, then release its separately registered reference. */
extern "C" void cNetObjectMgr_Delete(const GobjId* id)
{
    GobjId key;
    TransferObjectIterator end;
    GobjId referenceKey;
    TransferReferenceIterator referenceEnd;
    TransferObjectIterator found;
    key.word = id->word;
    std_tree_pair_int_value_compare_find_intR_3(&found, &D_005826A0, &key);
    TransferObjectNode* node = found.node;
    object_end(&end);
    if ((node == end.node) ^ 1) {
        TransferObjectEntry* entry = node->entry;
        erase_object(node);
        TransferReference* reference = entry->reference;
        {
            AllocGuard guard;
            cMemMan_Deallocate(0, reference, D_004BFB00, 0x119);
        }
        {
            AllocGuard guard;
            cMemMan_Deallocate(0, entry, D_004BFB00, 0x11A);
        }
        TransferReferenceIterator referenceFound;
        referenceKey.word = id->word;
        std_tree_pair_int_value_compare_find_uintR_2(&referenceFound, &D_00582700, &referenceKey);
        TransferReferenceNode* referenceNode = referenceFound.node;
        reference_end(&referenceEnd);
        if ((referenceNode == referenceEnd.node) ^ 1) {
            TransferReference* registered = referenceNode->reference;
            {
                AllocGuard guard;
                cMemMan_Deallocate(0, registered, D_004BFB00, 0x121);
            }
            erase_reference(referenceNode);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0042DF20 */

/* merge_units: begin func_0042E180 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off

struct ActivateNotice {
    void* vtable;
    int header[6];
    unsigned int flags;
    unsigned char state;
    char pad21[0xB];
    int target;
};

struct ActivateController {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual bool can_create_message(); /* +0x44 */
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual unsigned char mode(); /* +0x88 */
};

extern "C" {
extern unsigned char g_IsMultiplayer;
extern int D_005721A8;
extern int D_00494178;
extern char D_00582770[];
extern char D_00582680[];
extern char D_00582730[];
extern char D_004D9300[];
extern char D_004E0EA0[];
extern void * const D_004E0F20[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void std_tree_pair_int_value_compare_insert_one_pairR_2(TransferReferenceInsertResult* result, RbTree* tree, const TransferReferenceValue* value);
void cNPCInfoObject_ctor(int* shared);
void cNPCInfoObject_dtor(int* shared, short flags);
int cNPCInfoObject_GetOwner_cObjectIdR(int* shared, const GobjId* id);
int cNPCInfoObject_GetPrevOwner(int* shared, const GobjId* id);
void cNetObj_SetOwner(int id, int peer);
int NetGetMyClientIndex(int* id, int session);
int cNetObj_GetOwner(unsigned int id);
void cMessage_ctor_cMessageNameR(void* notice, const void* descriptor);
void QueueMessage_cMessageR_cSystemP_int(void* notice, cGOBJ* object, int flags);
void cMessage_dtor(void* notice, int flags);
int cNetObj_SendMessage_int_cMessageR_int_int(unsigned int id, const void* notice, int flags, int peer);
void NetObjectMgr_AddTransferTimer(const GobjId* id);
void cNetObjectMgr_TransferRequest(const GobjId* id, int peer);
}

static inline const GobjId* object_id(cGOBJ* object)
{
    return &((GobjEntry*)object)->id;
}

static inline int current_peer(void)
{
    int session = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}

static inline const GobjId& reference_id(cGOBJ* object, GobjId& invalid, int none)
{
    if (object)
        return ((GobjEntry*)object)->id;
    invalid.word = none;
    return invalid;
}

static inline bool is_alive(cGOBJ* a) { return a->unk2D && a->unk2C && !a->unk2E; }

static inline void request_transfer(cGOBJ* object, int peer, int owner)
{
    TransferRequestNotice notice;
    cMessage_ctor_cMessageNameR(&notice, D_00582770);
    notice.vtable = ((char*)D_004E0F20);
    notice.id.word = object_id(object)->word;
    notice.peer = peer;
    notice.flags = 0x40;
    cNetObj_SendMessage_int_cMessageR_int_int(object_id(object)->word, &notice, 0, owner);
    NetObjectMgr_AddTransferTimer(&((GobjEntry*)object)->id);
    notice.vtable = ((char*)D_004E0F20);
    cMessage_dtor(&notice, 0);
}

static inline void request_activate(cGOBJ* object, int target, int peer)
{
    ActivateNotice notice;
    cMessage_ctor_cMessageNameR(&notice, D_00582680);
    notice.vtable = D_004E0EA0;
    notice.flags = 0x40;
    notice.target = target;
    if (peer != current_peer())
        notice.state = 8;
    else
        notice.state = 1;
    QueueMessage_cMessageR_cSystemP_int(&notice, object, 1);
    notice.vtable = D_004E0EA0;
    cMessage_dtor(&notice, 0);
}

static inline void send_release(cGOBJ* object)
{
    TransferNotice notice;
    cMessage_ctor_cMessageNameR(&notice, D_00582730);
    notice.vtable = D_004D9300;
    notice.action = 2;
    notice.enabled = 1;
    QueueMessage_cMessageR_cSystemP_int(&notice, object, 0);
    notice.vtable = D_004D9300;
    cMessage_dtor(&notice, 0);
}

/* Activate network control of an object and notify its owner peer. */
extern "C" void cNetObjectMgr_AddActivate(cGOBJ* object, int peer)
{
    int shared;
    GobjId key;
    TransferObjectIterator end;
    TransferObjectIterator found;
    ActivateController* controller = (ActivateController*)object->attached;
    if (!controller || !controller->can_create_message())
        return;
    key.word = object_id(object)->word;
    std_tree_pair_int_value_compare_find_intR_3(&found, &D_005826A0, &key);
    TransferObjectNode* node = found.node;
    cNPCInfoObject_ctor(&shared);
    cAssocArray_int_tNetObjectPtr_Iterator_ctor(&end, std_map_int_tNetObjectPtr_end(&D_005826A0));
    if (node == end.node) {
        TransferObjectEntry* entry;
        {
            AllocGuard guard;
            entry = (TransferObjectEntry*)cMemMan_Allocate(0, sizeof(TransferObjectEntry), D_004BFB00, 0xA6);
        }
        if (entry)
            entry->reference = 0;
        TransferReference* reference;
        {
            AllocGuard guard;
            reference = (TransferReference*)cMemMan_Allocate(0, sizeof(TransferReference), D_004BFB00, 0xA8);
        }
        GobjId invalid;
        if (reference) {
            int none = -1;
            reference->id.word = none;
            reference->object = object;
            reference->id.word = reference_id(object, invalid, none).word;
        }
        entry->reference = reference;
        TransferReferenceInsertResult result;
        TransferReferenceValue value;
        value.id.word = object_id(object)->word;
        value.reference = (TransferReference*)entry;
        std_tree_pair_int_value_compare_insert_one_pairR_2(&result, &D_005826A0, &value);
    }
    if (peer >= 0) {
        int owner = cNPCInfoObject_GetOwner_cObjectIdR(&shared, &((GobjEntry*)object)->id);
        if (owner < 0)
            owner = cNPCInfoObject_GetPrevOwner(&shared, &((GobjEntry*)object)->id);
        cNetObj_SetOwner(object->unk10, peer);
        if (owner != peer && owner >= 0) {
            if (owner != current_peer())
                request_transfer(object, peer, owner);
            else
                cNetObjectMgr_TransferRequest(&((GobjEntry*)object)->id, (short)peer);
        } else {
            request_activate(object, object->unk10, peer);
        }
        if (peer != current_peer()) {
            unsigned int id = object_id(object)->word;
            if (cNetObj_GetOwner(id) != current_peer()) {
                if (!is_alive(object)) {
                    ActivateController* c2 = (ActivateController*)object->attached;
                    if (!c2 || c2->mode() != 2)
                        send_release(object);
                }
            }
        }
    }
    cNPCInfoObject_dtor(&shared, -1);
}
#pragma pop /* merge_units */
/* merge_units: end func_0042E180 */

/* merge_units: begin func_0042E6D0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern RbTree D_005826C0;
extern RbTree D_005826E0;
extern RbTree D_00582720;
void std_tree_pair_int_value_compare_begin_void_4(TransferObjectIterator* result, RbTree* tree);
PendingTransferIterator std_map_int_cMessagePtr_begin(RbTree* tree);
PendingTransferIterator std_map_int_cMessagePtr_end(RbTree* tree);
void cAssocArray_int_cMessagePtr_Iterator_ctor(PendingTransferIterator* result, const PendingTransferIterator& source);
void std_tree_pair_int_value_compare_begin_void_3(TransferReferenceIterator* result, RbTree* tree);
void std_red_black_tree_1_increment(void* iterator);
void std_tree_pair_int_value_compare_clear_void_2(RbTree* tree);
void std_tree_pair_short_value_compare_clear(RbTree* tree);
void std_tree_pair_int_value_compare_clear_void_3(RbTree* tree);
void func_0042F4D0(RbTree* tree);
void std_tree_pair_int_value_compare_clear_void_5(RbTree* tree);
}

/* Release owned references and pending messages, then clear their transfer maps. */
extern "C" void cNetObjectMgr_Reset(void)
{
    TransferObjectIterator object;
    PendingTransferIterator pending;
    TransferReferenceIterator reference;
    TransferObjectIterator objectEnd;
    PendingTransferIterator pendingBegin;
    PendingTransferIterator pendingEnd;
    TransferReferenceIterator referenceEnd;
    TransferObjectIterator objectBegin;
    std_tree_pair_int_value_compare_begin_void_4(&objectBegin, &D_005826A0);
    object.node = objectBegin.node;
    while (cAssocArray_int_tNetObjectPtr_Iterator_ctor(&objectEnd, std_map_int_tNetObjectPtr_end(&D_005826A0)),
           (object.node == objectEnd.node) ^ 1) {
        TransferObjectEntry* entry = object.node->entry;
        TransferReference* owned = entry->reference;
        {
            AllocGuard guard;
            cMemMan_Deallocate(0, owned, D_004BFB00, 0x61);
        }
        {
            AllocGuard guard;
            cMemMan_Deallocate(0, entry, D_004BFB00, 0x62);
        }
        std_red_black_tree_1_increment(&object);
    }
    std_tree_pair_int_value_compare_clear_void_2(&D_005826A0);
    std_tree_pair_short_value_compare_clear(&D_005826C0);
    cAssocArray_int_cMessagePtr_Iterator_ctor(&pendingBegin, std_map_int_cMessagePtr_begin(&D_005826E0));
    pending = pendingBegin;
    while (cAssocArray_int_cMessagePtr_Iterator_ctor(&pendingEnd, std_map_int_cMessagePtr_end(&D_005826E0)),
           (pending.node == pendingEnd.node) ^ 1) {
        TransferMessage* message = pending.node->message;
        {
            AllocGuard guard;
            message->~TransferMessage();
            cMemMan_Deallocate(0, message, D_004BFB00, 0x6B);
        }
        std_red_black_tree_1_increment(&pending);
    }
    std_tree_pair_int_value_compare_clear_void_3(&D_005826E0);
    TransferReferenceIterator referenceBegin;
    std_tree_pair_int_value_compare_begin_void_3(&referenceBegin, &D_00582700);
    reference.node = referenceBegin.node;
    while (cAssocArray_int_tNetActivateTerrainObjectPtr_Iterator_ctor(&referenceEnd, std_map_int_tNetActivateTerrainObjectPtr_end(&D_00582700)),
           (reference.node == referenceEnd.node) ^ 1) {
        TransferReference* registered = reference.node->reference;
        {
            AllocGuard guard;
            cMemMan_Deallocate(0, registered, D_004BFB00, 0x75);
        }
        std_red_black_tree_1_increment(&reference);
    }
    func_0042F4D0(&D_00582700);
    std_tree_pair_int_value_compare_clear_void_5(&D_00582720);
}
#pragma pop /* merge_units */
/* merge_units: end func_0042E6D0 */
