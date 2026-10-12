#pragma cplusplus on
#include "types.h"
struct Ctl_00254600 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual int IsActive();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual int GetId();
};
struct CtlObj_00254600 { char pad[0x14]; unsigned char b14; };
struct Obj_00254600 { char pad0[0x58]; Ctl_00254600* ctl; };
struct Ev_00254600 { char pad[0x30]; int id; };
struct Msg_00254600 { void* vtable; char pad4[0x1C]; signed char b20; char pad21[3]; signed char b24; char pad25[3]; void* bp; int id; };
struct Bp_00254600 { char pad0[0xC]; int net; char pad10[0x2F3 - 0x10]; unsigned char b2F3; char pad2F4[0x308 - 0x2F4]; int owner; char pad30C[8]; float f314; };
extern "C" {
extern unsigned char D_005721C8;
extern int D_004F5440;
extern char D_005061B0[];
extern char D_004DCEF0[];
extern char D_004DCF10[];
int* Event_GetType(void* ev);
void Event_Construct(void* m, void* type);
void cMessage_dtor(void* m, int flags);
Obj_00254600* Object_LookupById(int* id);
void Transport_Send(int target, Msg_00254600* msg, int a, int b);
void func_001762C0(Ctl_00254600* c, Bp_00254600* b);
int Object_HandleMessage(Bp_00254600* b, Ev_00254600* ev);
}
extern "C" int cBackpack_v01(Bp_00254600* bp, Ev_00254600* ev)
{
    int t = *Event_GetType(ev);
    if (t == D_004F5440) {
        int id = ev->id;
        Ctl_00254600* c = Object_LookupById(&id)->ctl;
        if (c && c->IsActive() && ((CtlObj_00254600*)c)->b14) {
            int who = c->GetId();
            if (bp->b2F3 || bp->owner == who) {
                if (bp->f314 < 0.0f) {
                    func_001762C0(c, bp);
                }
            } else {
                if (D_005721C8) {
                    Msg_00254600 m;
                    Event_Construct(&m, D_005061B0);
                    m.id = who;
                    m.vtable = D_004DCEF0;
                    m.bp = bp;
                    m.b24 = 2;
                    m.b20 = 4;
                    Transport_Send(bp->net, &m, -1, bp->owner);
                    m.vtable = D_004DCF10;
                    cMessage_dtor(&m, 0);
                }
            }
        }
        return 1;
    }
    return Object_HandleMessage(bp, ev);
}

