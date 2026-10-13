#include "types.h"
typedef struct { void* vt; int pad[8]; void* who; int pad2[3]; int whoId; int receiverId; } Evt270030;
typedef struct { int header; int receiverId; int whoId; } Arg270030;
extern void Event_Construct(Evt270030* e, void* type);
extern void* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(Evt270030* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt270030* e, int f);
extern char D_004DCCF0[];
extern char g_ScriptAIDeadMsgKey[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
#pragma push
#pragma opt_propagation off
/* Network receive handler for cAIDeadMsg (registered by cAIDeadMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAIDeadMsg_NetReceive(int a0, int a1, int a2, Arg270030* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt270030 e;
        void* obj;
        Arg270030* a = arg;
        Evt270030* p = &e;
        Event_Construct(p, g_ScriptAIDeadMsgKey);
        e.vt = D_004DCCF0;
        e.whoId = a->whoId;
        p->who = Object_LookupById((int*)((char*)&e + 0x34) /* &e.whoId */);
        e.receiverId = a->receiverId;
        obj = Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCCF0;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
