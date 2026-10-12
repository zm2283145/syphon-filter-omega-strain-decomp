#include "types.h"
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
typedef struct PkFF140 { int kind, id; unsigned char action, on; } PkFF140;
typedef struct MsgFF140 { void* vt; char p4[0x20]; int action; unsigned char on; char p29[3]; } MsgFF140;
extern unsigned char D_005723C8, D_005721D0;
extern char D_0055D480[], D_004E0840[];
void cMessage_ctor5(MsgFF140*, void*, PkFF140*);
void** NetMap_Lookup(int);
void MsgQueue_QueueClone(MsgFF140*, void*, int, int);
void cMessage_dtor(MsgFF140*, int);
int func_003FF140(int a, int b, int c, PkFF140* p0) {
    MsgFF140 msg;
    PkFF140* p;
    if (!D_005723C8) D_005723C8 = 1;
    p = p0;
    if (D_005721D0) {
        void** obj;
        cMessage_ctor5(&msg, D_0055D480, p);
        msg.vt = D_004E0840;
        msg.action = p->action;
        msg.on = p->on;
        obj = NetMap_Lookup(p->id);
        if (obj) MsgQueue_QueueClone(&msg, *obj, 0, 0);
        msg.vt = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0xC;
}
#pragma pop
