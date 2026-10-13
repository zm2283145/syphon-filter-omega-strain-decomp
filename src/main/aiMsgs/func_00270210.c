#include "types.h"
typedef struct { void* vt; int pad[9]; int receiverId; int pad2; } Evt270210;
typedef struct { int header; int receiverId; } Arg270210;
extern void Event_Construct(Evt270210* e, void* type);
extern void* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(Evt270210* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt270210* e, int f);
extern char D_004DCD10[];
extern char g_ScriptAIDeactivatedMsgKey[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
#pragma opt_common_subs off
/* Network receive handler for cAIDeactivatedMsg (registered by cAIDeactivatedMsg_NetRegister): rebuilds the
 * message from the packet {receiver id} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAIDeactivatedMsg_NetReceive(int a0, int a1, int a2, Arg270210* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt270210 e;
        void* obj;
        Event_Construct(&e, g_ScriptAIDeactivatedMsgKey);
        e.vt = D_004DCD10;
        e.receiverId = arg->receiverId;
        obj = Object_LookupById(&e.receiverId);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD10;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 8;
}



#pragma opt_common_subs reset
