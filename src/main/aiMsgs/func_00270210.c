#include "types.h"
typedef struct { void* vt; int pad[9]; int id; int pad2; } AIDeadEvt;
typedef struct { int pad; int id; } AIDeadArg;
extern void Event_Construct(AIDeadEvt* e, void* type);
extern void* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(AIDeadEvt* e, void* obj, int a, int b);
extern void cMessage_dtor(AIDeadEvt* e, int f);
extern char D_004DCD10[];
extern char g_ScriptAIDeactivatedMsgKey[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
#pragma opt_common_subs off
int func_00270210(int a0, int a1, int a2, AIDeadArg* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        AIDeadEvt e;
        void* obj;
        Event_Construct(&e, g_ScriptAIDeactivatedMsgKey);
        e.vt = D_004DCD10;
        e.id = arg->id;
        obj = Object_LookupById(&e.id);
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD10;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 8;
}



#pragma opt_common_subs reset
