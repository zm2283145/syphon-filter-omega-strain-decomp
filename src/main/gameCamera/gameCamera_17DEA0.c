/*
 * main/gameCamera: range (2 files, 0017DEA0-0017DFF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0017DEA0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; float f10; } DSeg;
class DCurve {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(float, float);
    float f4; float f8; float fC; float f10; float f14;
    float f18; float f1C; float f20; float f24; float f28; float f2C;
    DSeg* f30; float f34; float f38; float f3C;
};
static const float dat_0048A168[2] = { 0.0f, 0.0f };
extern "C" int cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_NextFrame(void*, float);
extern "C" int cSplinedMotion_float_IsTransitionInProgress(void*);
extern "C" float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Evaluate(void*);
extern "C" void cCameraShake_cPulsedShakeMagnitude_NextFrame(DCurve* p, float dt, float b) {
    if (!(p->f38 <= 0.0f)) {
        p->f38 -= dt;
        if (p->f38 <= 0.0f) {
            float t;
            p->f38 = 0.0f;
            p->f10 = (*(float*)dat_0048A168);
            t = p->f3C;
            if (!(t < 0.0f)) {
                float r = t * p->f2C;
                p->f1C *= r;
                p->f24 *= r;
                p->f28 = t;
                {
                    p->f2C = (0.0f != t) ? 1.0f / t : 0.0f;
                }
                p->f34 = p->f30->f10;
            }
        }
    }
    p->f4 = p->f8;
    p->v4();
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_NextFrame(&p->f30, dt);
    if (cSplinedMotion_float_IsTransitionInProgress(p)) {
        p->f8 = cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Evaluate(&p->f30);
        p->v5();
    } else {
        p->f8 = p->f10;
    }
    p->v6(dt, b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017DEA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017DEA0 */

/* merge_units: begin func_0017DFF0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float p0, m0, p1, m1, t1, inv; } SSeg;
class SCurve {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(float, float);
    float f4; float f8; float fC; float f10; float f14;
    float f18; float f1C; float f20; float f24; float f28; float f2C;
    SSeg* seg; float t;
};
static inline float SC_Max(float a, float b) {
    float r;
    asm {
        mov.s r, a
        max.s r, b, r
    }
    return r;
}
static inline bool SC_CountDown(SCurve* p, float dt) {
    float old = p->t;
    p->t -= dt;
    p->t = SC_Max(p->t, 0.0f);
    return old > 0.0f && p->t == 0.0f;
}
static inline bool SC_HasRemaining(SCurve* c) { return !(c->t == 0.0f); }
static inline float SC_Hermite(SCurve* c) {
    SSeg* s = c->seg;
    float t2, t3, t;
    float h0, h1, h2, h3;
    float d = s->t1 - c->t;
    if (0.0f != s->t1) {
        t = d * s->inv;
    } else {
        t = 1.0f;
    }
    t2 = t * t;
    t3 = t2 * t;
    h0 = 1.0f + (2.0f * t3 - 3.0f * t2);
    h1 = -2.0f * t3 + 3.0f * t2;
    h2 = t + (t3 - 2.0f * t2);
    h3 = t3 - t2;
    return h0 * s->p0 + h1 * s->p1 + h2 * s->m0 + h3 * s->m1;
}
extern "C" bool cSplinedMotion_float_NextFrame(SCurve* p, float dt, float b) {
    bool done;
    p->f4 = p->f8;
    p->v4();
    done = SC_CountDown(p, dt);
    if (SC_HasRemaining(p)) {
        p->f8 = SC_Hermite(p);
        p->v5();
    } else {
        p->f8 = p->f10;
    }
    p->v6(dt, b);
    return done;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017DFF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017DFF0 */
