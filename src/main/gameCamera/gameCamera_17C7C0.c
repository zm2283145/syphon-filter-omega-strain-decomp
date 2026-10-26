/*
 * main/gameCamera: range (4 files, 0017C7C0-0017C900)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "curve_count_down.h"

/* merge_units: begin func_0017C7C0 */
#pragma push /* merge_units */
typedef struct { float p0, m0, p1, m1, t1, inv; } B5dSeg;
typedef struct { B5dSeg* seg; float t; } B5dCurve;
float Curve_Hermite(B5dCurve* c) {
    B5dSeg* s = c->seg;
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017C7C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017C7C0 */

/* merge_units: begin func_0017C870 */
#pragma push /* merge_units */
typedef struct { char pad[0x34]; float f34; } A5_Curve;
int Curve_HasRemaining(A5_Curve* c) { return !(c->f34 == 0.0f); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017C870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017C870 */

/* merge_units: begin func_0017C8A0 */
#pragma push /* merge_units */
/* Count a curve's remaining time down to zero. */
DEFINE_CURVE_COUNT_DOWN(Curve_CountDown)
#pragma pop /* merge_units */
/* merge_units: end func_0017C8A0 */

/* merge_units: begin func_0017C900 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; float f10; } B4CurveTgt;
class B4Curve {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual float GetSpeed();
    float f4; float f8; float fC; float f10; float f14;
    char f18[8];
    float f20; float f24; float f28; float f2C;
    B4CurveTgt* tgt;
    float f34;
};
extern "C" void func_0017CA90(void*, int);
extern "C" void* Mem_PlacementNew(int, void*);
extern "C" void cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(float, void*, float*, float*, float*, float*);
static inline bool b4NonZero(float x) { return !(0.0f == x); }
extern "C" void Curve_Retarget(B4Curve* p) {
    unsigned char go = 0;
    if (p->f34 == p->tgt->f10 && !(p->f28 <= 0.0f)) go = 1;
    if (go) {
        float s[1];
        void* n;
        s[0] = p->GetSpeed();
        func_0017CA90(p->f18, -1);
        n = Mem_PlacementNew(0x18, p->f18);
        if (n) cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(p->f28, n, &p->f8, &p->fC, &p->f10, s);
    } else if (b4NonZero(p->f34)) {
        float s = p->GetSpeed();
        float v = s * p->f28;
        p->f20 = p->f10;
        p->f24 = v;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017C900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017C900 */
