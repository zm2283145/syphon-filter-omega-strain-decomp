#pragma cplusplus on
#include "types.h"
typedef struct { int f0; int f4; int f8; int fC; int f10; int f14; } Pk70200;
typedef struct { void* vt; char p4[0x20]; int f24; int f28; int f2C; void* f30; } Msg70200;
typedef struct { char p0[0x24]; unsigned char action; } Hb70200;
typedef struct { char p0[0x98]; int f98; } Obj70200;
extern "C" {
extern unsigned char D_005723C8, D_005721D0, D_005721C8, D_005721C0;
extern char D_004EE698[], D_004D9940[];
extern void Event_Construct(Msg70200* e, void* type);
extern Obj70200* Object_LookupById(int* id);
extern void MsgQueue_QueueClone(Msg70200*, void*, int, int);
extern void cMessage_dtor(Msg70200*, int);
}
#pragma define_section GUARD_70200_DTOR ".dtors_drop" far_absolute RX
struct Guard_70200 {
    Guard_70200() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(GUARD_70200_DTOR) ~Guard_70200() { D_005723C8 = 0; }
};
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" int func_00170200(int a0, int a1, int a2, Pk70200* arg) {
    Guard_70200 g;
    if (D_005721D0) {
        Msg70200 msg;
        int id1;
        int id0;
        Obj70200* obj;
        Pk70200* p = arg;
        Msg70200* m;
        m = &msg;
        Event_Construct(m, D_004EE698);
        msg.vt = D_004D9940;
        msg.f24 = p->f8;
        msg.f28 = p->fC;
        msg.f2C = p->f10;
        id0 = p->f14;
        m->f30 = Object_LookupById(&id0);
        id1 = p->f4;
        obj = Object_LookupById(&id1);
        if (obj) {
            MsgQueue_QueueClone(&msg, obj, 0, 0);
            if (D_005721C8 ? D_005721C0 : 1) {
                int act = (unsigned char)msg.f24;
                if (act == 0) {
                    obj->f98++;
                    if (obj->f98 > 3) obj->f98 = 3;
                } else if (act == 2) {
                    obj->f98--;
                    if (obj->f98 < 0) obj->f98 = 0;
                }
            }
        }
        msg.vt = D_004D9940;
        cMessage_dtor(&msg, 0);
    }
    return 0x18;
}