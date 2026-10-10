#include "types.h"
typedef struct { char d[0x9C]; } LdStr_f3;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    LdStr_f3 s78;
    LdStr_f3 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) LdSnd_f3;
typedef struct { void* vtable; char base[0x20]; int kind; int arg; } LdMsg_f3;
typedef struct { char pad[0x150]; char preset[1]; } Lift_f3;
extern char D_004F5448[];
extern char D_004DAED0[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern int func_00214240(Lift_f3* l);
extern int func_00214470(Lift_f3* l);
extern int func_002141A0(Lift_f3* l);
extern void func_00214310(Lift_f3* l);
extern void Event_Construct(LdMsg_f3* m, void* type);
extern void Event_Send(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void SoundEvent_CtorFromPreset(LdSnd_f3* e, void* preset, Lift_f3* l);
extern void func_0036E220(LdStr_f3* s, int flag);
unsigned char Lift_OpenDoors(Lift_f3* l)
{
    LdSnd_f3 ev;
    LdMsg_f3 msg;
    unsigned char r;
    if (func_00214240(l)) {
        r = func_00214470(l);
        if (r) {
            Event_Construct(&msg, D_004F5448);
            msg.vtable = D_004DAED0;
            msg.kind = 2;
            msg.arg = 0;
            Event_Send(&msg, l, 0);
            msg.vtable = D_004DAED0;
            cMessage_dtor(&msg, 0);
        }
        SoundEvent_CtorFromPreset(&ev, l->preset, l);
        ev.flag = 1;
        Event_Send(&ev, D_004FFB50, 1);
        ev.vt = D_004DAE30;
        func_0036E220(&ev.s114, -1);
        func_0036E220(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    } else {
        r = 1;
    }
    if (func_002141A0(l)) {
        func_00214310(l);
    }
    return r;
}