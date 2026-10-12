#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
static inline bool Not(unsigned char v) { return !(v != 0); }
struct Phys { char pad[0xDC]; unsigned char bDC; };
struct Actor {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e)
    virtual void Damage(Actor* src, int a, int b, int c, int d, int e, float amt);
    VPAD1(f)
    virtual unsigned char GetState();
    char pad4[0x10];
    unsigned char active;
    char pad15[0x40 - 0x15];
    float x40;
    char pad44[0x30A4 - 0x44];
    float lastY;
    float fallDist;
    char pad30AC[0x3210 - 0x30AC];
    int flags;
    char pad3214[0x3290 - 0x3214];
    void* root;
    char pad3294[0x3310 - 0x3294];
    Phys* phys;
    char pad3314[0x3398 - 0x3314];
    int x3398;
    char pad339C[0x33A5 - 0x339C];
    unsigned char b33A5;
    bool InWater() {
        bool r = false;
        if (phys && phys->bDC) r = true;
        return r;
    }
    bool Bit21() { return Not(Not((flags >> 21) & 1)); }
    bool IsDown() { unsigned char s = GetState(); return s == 2 || s == 3; }
};
extern "C" {
extern void* Root_GetWorldPlacement(void*);
extern float* Placement_GetPosition(void*);
extern float D_0049CEF0;
extern float D_0049CEF8;
extern float D_0049CF00;
extern float D_0049CF08;
extern float D_0049CF18;
}
extern "C" void Actor_UpdateFallState(Actor* a, int resetY)
{
    if (a->active) {
        float* p = Placement_GetPosition(Root_GetWorldPlacement(a->root));
        float d = a->lastY - p[2];
        if (a->InWater()) {
            if (d > D_0049CF18) {
                if (!a->IsDown())
                    a->Damage(a, 1, 0xF, 0, 0, 0, (float)(int)a->x40);
            }
        } else {
            bool c = a->Bit21() || a->Bit21() || a->b33A5;
            float lo = c ? D_0049CF00 : D_0049CEF0;
            float hi = c ? D_0049CF08 : D_0049CEF8;
            if (d > 0.0f) {
                a->fallDist = d;
                if (d > lo) {
                    float amt;
                    if (d > hi)
                        amt = (float)(int)a->x40;
                    else
                        {
                            float t = (d - lo) * (1.0f / (hi - lo));
                            amt = t * (float)a->x3398;
                        }
                    a->Damage(a, 1, 0xC, 0, 0, 0, amt);
                }
            }
        }
    }
    if (a->InWater()) {
        if (resetY)
            a->lastY = Placement_GetPosition(Root_GetWorldPlacement(a->root))[2];
    } else {
        a->lastY = -3.4028235e38f;
    }
}



