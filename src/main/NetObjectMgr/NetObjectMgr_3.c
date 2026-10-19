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
Word* func_0042DA10(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* end(): iterator at the tree header. */
void func_0042DA20(Iter* out, Tree* t) {
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
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern int D_005721A8;
extern int D_00494178;
extern char D_00582770[];
extern char D_00572198[];
extern "C" void Message_GetScriptTypeKey();
extern "C" void func_00431F30();
extern "C" void func_00432150();
extern void * const D_004E0F20[];
extern char D_004E0E80[];
void func_0042EDF0(TransferObjectIterator* result, RbTree* tree, const GobjId* id);
void func_0042DF10(TransferObjectIterator* result, RbTree* tree);
TransferObjectIterator* func_0042DF00(TransferObjectIterator* result,
                                    const TransferObjectIterator* source);
void func_00436C00(int* shared);
void func_00436BA0(int* shared, short flags);
int func_00434440(int* shared, const GobjId* id);
int func_00434380(int* shared, const GobjId* id);
void func_00434600(int* shared, const GobjId* id, int peer);
int NetGame_InitLocalSlot(int* id, int session);
int PlayerSlots_Get(int peer);
void Event_Construct(void* notice, const void* descriptor);
void cMessage_dtor(void* notice, int flags);
int Transport_Send(unsigned int id, const void* notice, int flags, int peer);
void NetObjectMgr_AddTransferTimer(const GobjId* id);
void func_0042D360(const GobjId* id, int peer);
void func_00429200(TransferReleaseNotice* notice, unsigned int id, int peer);
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
    if (D_005721C8) {
        if (D_00494178 == -1)
            NetGame_InitLocalSlot(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}

static inline int is_host(void)
{
    return D_005721C8 ? D_005721C0 : 1;
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
    func_00429200(&notice, object_id(object)->word, peer);
    notice.vtable = D_004E0E80;
    cMessage_dtor(&notice, 0);
}

/* Route ownership changes through the current peer or the object's local callbacks. */
extern "C" void func_0042DA30(cGOBJ* object, int previousPeer, int nextPeer)
{
    int shared;
    GobjId key;
    TransferObjectIterator end;
    TransferObjectIterator found;
    TransferObjectIterator rawEnd;
    key.word = object_id(object)->word;
    func_0042EDF0(&found, &D_005826A0, &key);
    TransferObjectNode* node = found.node;
    func_00436C00(&shared);
    func_0042DF10(&rawEnd, &D_005826A0);
    func_0042DF00(&end, &rawEnd);
    if ((node == end.node) ^ 1) {
        int owner = func_00434440(&shared, object_id(object));
        int previousOwner = func_00434380(&shared, object_id(object));
        if (previousPeer == owner) {
            if (nextPeer >= 0) {
                if (is_host()) {
                    func_00434600(&shared, object_id(object), nextPeer);
                    if (owner != current_peer())
                        request_transfer(object, nextPeer, owner);
                    else
                        func_0042D360(object_id(object), (short)nextPeer);
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
                func_00434600(&shared, object_id(object), nextPeer);
                if (previousOwner != current_peer())
                    request_transfer(object, nextPeer, previousOwner);
                else
                    func_0042D360(object_id(object), (short)nextPeer);
            } else {
                func_0042D360(object_id(object), (short)nextPeer);
            }
        } else {
            if (previousPeer != current_peer())
                request_release(object, previousPeer);
            else
                ((TransferOwnerObjectMethods*)object)->release_transfer();
        }
    }
    func_00436BA0(&shared, -1);
}

#pragma opt_common_subs on

/* Destroy a transfer request and optionally release its allocation. */
extern "C" TransferRequestNotice* func_0042DEA0(TransferRequestNotice* notice, int flags)
{
    if (notice) {
        notice->vtable = ((char*)D_004E0F20);
        cMessage_dtor(notice, 0);
        if ((short)flags > 0)
            operator_delete(notice);
    }
    return notice;
}
void * const D_004E0F20[8] = { (void*)0x0, (void*)0x0, (void*)func_0042DEA0, (void*)func_00431F30, (void*)func_00432150, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_0042DA30 */
