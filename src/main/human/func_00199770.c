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
void func_001992B0(O_199770* o, bool on, int f);
void func_0045B610(unsigned char* s, unsigned char on);
void func_00244A80(void* p, int a, unsigned char on);
extern void* D_004FFC2C;
}
static inline unsigned char Has_199770(O_199770* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
extern "C" void func_00199770(O_199770* o)
{
    if (o->b33E7) {
        func_001992B0(o, !(o->b33E6 != 0), 0);
    } else {
        unsigned char on;
        unsigned char armed;
        on = !(*o->state != 0);
        armed = o->weapons->ammo > -1;
        if (!armed) on = 0;
        func_0045B610(o->state, on);
        if (Has_199770(o) && o->active && armed) func_00244A80(D_004FFC2C, 0, on);
    }
}

