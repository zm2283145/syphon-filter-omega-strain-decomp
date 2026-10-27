/*
 * SFOGame/Source/taser: 3 files, 00264360-00264370
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00264360 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "taser_types.h"

/* &v->data[i] */
TaserEntry* std_vector_TaserPoint_opIndex(TaserVec* v, int i) {
    return &v->data[i];
}
static inline void merge_flush_func_00264360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00264360 */

/* merge_units: begin func_00264370 */
#pragma push /* merge_units */
typedef struct E264370 {
    char p0[0x10]; float f10; char p14[4]; float f18; char p1c[4];
    float f20; char p24[4]; float f28; char p2c[4]; float f30; float f34; char p38[8];
} E264370;
typedef struct { char p[0x14]; int n; E264370* d; } V264370;
extern float D_0048B110;
extern float D_0048B128;
extern float D_0048B138;
extern float D_0048B178;
extern float D_0048B1B8;
static inline float Abs264370(float x) { float r; asm { abs.s r, x } return r; }
static inline float Sign264370(float x) { return x > 0.0f ? 1.0f : -1.0f; }
static inline E264370* Get264370(V264370* v, int i) { return &v->d[i]; }
static inline float Calc264370(float k, float* p, float x, int flag)
{
    float d = k * -x;
    float sp = Sign264370(*p);
    float sd = Sign264370(d);
    if (sd != sp) d *= 2.0f;
    if (flag && Abs264370(d) < D_0048B128) d *= D_0048B138;
    return d;
}
#pragma opt_strength_reduction off
void cAirTaser_AddTension(V264370* v, float dt, int flag)
{
    int i;
    float k = D_0048B110 * dt;
    int n = v->n;
    for (i = 1; i < n - 1; i++) {
        E264370* e = Get264370(v, i);
        float* p = &e->f20;
        float d = Calc264370(k, p, e->f10, flag);
        {
            float a = Abs264370(d * D_0048B178);
            float lo = D_0048B1B8;
            float hi = 1.0f;
            asm {
                max.s a, a, lo
                min.s a, a, hi
            }
            Get264370(v, i)->f30 = Get264370(v, i)->f34 = a;
        }
        *p += d;
        e = Get264370(v, i);
        p = &e->f28;
        d = Calc264370(k, p, e->f18, flag);
        *p += d;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00264370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00264370 */

/* merge_units: begin func_00264530 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

/* lq/sq quad copies and VU0 vector ops as GCC-style volatile asm; the unused xx keeps retail's dead addiu.
   axis/up are declared before the scoped d so the stack slots match (up at 0x80, d at 0x70). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    V() {}
    void Set(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { Q16(this, &o); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline void VSub(V* c, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(c), "r"(a), "r"(b) : "memory"); }
struct M {
    V r[3]; V t;
    void Apply(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
};
struct Pt { V pos; V src; char pad[0x20]; };
struct Path {
    char pad[0x14];
    int n;
    Pt* p;
    char pad1C[0x60 - 0x1C];
    M m;
    Pt*& P() { return p; }
};
extern "C" {
V* cVector_ctor_float_float_float_float(V* v, float x, float y, float z, float w);
void cVector_GetNormalized_void(V* out, V* v);
void cVector_Cross(V* out, V* a, V* b);
V* cVector_Normalize_void(V* v);
V* cVector_ctor_cVectorR(V* d, V* s);
int cVector_IsZeroXYZ(V* v);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M* m, V* a, V* b, V* c, V* t);
void cMatrix_MakeLookAtMatrix_cVectorR(M* m, V* axis);
void cMatrix_SetUnit(M* m);
}
extern "C" void cAirTaser_PointsToWorld(Path* s, V* org)
{
    s->p[0].pos = *org;
    V axis;
    V up;
    {
        V d;
        VSub(&d, &(&s->P()[s->n])[-1].pos, &s->P()[0].pos);
        axis = d;
    }
    up.Set(0.0f, 0.0f, 1.0f, 1.0f);
    {
        V c;
    cVector_Cross(&c, &axis, &up);
    if (!cVector_IsZeroXYZ(&c)) {
        V f;
        V r;
        V u;
        V w;
        cVector_GetNormalized_void(&f, &axis);
        cVector_ctor_cVectorR(&r, cVector_Normalize_void(&c));
        cVector_Cross(&u, &r, &f);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(&s->m, &r, &f, &u, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(&axis)) {
        cMatrix_MakeLookAtMatrix_cVectorR(&s->m, &axis);
    } else {
        cMatrix_SetUnit(&s->m);
    }
    }
    V* t = &s->m.t; *t = s->P()[0].pos;
    int n = s->n;
    for (int i = 0; i < n; i++) {
        s->P()[i].pos = s->P()[i].src;
        s->m.Apply(&s->P()[i].pos);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00264530(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00264530 */
