/* Actor_UpdateJumpApex (001A2C00). Volatile reads keep retail's reloads of f3248/ledge with CSE on;
   the class-typed ternary with a cast temporary reproduces the unaligned else-arm. */
#pragma cplusplus on
#include "vslot_pad.h"

struct V4 { float x, y, z, w; V4() {} };

struct Ledge {
    char p0[0x12];
    unsigned char b12;
    unsigned char b13;
    char p14[0xDC - 0x14];
    unsigned char bDC;
    unsigned char bDD;
    char pDE[0x2C4 - 0xDE];
    float f2C4;
    char p2C8[0x310 - 0x2C8];
    V4 v310;
    char p320[0x700 - 0x320];
    unsigned char b700;
    unsigned char b701;
};

class Obj58 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int Busy();
};

class ActorV {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V4 GetE4();
    VPAD8(f)
    virtual unsigned char Get108();
};

struct Act : ActorV {
    char p4[0x14 - 4];
    unsigned char b14;
    char p15[0x58 - 0x15];
    Obj58* obj58;
    char p5C[0x30A0 - 0x5C];
    float f30A0;
    char p30A4[0x320C - 0x30A4];
    int state;
    int f3210;
    char p3214[0x3248 - 0x3214];
    union { int f3248; struct { unsigned g0:3; unsigned g3:1; unsigned g4:6; unsigned g10:1; unsigned g11:1; unsigned g12:1; unsigned g13:1; unsigned g14:1; unsigned g15:17; } gb; };
    char p324C[0x3310 - 0x324C];
    Ledge* ledge;
    char p3314[0x34D8 - 0x3314];
    float f34D8;
};

extern "C" {
void Actor_ComputeJumpTarget(Act* a);
void Actor_CatchLedgeInAir(Act* a);
void Actor_LandFromAir(Act* a, int f);
void Actor_StartFall(Act* a);
void Actor_UpdateFallState(Act* a, bool f);
void Actor_LandDead(Act* a, int f);
V4* Vec4_Assign(V4* d, V4* s);
V4* Vec4_GetZero(void);

extern float D_0049CEE0;
extern float D_0049CEE8;
extern float D_0049CF20;
extern float D_0049CF28;
extern float D_0049CF30;
extern signed char D_004E1D88;
extern float D_004E1D90;
extern float D_004E1D94;
extern float D_004E1D98;
extern float D_004E1D9C;
}

static inline V4* LedgeVel(Act* a)
{
    Ledge* l = *(Ledge* volatile*)&a->ledge;
    if (l) return &l->v310;
    if (!D_004E1D88) {
        D_004E1D90 = 0.0f;
        D_004E1D88 = 1;
        D_004E1D94 = 0.0f;
        D_004E1D98 = 0.0f;
        D_004E1D9C = 0.0f;
    }
    return (V4*)&D_004E1D90;
}

static inline bool R7(int m) { return m == 2 || m == 3; }
static inline bool LedgeDD(Act* a)
{
    bool r = false;
    Ledge* l = a->ledge; if (l && l->bDD) r = true;
    return r;
}

static inline bool LedgeDC(Act* a)
{
    bool r = false;
    Ledge* l = *(Ledge* volatile*)&a->ledge; if (l && l->bDC) r = true;
    return r;
}

struct VT { float x, y, z, w; VT() {} VT(const VT& o) { Vec4_Assign((V4*)this, (V4*)&o); } };
extern "C" VT cHumanCollisionRoutine_PredictNextVelocity(Ledge* l, float dt);

extern "C" void Actor_UpdateJumpApex(Act* a, float dt)
{
    if (a->ledge == 0) return;
    if ((*(volatile int*)&a->f3248 >> 14) & 1) {
        a->f3248 &= ~0x4000;
        if ((a->f3210 >> 4) & 1) Actor_ComputeJumpTarget(a);
    }
    {
        int g;unsigned char skip; skip = (a->f3210 >> 4) & 1;
        if (!skip) {
            if ((a->f3210 >> 5) & 1) {
                g = a->f3248;
                if ((g >> 10) & 1) {
                    skip = R7(a->Get108());
                    if (!skip) {
                        float h;
                        Ledge* l = a->ledge;
                        VT t70 = l ? cHumanCollisionRoutine_PredictNextVelocity(l, dt) : *(VT*)Vec4_Assign((V4*)&(const VT&)VT(), Vec4_GetZero());
                        h = t70.z;
                        V4 t60 = a->GetE4();
                        if (h <= a->f34D8) Actor_CatchLedgeInAir(a);
                    }
                } else if (((g >> 11) & 1) || ((g >> 12) & 1)) {
                    if (!skip) {
                        if (LedgeVel(a)->z <= 0.0f) {
                            if (LedgeDD(a)) Actor_LandFromAir(a, 1);
                            else Actor_StartFall(a);
                        }
                    }
                }
            } else if ((a->f3210 >> 10) & 1) {
                if (LedgeDD(a)) Actor_LandFromAir(a, 1);
            } else {
                
                if (a->state != 0) {
                    if (!((a->f3210 >> 2) & 1) || !((a->f3248 >> 3) & 1)) {
                        if (!((a->f3210 >> 9) & 1)) {
                            if (a->state != 0x1B && a->state != 0x1F) goto done;
                            if ((a->f3210 >> 29) & 1) goto done;
                        }
                    }
                }
                if (((a->f3210 >> 9) & 1) && LedgeDD(a)) {
                    Actor_LandFromAir(a, 1);
                } else if (!(a->f30A0 <= D_0049CEE0) && !(a->ledge->f2C4 <= D_0049CEE8)) {
                    float lim = (a->state == 0x1B || a->state == 0x1F) ? (a->state == 0x1F ? D_0049CF28 : D_0049CF30) : D_0049CF20;
                    if (LedgeVel(a)->z < lim) {
                        a->f3248 &= ~0x400;
                        a->f3248 &= ~0x800;
                        a->f3248 &= ~0x1000;
                        a->f3248 &= ~0x2000;
                        Actor_StartFall(a);
                    }
                }
            }
        }
    }
done:
    {
        bool on;
        Ledge* l = a->ledge;
        if (l && l->b12 && l->b13 && LedgeDC(a)) {
            if (a->f30A0 == 0.0f) on = 1; else on = 0;
            a->f30A0 += dt;
        } else {
            a->f30A0 = 0.0f;
            on = false;
        }
        Actor_UpdateFallState(a, on);
    }
    Actor_LandDead(a, 0);
    if (!a->b14) {
        bool busy = false;
        Obj58* o = a->obj58; if (o && o->Busy()) busy = true;
        if (busy) return;
    }
    if (a->state == 0xA) {
        Ledge* l = a->ledge;
        l->b701 = 0;
        l->b700 = 1;
    }
}























