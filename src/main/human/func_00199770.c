#pragma cplusplus on
#pragma opt_lifetimes off
#include "types.h"
#include "vslot_pad.h"
class C_199770 { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };
struct W_199770 { char pad[0x78]; int ammo; };
struct O_199770 { char pad[0x14]; unsigned char active; char pad15[0x58 - 0x15]; C_199770* ctl;
  char pad5C[0x33E6 - 0x5C]; unsigned char b33E6; unsigned char b33E7; char pad33E8[4]; unsigned char* state;
  char pad33F0[0x3524 - 0x33F0]; W_199770* weapons; };
extern "C" {
void Goggles_SetMode(O_199770* o, bool on, int f);
void Flashlight_SetState(unsigned char* s, unsigned char on);
void Hud_SetFlashlightIcon(void* p, int a, unsigned char on);
extern void* D_004FFC2C;
}
static inline unsigned char Has_199770(O_199770* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
extern "C" void Flashlight_Toggle(O_199770* o)
{
    if (o->b33E7) {
        Goggles_SetMode(o, !(o->b33E6 != 0), 0);
    } else {
        unsigned char on;
        unsigned char armed;
        on = !(*o->state != 0);
        armed = o->weapons->ammo > -1;
        if (!armed) on = 0;
        Flashlight_SetState(o->state, on);
        if (Has_199770(o) && o->active && armed) Hud_SetFlashlightIcon(D_004FFC2C, 0, on);
    }
}

