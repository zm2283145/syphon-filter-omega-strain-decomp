#include "types.h"
typedef struct { void* vt; int pad[8]; void* who; signed char flag; char pad2[11]; int whoId; int receiverId; } Evt26F850;
typedef struct { int header; int receiverId; int whoId; signed char flag; } Arg26F850;
extern void Event_Construct(Evt26F850* e, void* type);
extern void* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(Evt26F850* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt26F850* e, int f);
extern char D_004DCD70[];
extern char D_004DCC90[];
extern char g_ScriptAINewAwarenessMsgKey[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
#pragma push
#pragma opt_propagation off
/* Network receive handler for cAINewAwarenessMsg (registered by cAINewAwarenessMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id, flag} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAINewAwarenessMsg_NetReceive(int a0, int a1, int a2, Arg26F850* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26F850 e;
        void* obj;
        Arg26F850* a = arg;
        Evt26F850* p = &e;
        Event_Construct(p, g_ScriptAINewAwarenessMsgKey);
        e.vt = D_004DCD70;
        e.whoId = a->whoId;
        p->who = Object_LookupById((int*)((char*)&e + 0x34) /* &e.whoId */);
        e.vt = D_004DCC90;
        e.flag = a->flag;
        e.receiverId = a->receiverId;
        obj = Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD70;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
