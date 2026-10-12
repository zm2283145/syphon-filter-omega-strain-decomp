#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C_199860 { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };
struct E_199860 { char pad[0x100]; signed char b100; };
struct O_199860 { char pad[0x14]; unsigned char active; char pad15[0x58 - 0x15]; C_199860* ctl;
  char pad5C[0x33E5 - 0x5C]; unsigned char b33E5; unsigned char b33E6; unsigned char b33E7; char pad33E8[4]; unsigned char* state;
  char pad33F0[0x3524 - 0x33F0]; void* weapons; };
extern "C" {
void Goggles_SetMode(O_199860* o, int on, int f);
void Flashlight_SetState(unsigned char* s, int on);
E_199860* WeaponInv_GetSlot6Record(void* w);
void Hud_SetGoggles(void* p, int v);
extern void* D_004FFC2C;
}
static inline unsigned char Has_199860(O_199860* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
extern "C" void Goggles_Toggle(O_199860* o)
{
    unsigned char was = o->b33E7;
    if (was) {
        if (o->b33E5) return;
        if (o->b33E6 == 1) Goggles_SetMode(o, 0, 0);
        o->b33E7 = 0;
    } else if (WeaponInv_GetSlot6Record(o->weapons)) {
        o->b33E7 = 1;
        if (*o->state) Flashlight_SetState(o->state, 0);
    }
    if (was != o->b33E7) {
        if (Has_199860(o) && o->active) {
            int v = 0;
            if (o->b33E7 && WeaponInv_GetSlot6Record(o->weapons)) v = WeaponInv_GetSlot6Record(o->weapons)->b100;
            Hud_SetGoggles(D_004FFC2C, v);
        }
    }
}