/*
 * SFOGame/Source/gameCamera: 10 files, 0017DBF0-0017DEA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017DBF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cHermiteSplineControlPoint_cVector_Tangent(char* self) {
    return self + 16;
}
static inline void merge_flush_func_0017DBF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017DBF0 */

/* merge_units: begin func_0017DC00 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4 opMul(V4* b, float s) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(b)
        mfc1 b, s
        qmtc2.ni b, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(q1)
        .set reorder
    }
    return l0;
}
static inline void merge_flush_func_0017DC00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017DC00 */

/* merge_units: begin func_0017DC30 */
#pragma push /* merge_units */
void* cHermiteSplineControlPoint_cVector_Position(void* self) {
    return self;
}

/* Address of 32-byte element i. */
char* cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(char* base, int i) {
    return base + (i << 5);
}

float cHermiteSplineWithScaledDuration_cVector_Duration(char* self) {
    return *(float*)(self + 64);
}
static inline void merge_flush_func_0017DC30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017DC30 */

/* merge_units: begin func_0017DC60 */
#pragma push /* merge_units */
#include "vu0_scale_eq.h"
#pragma push
#pragma peephole off
#pragma opt_propagation off
CURVE_RETIME_FUNC(cSplinedMotion_cVector_RestartTransition)
#pragma pop
static inline void merge_flush_func_0017DC60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017DC60 */

/* merge_units: begin func_0017DD00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


float nGameUnits_Sec(float f12) {
    return f12;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017DD00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017DD00 */

/* merge_units: begin func_0017DD10 */
#pragma push /* merge_units */
#pragma peephole off
typedef struct { char pad[0x40]; Vec4 v; } S;
/* Sets the curve's target vector (+0x40). */
void cSplinedMotion_cVector_SetTargetVal(S* dst, Vec4* src) { dst->v = *src; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017DD10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017DD10 */

/* merge_units: begin func_0017DD20 */
#pragma push /* merge_units */
typedef struct { float x, y, z; } Vec3_0017DD20;
extern float Libc_Cosf(float a);
extern float Libc_Sinf(float a);
/* cMatrix_ctor_cEulerAngleTR: rotation matrix from Euler angles (x, y, z), the
 * y-first variant of cMatrix_ctor_cEulerAngleTR_2. */
Mtx44* cMatrix_ctor_cEulerAngleTR(Mtx44* m, Vec3_0017DD20* angles)
{
    /* declaration order sets the saved FPR of each value (retail's f20-f24) */
    float czcy, cy, y, sz, szsy, z, sy, x, sx, cx, cz, czsy, szcy;
    y = angles->y;
    x = angles->x;
    z = angles->z;
    cy = Libc_Cosf(y);
    sy = Libc_Sinf(y);
    cx = Libc_Cosf(x);
    sx = Libc_Sinf(x);
    cz = Libc_Cosf(z);
    sz = Libc_Sinf(z);
    czsy = cz * sy;
    szcy = sz * cy;
    czcy = cz * cy;
    szsy = sz * sy;
    m->m[0][0] = czcy - szsy * sx;
    m->m[0][1] = szcy + czsy * sx;
    m->m[0][2] = -cx * sy;
    m->m[1][0] = -sz * cx;
    m->m[1][1] = cz * cx;
    m->m[1][2] = sx;
    m->m[2][0] = czsy + szcy * sx;
    m->m[2][1] = szsy - czcy * sx;
    m->m[2][2] = cx * cy;
    m->m[0][3] = 0.0f;
    m->m[1][3] = 0.0f;
    m->m[2][3] = 0.0f;
    m->m[3][0] = 0.0f;
    m->m[3][1] = 0.0f;
    m->m[3][2] = 0.0f;
    m->m[3][3] = 1.0f;
    return m;
}
static inline void merge_flush_func_0017DD20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017DD20 */

/* merge_units: begin func_0017DE50 */
#pragma push /* merge_units */
typedef struct Float3 {
    float x, y, z;
} Float3;

extern int Libc_Rand(void);

Float3* cEulerAngle_T_1_2_ctor_float_float_float(Float3* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

int RAND(void) {
    return Libc_Rand();
}

float cCameraShake_cPulsedShakeMagnitude_GetCurrVal(char* self) {
    return *(float*)(self + 8);
}

void* cSplinedMotion_float_GetCurrVal(char* self) {
    return self + 8;
}
static inline void merge_flush_func_0017DE50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017DE50 */

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
