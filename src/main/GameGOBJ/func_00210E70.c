#pragma cplusplus on
#include "types.h"
struct Ctl_00210E70 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual int IsPlayer();
};
struct Obj_00210E70 { char pad0[0xC]; int id; char pad10[4]; unsigned char b14; char pad15[0x58 - 0x15]; Ctl_00210E70* ctl; };
struct LiftMsg_00210E70 { void* vtable; char base[0x1C]; unsigned char b20; char pad21[3]; int kind; int floor; int from; int to; char pad34[4]; };
struct Lift_00210E70 { char pad0[0xC]; int id; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern int g_TriggerMsgKey;
extern char D_004DAF10[];
void Event_Construct(void* m, void* type);
void cMessage_dtor(void* m, int flags);
Obj_00210E70* GObj_IdentityB(void*);
void Lift_SeekFloor(Lift_00210E70* l, int floor, int a2, int a3);
void Transport_Send(int target, LiftMsg_00210E70* msg, int a, int b);
}
static inline Lift_00210E70* GetLift_00210E70(void** a) { return (Lift_00210E70*)a[0]; }
static inline int ObjId_00210E70(Obj_00210E70* o) { return o ? o->id : 0; }
static inline unsigned char IsPlayerCtl_00210E70(Obj_00210E70* o)
{
    unsigned char r = 0;
    Ctl_00210E70* c = o->ctl;
    if (c && c->IsPlayer())
        r = 1;
    return r;
}
extern "C" int Script_cElevatorGOBJ_ChooseFloor_2(void** args)
{
    LiftMsg_00210E70 msg;
    Obj_00210E70* o = GObj_IdentityB(args[1]);
    Lift_00210E70* l = GetLift_00210E70(args);
    if (o) {
        if (o->b14 && IsPlayerCtl_00210E70(o)) {
            Lift_SeekFloor(l, -1, 1, 0);
        } else {
            LiftMsg_00210E70* p = &msg;
            int dest;
            int tid;
            Event_Construct(p, &g_TriggerMsgKey);
            msg.vtable = D_004DAF10;
            msg.kind = 1;
            msg.floor = -1;
            p->to = ObjId_00210E70(o);
            p->from = ObjId_00210E70(0);
            tid = l->id;
            if (g_IsMultiplayer) {
                if (IsPlayerCtl_00210E70(o))
                    dest = ((unsigned int)(o->id & 0x7F000000) >> 24) - 1;
                else
                    dest = -1;
            } else {
                dest = 0;
            }
            Transport_Send(tid, &msg, 0, dest);
            msg.vtable = D_004DAF10;
            cMessage_dtor(&msg, 0);
        }
    }
    return 0;
}
