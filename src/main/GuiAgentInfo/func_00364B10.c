/* Retail reloads the clamp constants each time and keeps 0.5f in one register: CSE and propagation off. */
#pragma opt_common_subs off
#pragma opt_propagation off
#include "types.h"

typedef struct {
    char pad0[4];
    float f4;
    float f8;
    float fC;
    float f10;
    char pad14[4];
    float f18;
    char pad1C[4];
    float f20;
    char pad24[4];
    float f28;
    char pad2C[0x38 - 0x2C];
    unsigned char b38;
} A364B10;

extern float Math_FMod(float, float);
extern void func_0017CA90(float* p, int a);
extern void* Mem_PlacementNew(int type, float* p);
extern void cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(void* r, float* a, float* b, float* c, void* d, float e);
extern char D_00492EE0[];

static inline float clamp01(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }

static inline float Wrap01(A364B10* p, float t)
{
    float r;
    if (!p->b38) {
        r = clamp01(t, 0.0f, 1.0f);
    } else {
        r = Math_FMod(t, 1.0f);
        if (r < 0.0f) r += 1.0f;
    }
    return r;
}

static inline float WrapDelta(A364B10* p, float d)
{
    float r;
    float h;
    if (!p->b38) {
        return d;
    }
    r = Math_FMod(d, 1.0f);
    h = 0.5f;
    if (r < h) {
        r += 1.0f;
    } else if (r > h) {
        r -= 1.0f;
    }
    return r;
}

/* Advance the anim channel times by *dt, clamp or wrap them, then apply to the target. */
void func_00364B10(A364B10* p, float* dt)
{
    float d;
    p->f4 += *dt;
    p->f8 += *dt;
    p->f10 += *dt;
    p->f18 += *dt;
    p->f20 += *dt;
    p->f4 = Wrap01(p, p->f4);
    p->f8 = Wrap01(p, p->f8);
    d = WrapDelta(p, p->f10 - p->f8);
    p->f10 = p->f8 + d;
    func_0017CA90(&p->f18, -1);
    {
        void* r = Mem_PlacementNew(0x18, &p->f18);
        if (r) cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(r, &p->f8, &p->fC, &p->f10, D_00492EE0, p->f28);
    }
}

