#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off

#include "transfer_cleanup_types.h"
#include "alloc_guard.h"

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
extern RbTree D_005826A0;
extern unsigned char D_005721C8;
extern int D_005721A8;
extern int D_00494178;
extern char D_00582770[];
extern char D_00582680[];
extern char D_00582730[];
extern char D_004BFB00[];
extern char D_004D9300[];
extern char D_004E0EA0[];
extern void * const D_004E0F20[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void func_0042EDF0(TransferObjectIterator* result, RbTree* tree, const GobjId* id);
TransferObjectIterator func_0042DF10(RbTree* tree);
void func_0042DF00(TransferObjectIterator* result, const TransferObjectIterator& source);
void func_0042F170(TransferReferenceInsertResult* result, RbTree* tree, const TransferReferenceValue* value);
void func_00436C00(int* shared);
void func_00436BA0(int* shared, short flags);
int func_00434440(int* shared, const GobjId* id);
int func_00434380(int* shared, const GobjId* id);
void func_003FB4B0(int id, int peer);
int func_002EBAF8(int* id, int session);
int Player_GetIndex(unsigned int id);
void Event_Construct(void* notice, const void* descriptor);
void Event_Send(void* notice, cGOBJ* object, int flags);
void cMessage_dtor(void* notice, int flags);
int Transport_Send(unsigned int id, const void* notice, int flags, int peer);
void NetObjectMgr_AddTransferTimer(const GobjId* id);
void func_0042D360(const GobjId* id, int peer);
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
            func_002EBAF8(&D_00494178, session);
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
    Event_Construct(&notice, D_00582770);
    notice.vtable = ((char*)D_004E0F20);
    notice.id.word = object_id(object)->word;
    notice.peer = peer;
    notice.flags = 0x40;
    Transport_Send(object_id(object)->word, &notice, 0, owner);
    NetObjectMgr_AddTransferTimer(&((GobjEntry*)object)->id);
    notice.vtable = ((char*)D_004E0F20);
    cMessage_dtor(&notice, 0);
}

static inline void request_activate(cGOBJ* object, int target, int peer)
{
    ActivateNotice notice;
    Event_Construct(&notice, D_00582680);
    notice.vtable = D_004E0EA0;
    notice.flags = 0x40;
    notice.target = target;
    if (peer != current_peer())
        notice.state = 8;
    else
        notice.state = 1;
    Event_Send(&notice, object, 1);
    notice.vtable = D_004E0EA0;
    cMessage_dtor(&notice, 0);
}

static inline void send_release(cGOBJ* object)
{
    TransferNotice notice;
    Event_Construct(&notice, D_00582730);
    notice.vtable = D_004D9300;
    notice.action = 2;
    notice.enabled = 1;
    Event_Send(&notice, object, 0);
    notice.vtable = D_004D9300;
    cMessage_dtor(&notice, 0);
}

/* Activate network control of an object and notify its owner peer. */
extern "C" void func_0042E180(cGOBJ* object, int peer)
{
    int shared;
    GobjId key;
    TransferObjectIterator end;
    TransferObjectIterator found;
    ActivateController* controller = (ActivateController*)object->attached;
    if (!controller || !controller->can_create_message())
        return;
    key.word = object_id(object)->word;
    func_0042EDF0(&found, &D_005826A0, &key);
    TransferObjectNode* node = found.node;
    func_00436C00(&shared);
    func_0042DF00(&end, func_0042DF10(&D_005826A0));
    if (node == end.node) {
        TransferObjectEntry* entry;
        {
            AllocGuard guard;
            entry = (TransferObjectEntry*)Mem_Alloc(0, sizeof(TransferObjectEntry), D_004BFB00, 0xA6);
        }
        if (entry)
            entry->reference = 0;
        TransferReference* reference;
        {
            AllocGuard guard;
            reference = (TransferReference*)Mem_Alloc(0, sizeof(TransferReference), D_004BFB00, 0xA8);
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
        func_0042F170(&result, &D_005826A0, &value);
    }
    if (peer >= 0) {
        int owner = func_00434440(&shared, &((GobjEntry*)object)->id);
        if (owner < 0)
            owner = func_00434380(&shared, &((GobjEntry*)object)->id);
        func_003FB4B0(object->unk10, peer);
        if (owner != peer && owner >= 0) {
            if (owner != current_peer())
                request_transfer(object, peer, owner);
            else
                func_0042D360(&((GobjEntry*)object)->id, (short)peer);
        } else {
            request_activate(object, object->unk10, peer);
        }
        if (peer != current_peer()) {
            unsigned int id = object_id(object)->word;
            if (Player_GetIndex(id) != current_peer()) {
                if (!is_alive(object)) {
                    ActivateController* c2 = (ActivateController*)object->attached;
                    if (!c2 || c2->mode() != 2)
                        send_release(object);
                }
            }
        }
    }
    func_00436BA0(&shared, -1);
}
