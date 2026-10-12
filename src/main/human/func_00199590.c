#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct V_199590 { __int128 q; V_199590() {} };
struct F2Str_199590 { char d[0x9C]; };
struct F2Ev_199590 { void* vt; char pad4[0x1C]; unsigned char flag; char pad21[0x57]; F2Str_199590 s78; F2Str_199590 s114; char pad1B0[0x10]; } __attribute__((aligned(16)));
class C_199590 { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };
struct E_199590 { char pad[0x100]; signed char b100; };
class O_199590 { public:
  VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual V_199590 GetPos();
  char pad4[0x10]; unsigned char active; char pad15[0x58 - 0x15]; C_199590* ctl;
  char pad5C[0x33E6 - 0x5C]; unsigned char b33E6; unsigned char b33E7; char pad33E8[0x346F - 0x33E8]; unsigned char b346F;
  char pad3470[0x3524 - 0x3470]; void* weapons; };
extern "C" {
E_199590* WeaponInv_GetSlot6Record(void* w);
void Hud_SetFlashlightIcon(void* p, int v, unsigned char on);
void WeaponInv_SetSlotModelState(void* w, int k, unsigned char on);
void SoundPosRequest_Ctor(F2Ev_199590* e, void* name, V_199590* pos);
void Event_Send(F2Ev_199590* e, void* tgt, int n);
void func_0036E220(F2Str_199590* s, int f);
void cMessage_dtor(F2Ev_199590* e, int f);
extern void* D_004FFC2C;
extern char D_004F0DF0[];
extern char D_004FFB50[];
extern char D_004DAE30[];
}
static inline unsigned char Has_199590(O_199590* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
extern "C" void Actor_InfraredSwitch(O_199590* o, unsigned char on)
{
    E_199590* e = WeaponInv_GetSlot6Record(o->weapons);
    int v = 0;
    void* mgr = D_004FFC2C;
    if (e) v = e->b100;
    o->b346F = on ? v : 0;
    if (Has_199590(o) && o->active && o->b33E7) {
        Hud_SetFlashlightIcon(mgr, v, on);
        if (!e) { o->b33E6 = 0; o->b33E7 = 0; }
    }
    WeaponInv_SetSlotModelState(o->weapons, 6, on);
    {
        V_199590 pos = o->GetPos();
        F2Ev_199590 ev;
        SoundPosRequest_Ctor(&ev, D_004F0DF0, &pos);
        ev.flag = 1;
        Event_Send(&ev, D_004FFB50, 0);
        ev.vt = D_004DAE30;
        func_0036E220(&ev.s114, -1);
        func_0036E220(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    }
}
