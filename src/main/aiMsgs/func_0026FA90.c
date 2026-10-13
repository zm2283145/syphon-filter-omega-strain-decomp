#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct VObj26FA90 { VPAD16(a) VPAD4(b) VPAD1(c) virtual int Check(); char pad[0x20C]; int f210; };
typedef struct { char pad[0x58]; VObj26FA90* sub; } Obj26FA90;
typedef struct { void* vt; int pad[8]; void* n1; void* n2; int pad2[2]; int whoId; int receiverId; } Evt26FA90;
typedef struct { int header; int receiverId; int n1; int n2; } Arg26FA90;
extern "C" {
extern void Event_Construct(Evt26FA90* e, void* type);
extern void* Object_LookupById(int* id);
extern void* NpcPath_GetNode(int id);
extern void MsgQueue_QueueClone(Evt26FA90* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt26FA90* e, int f);
extern char D_004DCD50[];
extern char D_004DCCB0[];
extern char g_ScriptAIDestinationReachedMsgKey[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
}
#pragma push
#pragma optimization_level 3

#pragma opt_propagation off
/* Network receive handler for cAIDestinationReachedMsg (registered by cAIDestinationReachedMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id} and queues a clone on the receiving
 * object. Returns the packet size. */
extern "C" int cAIDestinationReachedMsg_NetReceive(int a0, int a1, int a2, Arg26FA90* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26FA90 e;
        Obj26FA90* obj;
        Arg26FA90* a = arg;
        Evt26FA90* p = &e;
        Event_Construct(p, g_ScriptAIDestinationReachedMsgKey);
        e.vt = D_004DCD50;
        if (a->n1 >= 0) p->n1 = NpcPath_GetNode(a->n1); else p->n1 = 0;
        if (a->n2 >= 0) p->n2 = NpcPath_GetNode(a->n2); else p->n2 = 0;
        p->vt = D_004DCCB0;
        e.receiverId = a->receiverId;
        obj = (Obj26FA90*)Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) {
            unsigned char ok = 0;
            if (obj->sub && obj->sub->Check()) ok = 1;
            if (ok) obj->sub->f210 = 0;
            MsgQueue_QueueClone(&e, obj, 0, 0);
        }
        e.vt = D_004DCD50;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
