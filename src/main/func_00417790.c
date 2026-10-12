#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct E_417790 { char name[0xC]; unsigned char kind; char pad[3]; int x; int y; };
struct I_417790 { int f0; float t; };
struct W_417790 {
    VPAD8(p) VPAD4(q)
    virtual void Update(float dt);
    char pad[0x10];
    unsigned short flags;
};
struct O_417790 {
    int f0;
    W_417790* w;
    char pad[0x1C];
    I_417790* inst;
    char pad28[0x58];
    E_417790* cur;
    bool Done();
};
extern "C" void func_003F43D0(I_417790* i, float dt);

inline bool O_417790::Done()
{
    if (cur == 0 || inst == 0 || cur->kind != 1 || (float)cur->y == inst->t) return true;
    return false;
}

extern "C" void func_00417790(O_417790* o, float dt)
{
    if (o->inst) func_003F43D0(o->inst, dt);
    {
        unsigned short& f = o->w->flags;
        if ((f & 0x10) && (f & 8)) {
            if (o->Done()) f &= ~8;
        }
    }
    o->w->Update(dt);
}
