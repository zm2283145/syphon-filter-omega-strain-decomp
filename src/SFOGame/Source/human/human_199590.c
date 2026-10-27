/*
 * main/human: range (5 files, 00199590-00199860)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00199590 */
#pragma push /* merge_units */
#pragma cplusplus on
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
E_199590* cWeapon_GetGoggleEntry(void* w);
void cHud_ChangeGadgetState(void* p, int v, unsigned char on);
void cWeapon_SetHardpointActivation(void* w, int k, unsigned char on);
void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(F2Ev_199590* e, void* name, V_199590* pos);
void QueueMessage_cMessageR_cSystemP_int(F2Ev_199590* e, void* tgt, int n);
void cFileMan_dtor(F2Str_199590* s, int f);
void cMessage_dtor(F2Ev_199590* e, int f);
extern void* g_Hud;
extern char D_004F0DF0[];
extern char g_Game[];
extern char D_004DAE30[];
}
static inline unsigned char Has_199590(O_199590* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
extern "C" void cHuman_EquipGoggles(O_199590* o, unsigned char on)
{
    E_199590* e = cWeapon_GetGoggleEntry(o->weapons);
    int v = 0;
    void* mgr = g_Hud;
    if (e) v = e->b100;
    o->b346F = on ? v : 0;
    if (Has_199590(o) && o->active && o->b33E7) {
        cHud_ChangeGadgetState(mgr, v, on);
        if (!e) { o->b33E6 = 0; o->b33E7 = 0; }
    }
    cWeapon_SetHardpointActivation(o->weapons, 6, on);
    {
        V_199590 pos = o->GetPos();
        F2Ev_199590 ev;
        cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&ev, D_004F0DF0, &pos);
        ev.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
        ev.vt = D_004DAE30;
        cFileMan_dtor(&ev.s114, -1);
        cFileMan_dtor(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00199590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00199590 */

/* merge_units: begin func_00199700 */
#pragma push /* merge_units */
#pragma cplusplus on
struct P_00199700 { unsigned char b0; char pad[0x17]; int v18; };
struct A_00199700 { char pad[0x33EC]; P_00199700* p; };
extern "C" int cHuman_GetFlashlightGobj(A_00199700* a)
{
    bool ok = false;
    P_00199700* p = a->p;
    if (p && p->b0) ok = true;
    return ok ? p->v18 : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00199700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00199700 */

/* merge_units: begin func_00199740 */
#pragma push /* merge_units */
typedef struct { char pad0[0x33EC]; unsigned char* p; } O_199740;
unsigned char cHuman_FlashlightIsOn(O_199740* o)
{
    unsigned char r = 0;
    if (o->p != 0 && *o->p != 0) r = 1;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00199740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00199740 */

/* merge_units: begin func_00199770 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_lifetimes off
class C_199770 { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };
struct W_199770 { char pad[0x78]; int ammo; };
struct O_199770 { char pad[0x14]; unsigned char active; char pad15[0x58 - 0x15]; C_199770* ctl;
  char pad5C[0x33E6 - 0x5C]; unsigned char b33E6; unsigned char b33E7; char pad33E8[4]; unsigned char* state;
  char pad33F0[0x3524 - 0x33F0]; W_199770* weapons; };
extern "C" {
void cHuman_RequestEquipGoggles(O_199770* o, bool on, int f);
void cFlashlight_SetState(unsigned char* s, unsigned char on);
#if 0 /* merge_units */
void cHud_ChangeGadgetState(void* p, int a, unsigned char on);
#endif /* merge_units */
#define cHud_ChangeGadgetState(a0, a1, a2) (cHud_ChangeGadgetState((a0), (a1), (a2))) /* merge_units */

}
static inline unsigned char Has_199770(O_199770* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
extern "C" void cHuman_ToggleGadgetState(O_199770* o)
{
    if (o->b33E7) {
        cHuman_RequestEquipGoggles(o, !(o->b33E6 != 0), 0);
    } else {
        unsigned char on;
        unsigned char armed;
        on = !(*o->state != 0);
        armed = o->weapons->ammo > -1;
        if (!armed) on = 0;
        cFlashlight_SetState(o->state, on);
        if (Has_199770(o) && o->active && armed) cHud_ChangeGadgetState(g_Hud, 0, on);
    }
}
#undef cHud_ChangeGadgetState /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00199770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00199770 */

/* merge_units: begin func_00199860 */
#pragma push /* merge_units */
#pragma cplusplus on
class C_199860 { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };
struct E_199860 { char pad[0x100]; signed char b100; };
struct O_199860 { char pad[0x14]; unsigned char active; char pad15[0x58 - 0x15]; C_199860* ctl;
  char pad5C[0x33E5 - 0x5C]; unsigned char b33E5; unsigned char b33E6; unsigned char b33E7; char pad33E8[4]; unsigned char* state;
  char pad33F0[0x3524 - 0x33F0]; void* weapons; };
extern "C" {
#if 0 /* merge_units */
void cHuman_RequestEquipGoggles(O_199860* o, int on, int f);
#endif /* merge_units */
#define cHuman_RequestEquipGoggles(a0, a1, a2) (cHuman_RequestEquipGoggles((O_199770 *)(a0), (bool)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cFlashlight_SetState(unsigned char* s, int on);
#endif /* merge_units */
#define cFlashlight_SetState(a0, a1) (cFlashlight_SetState((a0), (unsigned char)(a1))) /* merge_units */

#if 0 /* merge_units */
E_199860* cWeapon_GetGoggleEntry(void* w);
#endif /* merge_units */
#define cWeapon_GetGoggleEntry(a0) ((E_199860 *)cWeapon_GetGoggleEntry((a0))) /* merge_units */

void cHud_ChangeGadget(void* p, int v);
}
static inline unsigned char Has_199860(O_199860* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
extern "C" void cHuman_CycleGadgetState(O_199860* o)
{
    unsigned char was = o->b33E7;
    if (was) {
        if (o->b33E5) return;
        if (o->b33E6 == 1) cHuman_RequestEquipGoggles(o, 0, 0);
        o->b33E7 = 0;
    } else if (cWeapon_GetGoggleEntry(o->weapons)) {
        o->b33E7 = 1;
        if (*o->state) cFlashlight_SetState(o->state, 0);
    }
    if (was != o->b33E7) {
        if (Has_199860(o) && o->active) {
            int v = 0;
            if (o->b33E7 && cWeapon_GetGoggleEntry(o->weapons)) v = cWeapon_GetGoggleEntry(o->weapons)->b100;
            cHud_ChangeGadget(g_Hud, v);
        }
    }
}
#undef cHuman_RequestEquipGoggles /* merge_units */
#undef cFlashlight_SetState /* merge_units */
#undef cWeapon_GetGoggleEntry /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00199860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00199860 */
