#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)

/* Camera preset blend: eases the current camera preset toward the selected table entry. */

extern "C" {
float func_003FFA20(float* p, float a, float b);
float func_003FF970(float target, float cur, float* maxStep);
}
struct Fl { float v; Fl& operator=(const Fl& o) { v = o.v; return *this; } operator float() const { return v; } Fl& operator=(float x) { v = x; return *this; } };
struct CamE {
    char name[16];
    int id;
    Fl f0, f1, f2, f3, f4, f5, f6;
};
struct CamMgr { char pad[0x11C10]; CamE e[1]; };
extern "C" CamMgr D_0055DDA0;
struct CamOwner { char pad[0x2E10]; signed char sel[8]; };
struct CamT {
    char pad0[0x8C];
    CamOwner* owner;
    char pad90[0xA0 - 0x90];
    CamE cur;
    char padD0[0xE0 - 0xD0];
    int c0;
    char padE4[0xF0 - 0xE4];
    int d0;
    char padF4[0x10D - 0xF4];
    signed char ed;
};
static inline void GetE(CamT* t, CamE& o) {
    if (t->d0 == 0) o = D_0055DDA0.e[t->owner->sel[t->ed]];
    else o = D_0055DDA0.e[0];
}

extern "C" void func_003428D0(CamT* t)
{
    if (t->c0) {
        float acc = 0.0f;
        CamE e; GetE(t, e);
        t->cur.f0 = func_003FFA20(&acc, e.f0, t->cur.f0);
        t->cur.f1 = func_003FFA20(&acc, e.f1, t->cur.f1);
        t->cur.f2 = func_003FFA20(&acc, e.f2, t->cur.f2);
        t->cur.f3 = func_003FFA20(&acc, e.f3, t->cur.f3);
        t->cur.f4 = func_003FF970(e.f4, t->cur.f4, &acc);
        t->cur.f5 = func_003FF970(e.f5, t->cur.f5, &acc);
        t->cur.f6 = func_003FF970(e.f6, t->cur.f6, &acc);
        t->c0++;
        if (acc < 0.0001f) {
            t->c0 = 0;
            GetE(t, t->cur);
        }
    }
}
