/*
 * SFOGame/Source/GuiAgentInfo: 2 files, 00364B10-00364D00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00364B10 */
#pragma push /* merge_units */
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

extern float Libc_Fmodf(float, float);
extern void func_0017CA90(float* p, int a);
extern void* opNew_uint_voidP(int type, float* p);
extern void cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(void* r, float* a, float* b, float* c, void* d, float e);
extern char D_00492EE0[];

static inline float clamp01(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }

static inline float Wrap01(A364B10* p, float t)
{
    float r;
    if (!p->b38) {
        r = clamp01(t, 0.0f, 1.0f);
    } else {
        r = Libc_Fmodf(t, 1.0f);
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
    r = Libc_Fmodf(d, 1.0f);
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
        void* r = opNew_uint_voidP(0x18, &p->f18);
        if (r) cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(r, &p->f8, &p->fC, &p->f10, D_00492EE0, p->f28);
    }
}
static inline void merge_flush_func_00364B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364B10 */

/* merge_units: begin func_00364D00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


float func_00364D00(void) {
    return 0.0f;
}

float func_00364D10(void) {
    return 0.0f;
}
static inline void merge_flush_func_00364D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364D00 */
