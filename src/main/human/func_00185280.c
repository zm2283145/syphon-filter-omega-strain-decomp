#pragma cplusplus on
#include "types.h"
#define B7V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
struct B7_GObj {
    char pad0[0x4C];
    int type;
};
struct B7_Human {
    B7V8(a) B7V8(b) B7V8(c) B7V8(d) B7V8(e) B7V8(f) B7V8(g) B7V8(h)
    virtual unsigned char GetState(); /* +0x108 */
    char pad4[0x33BC - 4];
    float health;
};
extern "C" B7_GObj* GObj_IdentityB(int id);
extern "C" int D_0049D010;
extern "C" void Global_ShockToDeath(B7_Human* o, float a, float b, int c, int d);
extern "C" int Script_ShockToDeath(int* args)
{
    B7_GObj* o = GObj_IdentityB(args[0]);
    if (o && o->type == D_0049D010) {
        B7_Human* h = (B7_Human*)o;
        unsigned char s = h->GetState();
        bool dying = (s == 2 || s == 3);
        if (!dying && h->health < 0.0f) {
            Global_ShockToDeath(h, 0.5f, 10000.0f, 1, 1);
        }
    }
    return 0;
}