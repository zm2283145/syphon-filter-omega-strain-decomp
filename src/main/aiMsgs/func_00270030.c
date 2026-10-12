#include "types.h"
typedef struct { void* vt; int pad[8]; void* target; int pad2[3]; int tid; int oid; } Evt270030;
typedef struct { int pad; int id; int id2; } Arg270030;
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
int func_00270030(int a0, int a1, int a2, Arg270030* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt270030 e;
        void* obj;
        Arg270030* a = arg;
        Evt270030* p = &e;
        Event_Construct(p, g_ScriptAIDeadMsgKey);
        e.vt = D_004DCCF0;
        e.tid = a->id2;
        p->target = Object_LookupById((int*)((char*)&e + 0x34));
        e.oid = a->id;
        obj = Object_LookupById((int*)((char*)&e + 0x38));
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCCF0;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
