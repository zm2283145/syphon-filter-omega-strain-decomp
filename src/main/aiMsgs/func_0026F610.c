#include "types.h"
typedef struct { void* vt; int pad[8]; void* target; unsigned char flag; char pad2[11]; int tid; int oid; } Evt26F610;
typedef struct { int pad; int id; int id2; unsigned char flag; } Arg26F610;
extern void Event_Construct(Evt26F610* e, void* type);
extern void* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(Evt26F610* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt26F610* e, int f);
extern char D_004DCD70[];
extern char D_004DCC70[];
extern char D_004FF2B0[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
#pragma push
#pragma opt_propagation off
int func_0026F610(int a0, int a1, int a2, Arg26F610* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Evt26F610 e;
        void* obj;
        Arg26F610* a = arg;
        Evt26F610* p = &e;
        Event_Construct(p, D_004FF2B0);
        e.vt = D_004DCD70;
        e.tid = a->id2;
        p->target = Object_LookupById((int*)((char*)&e + 0x34));
        e.vt = D_004DCC70;
        e.flag = a->flag;
        e.oid = a->id;
        obj = Object_LookupById((int*)((char*)&e + 0x38));
        if (obj) MsgQueue_QueueClone(&e, obj, 0, 0);
        e.vt = D_004DCD70;
        cMessage_dtor(&e, 0);
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
