#include "types.h"
typedef struct { void* vtable; char pad[0x20]; int value; } F6Msg;
typedef struct { int id; int target; } F6Link;
typedef struct { unsigned char active; char pad[0x17]; float weight; char pad2[0x78]; unsigned char notify; char pad3[3]; F6Link link; } F6Slot;
typedef struct { char pad[0x18]; char arr[1]; } F6Host;
extern void std_deque_deleter_cSkaSystem_Request_push_back(void* arr, void* item);
extern F6Slot* std_deque_deleter_common_cSkaSystem_Request_back_void(void* arr);
extern char D_00542B68[];
extern void Event_PackHeader();
extern void cMessage_getSOBJClassId();
extern void cSkaAnimEventMessage_dtor();
extern void cSkaAnimEventMessage_Clone();
void * const D_004DFBD0[8] = { (void*)0x0, (void*)0x0, (void*)cSkaAnimEventMessage_dtor, (void*)cSkaAnimEventMessage_Clone, (void*)Event_PackHeader, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
extern void cMessage_ctor_cMessageNameR(F6Msg* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(F6Msg* m, int target, int immediate);
extern void cMessage_dtor(F6Msg* m, int flags);
static inline int F6LinkValid(F6Link* l) { return l->target != 0 && ~l->id != 0; }
void cSkaRequestStream_StartPlayingItem(float w, F6Host* h, void* req, int stop)
{
    F6Slot* s;
    std_deque_deleter_cSkaSystem_Request_push_back(h->arr, req);
    s = std_deque_deleter_common_cSkaSystem_Request_back_void(h->arr);
    s->weight = w;
    s->active = 1;
    if (stop) {
        F6Slot* e = std_deque_deleter_common_cSkaSystem_Request_back_void(h->arr);
        if (e->notify) {
            F6Link* l = &e->link;
            if (F6LinkValid(l)) {
                int v = l->id;
                F6Msg msg;
                cMessage_ctor_cMessageNameR(&msg, D_00542B68);
                msg.vtable = ((char*)D_004DFBD0);
                msg.value = v;
                QueueMessage_cMessageR_cSystemP_int(&msg, l->target, 1);
                msg.vtable = ((char*)D_004DFBD0);
                cMessage_dtor(&msg, 0);
            }
        }
        e->active = 0;
    }
}