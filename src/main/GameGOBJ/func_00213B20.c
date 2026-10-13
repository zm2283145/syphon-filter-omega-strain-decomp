#include "types.h"
typedef struct { char d[0x9C]; } LdStr_00213B20;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    LdStr_00213B20 s78;
    LdStr_00213B20 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) LdSnd_00213B20;
typedef struct {
    void* vt;
    char pad4[0x74];
    LdStr_00213B20 s78;
    LdStr_00213B20 s114;
    char pad1B0[0x20];
} LdSnd2_00213B20;
typedef struct { void* vtable; char base[0x20]; int kind; int arg; } LdMsg_00213B20;
typedef struct { char pad[0x150]; char preset[0x2E0 - 0x150]; char action[1]; } Lift_00213B20;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_004F5448[];
extern char D_004DAED0[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern char D_004DADF0[];
extern void func_0020EBA0(LdSnd2_00213B20* e, void* action, Lift_00213B20* l);
extern void Lift_ActivateRecipients(Lift_00213B20* l);
extern void Event_Construct(LdMsg_00213B20* m, void* type);
extern void Event_Send(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void SoundEvent_CtorFromPreset(LdSnd_00213B20* e, void* preset, Lift_00213B20* l);
extern void func_0036E220(LdStr_00213B20* s, int flag);
void Lift_FinishArrival(Lift_00213B20* l)
{
    LdSnd_00213B20 ev;
    LdSnd2_00213B20 ev1;
    LdMsg_00213B20 msg;
    func_0020EBA0(&ev1, l->action, l);
    Event_Send(&ev1, D_004FFB50, 1);
    ev1.vt = D_004DADF0;
    func_0036E220(&ev1.s114, -1);
    func_0036E220(&ev1.s78, -1);
    cMessage_dtor(&ev1, 0);
    SoundEvent_CtorFromPreset(&ev, l->preset, l);
    ev.flag = 1;
    Event_Send(&ev, D_004FFB50, 1);
    if (!D_005721C8 || (D_005721C8 ? D_005721C0 : 1)) {
        Event_Construct(&msg, D_004F5448);
        msg.vtable = D_004DAED0;
        msg.kind = 0;
        msg.arg = 0;
        Event_Send(&msg, l, 0);
        msg.vtable = D_004DAED0;
        cMessage_dtor(&msg, 0);
    }
    Lift_ActivateRecipients(l);
    ev.vt = D_004DAE30;
    func_0036E220(&ev.s114, -1);
    func_0036E220(&ev.s78, -1);
    cMessage_dtor(&ev, 0);
}

