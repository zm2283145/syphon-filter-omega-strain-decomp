/*
 * main/NetObjectMgr: 2 files, 0042DA10-0042DA30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042DA10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Iterator copy-assignment. */
Word* cAssocArray_int_tNetActivateTerrainObjectPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* end(): iterator at the tree header. */
void std_map_int_tNetActivateTerrainObjectPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042DA10 */

/* merge_units: begin func_0042DA30 */
#pragma push /* merge_units */
#pragma cplusplus on
/* Retail recomputes member addresses rather than keeping one across callbacks. */
#pragma opt_common_subs off

#include "transfer_ownership_types.h"

extern "C" {
extern RbTree D_005826A0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern int D_005721A8;
extern int D_00494178;
extern char D_00582770[];
extern char D_00572198[];
extern "C" void Message_GetScriptTypeKey();
extern "C" void cNetTransferMsg_v01();
extern "C" void cNetTransferMsg_v02();
extern void * const D_004E0F20[];
extern char D_004E0E80[];
void ObjMap_Find_42EDF0(TransferObjectIterator* result, RbTree* tree, const GobjId* id);
void std_map_int_tNetObjectPtr_end(TransferObjectIterator* result, RbTree* tree);
TransferObjectIterator* cAssocArray_int_tNetObjectPtr_Iterator_ctor(TransferObjectIterator* result,
                                    const TransferObjectIterator* source);
void cNPCInfoObject_ctor(int* shared);
void cNPCInfoObject_dtor(int* shared, short flags);
int cNPCInfoObject_GetOwner_cObjectIdR(int* shared, const GobjId* id);
int cNPCInfoObject_GetPrevOwner(int* shared, const GobjId* id);
void cNPCInfoObject_SetOwner_cObjectIdR_int(int* shared, const GobjId* id, int peer);
int NetGame_InitLocalSlot(int* id, int session);
int PlayerSlots_Get(int peer);
void Event_Construct(void* notice, const void* descriptor);
void cMessage_dtor(void* notice, int flags);
int Transport_Send(unsigned int id, const void* notice, int flags, int peer);
void NetObjectMgr_AddTransferTimer(const GobjId* id);
void cNetObjectMgr_TransferRequest(const GobjId* id, int peer);
void cDeactivateMsg_SendDeactivated(TransferReleaseNotice* notice, unsigned int id, int peer);
void NetObjectMgr_Remove(cGOBJ* object);
void operator_delete(void* allocation);
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
            NetGame_InitLocalSlot(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}

static inline int is_host(void)
{
    return g_IsMultiplayer ? D_005721C0 : 1;
}

static inline void request_transfer(cGOBJ* object, int peer, int owner)
{
    TransferRequestNotice notice;
    Event_Construct(&notice, D_00582770);
    notice.vtable = ((char*)D_004E0F20);
    notice.id.word = object_id(object)->word;
    notice.peer = peer;
    notice.flags = 0x40;
    Transport_Send(object_id(object)->word, &notice, 0, owner);
    NetObjectMgr_AddTransferTimer(object_id(object));
    notice.vtable = ((char*)D_004E0F20);
    cMessage_dtor(&notice, 0);
}

static inline void request_release(cGOBJ* object, int peer)
{
    TransferReleaseNotice notice;
    Event_Construct(&notice, D_00572198);
    notice.vtable = D_004E0E80;
    cDeactivateMsg_SendDeactivated(&notice, object_id(object)->word, peer);
    notice.vtable = D_004E0E80;
    cMessage_dtor(&notice, 0);
}

/* Route ownership changes through the current peer or the object's local callbacks. */
extern "C" void cNetObjectMgr_AddDeactivate(cGOBJ* object, int previousPeer, int nextPeer)
{
    int shared;
    GobjId key;
    TransferObjectIterator end;
    TransferObjectIterator found;
    TransferObjectIterator rawEnd;
    key.word = object_id(object)->word;
    ObjMap_Find_42EDF0(&found, &D_005826A0, &key);
    TransferObjectNode* node = found.node;
    cNPCInfoObject_ctor(&shared);
    std_map_int_tNetObjectPtr_end(&rawEnd, &D_005826A0);
    cAssocArray_int_tNetObjectPtr_Iterator_ctor(&end, &rawEnd);
    if ((node == end.node) ^ 1) {
        int owner = cNPCInfoObject_GetOwner_cObjectIdR(&shared, object_id(object));
        int previousOwner = cNPCInfoObject_GetPrevOwner(&shared, object_id(object));
        if (previousPeer == owner) {
            if (nextPeer >= 0) {
                if (is_host()) {
                    cNPCInfoObject_SetOwner_cObjectIdR_int(&shared, object_id(object), nextPeer);
                    if (owner != current_peer())
                        request_transfer(object, nextPeer, owner);
                    else
                        cNetObjectMgr_TransferRequest(object_id(object), (short)nextPeer);
                }
            } else {
                if (object->attached) {
                    if (previousPeer != current_peer())
                        request_release(object, previousPeer);
                    else
                        ((TransferOwnerControllerMethods*)object->attached)->release_transfer();
                }
                NetObjectMgr_Remove(object);
            }
        } else if (owner < 0) {
            if (previousOwner >= 0 && PlayerSlots_Get(previousOwner)) {
                cNPCInfoObject_SetOwner_cObjectIdR_int(&shared, object_id(object), nextPeer);
                if (previousOwner != current_peer())
                    request_transfer(object, nextPeer, previousOwner);
                else
                    cNetObjectMgr_TransferRequest(object_id(object), (short)nextPeer);
            } else {
                cNetObjectMgr_TransferRequest(object_id(object), (short)nextPeer);
            }
        } else {
            if (previousPeer != current_peer())
                request_release(object, previousPeer);
            else
                ((TransferOwnerObjectMethods*)object)->release_transfer();
        }
    }
    cNPCInfoObject_dtor(&shared, -1);
}

#pragma opt_common_subs on

/* Destroy a transfer request and optionally release its allocation. */
extern "C" TransferRequestNotice* cNetTransferMsg_dtor(TransferRequestNotice* notice, int flags)
{
    if (notice) {
        notice->vtable = ((char*)D_004E0F20);
        cMessage_dtor(notice, 0);
        if ((short)flags > 0)
            operator_delete(notice);
    }
    return notice;
}
void * const D_004E0F20[8] = { (void*)0x0, (void*)0x0, (void*)cNetTransferMsg_dtor, (void*)cNetTransferMsg_v01, (void*)cNetTransferMsg_v02, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_0042DA30 */
