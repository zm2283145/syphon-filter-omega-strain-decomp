#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct VObj26FD50 { VPAD16(a) VPAD4(b) VPAD1(c) virtual int Check(); char pad[0x20C]; int f210; };
typedef struct { char pad[0x58]; VObj26FD50* sub; } Obj26FD50;
typedef struct { void* vt; int pad[8]; void* n1; void* n2; int pad2[2]; int whoId; int receiverId; } Evt26FD50;
typedef struct { int header; int receiverId; int n1; int n2; } Arg26FD50;
extern "C" {
extern void Event_Construct(Evt26FD50* e, void* type);
extern void* Object_LookupById(int* id);
extern void* NpcPath_GetNode(int id);
extern void MsgQueue_QueueClone(Evt26FD50* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt26FD50* e, int f);
extern char D_004DCD50[];
extern char D_004DCCD0[];
extern char g_ScriptAIWaypointReachedMsgKey[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
}
#pragma push
#pragma optimization_level 3

#pragma opt_propagation off
/* Network receive handler for cAIWaypointReachedMsg (registered by cAIWaypointReachedMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id} and queues a clone on the receiving
 * object. Returns the packet size. */
extern "C" int cAIWaypointReachedMsg_NetReceive(int a0, int a1, int a2, Arg26FD50* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26FD50 e;
        Obj26FD50* obj;
Arg26FD50* a = arg;
Evt26FD50* p = &e;
        Event_Construct(p, g_ScriptAIWaypointReachedMsgKey);
        e.vt = D_004DCD50;
        if (a->n1 >= 0) p->n1 = NpcPath_GetNode(a->n1); else p->n1 = 0;
        if (a->n2 >= 0) p->n2 = NpcPath_GetNode(a->n2); else p->n2 = 0;
        p->vt = D_004DCCD0;
        e.receiverId = a->receiverId;
        obj = (Obj26FD50*)Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) {
            if (a->n2 >= 0) {
            unsigned char ok = 0;
            if (obj->sub && obj->sub->Check()) ok = 1;
            if (ok) obj->sub->f210 = (int)NpcPath_GetNode(a->n2);
            }
            MsgQueue_QueueClone(&e, obj, 0, 0);
        }
        e.vt = D_004DCD50;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
