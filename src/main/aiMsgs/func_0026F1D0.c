#include "types.h"
typedef struct { void* vt; int pad[8]; void* who; int pad2[3]; int whoId; int receiverId; } Evt26F1D0;
typedef struct { int header; int receiverId; int whoId; } Arg26F1D0;
extern void Event_Construct(Evt26F1D0* e, void* type);
extern void* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(Evt26F1D0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt26F1D0* e, int f);
extern char D_004DCD70[];
extern char D_004DCC30[];
extern char D_004FF2C0[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
#pragma push
#pragma opt_propagation off
/* Network receive handler for cAIUnconsciousMsg (registered by cAIUnconsciousMsg_NetRegister): rebuilds the
 * message from the packet {receiver id, who id} and queues a clone on the receiving
 * object. Returns the packet size. */
int cAIUnconsciousMsg_NetReceive(int a0, int a1, int a2, Arg26F1D0* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26F1D0 e;
        void* obj;
        Arg26F1D0* a = arg;
        Evt26F1D0* p = &e;
        Event_Construct(p, D_004FF2C0);
        e.vt = D_004DCD70;
        e.whoId = a->whoId;
        p->who = Object_LookupById((int*)((char*)&e + 0x34) /* &e.whoId */);
        e.vt = D_004DCC30;
        e.receiverId = a->receiverId;
        obj = Object_LookupById((int*)((char*)&e + 0x38) /* &e.receiverId */);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD70;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0xC;
}
#pragma pop
