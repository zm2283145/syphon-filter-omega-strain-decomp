#include "types.h"
typedef struct { void* vt; int pad[8]; void* target; int pad2[3]; int tid; int oid; } Evt270390;
typedef struct { int pad; int id; int id2; } Arg270390;
extern void Event_Construct(Evt270390* e, void* type);
extern void* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(Evt270390* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt270390* e, int f);
extern char D_004DCD70[];
extern char D_004DCD30[];
extern char D_004FF268[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
#pragma push
#pragma opt_propagation off
int func_00270390(int a0, int a1, int a2, Arg270390* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt270390 e;
        void* obj;
        Arg270390* a = arg;
        Evt270390* p = &e;
        Event_Construct(p, D_004FF268);
        e.vt = D_004DCD70;
        e.tid = a->id2;
        p->target = Object_LookupById((int*)((char*)&e + 0x34));
        e.vt = D_004DCD30;
        e.oid = a->id;
        obj = Object_LookupById((int*)((char*)&e + 0x38));
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD70;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0xC;
}
#pragma pop
