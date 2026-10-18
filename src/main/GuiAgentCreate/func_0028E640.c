#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)

/* Camera preset blend: eases the current camera preset toward the selected table entry. */

extern "C" {
float Math_StepEighth(float* p, float a, float b);
float Math_StepAngleEighth(float target, float cur, float* maxStep);
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
    char pad0[0x70];
    CamOwner* owner;
    char pad74[0x80 - 0x74];
    CamE cur;
    char padB0[0xC0 - 0xB0];
    int c0;
    char padC4[0xD0 - 0xC4];
    int d0;
    char padD4[0xED - 0xD4];
    signed char ed;
};
static inline void GetE(CamT* t, CamE& o) {
    if (t->d0 == 0) o = D_0055DDA0.e[t->owner->sel[t->ed]];
    else o = D_0055DDA0.e[0];
}

extern "C" void GuiAgentCreate_CameraApproach(CamT* t)
{
    if (t->c0) {
        float acc = 0.0f;
        CamE e; GetE(t, e);
        t->cur.f0 = Math_StepEighth(&acc, e.f0, t->cur.f0);
        t->cur.f1 = Math_StepEighth(&acc, e.f1, t->cur.f1);
        t->cur.f2 = Math_StepEighth(&acc, e.f2, t->cur.f2);
        t->cur.f3 = Math_StepEighth(&acc, e.f3, t->cur.f3);
        t->cur.f4 = Math_StepAngleEighth(e.f4, t->cur.f4, &acc);
        t->cur.f5 = Math_StepAngleEighth(e.f5, t->cur.f5, &acc);
        t->cur.f6 = Math_StepAngleEighth(e.f6, t->cur.f6, &acc);
        t->c0++;
        if (acc < 0.0001f) {
            t->c0 = 0;
            GetE(t, t->cur);
        }
    }
}
