/*
 * SFOGame/Source/gameCamera: 2 files, 0017F480-0017F520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017F480 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_F480 { float v; float s; Key_F480() {} };
struct Crv_F480 { Key_F480 k[2]; float dur; float inv; };
static inline Crv_F480* Init_F480(Crv_F480* c, float* a, float* b, float dur)
{
    float va = *a; float vs = *b * dur;
    { Key_F480* e = c->k; do { new (e) Key_F480; } while (++e != c->k + 2); }
    c->k[0].v = va;
    c->k[0].s = vs;
    c->k[1].v = va;
    c->k[1].s = vs;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
struct Phys_F480 { void* vt; float a; float b; float c; float d; int x14; Crv_F480 crv; Crv_F480* cur; int x34; };
extern "C" char D_004DA380[];
/* constructor: vtable, initial values from a/b, an inline constant curve (zero duration) */
#pragma push
#pragma opt_unroll_loops off
extern "C" Phys_F480* cSplinedMotion_float_ctor_floatR_floatR(Phys_F480* p, float* a, float* b)
{
    p->vt = D_004DA380;
    p->a = *a;
    p->b = *a;
    p->c = *b;
    p->d = *a;
    p->x14 = 0;
    {
        Crv_F480* c = &p->crv;
        Init_F480(c, a, b, 0.0f);
    }
    p->cur = &p->crv;
    p->x34 = 0;
    return p;
}
#pragma pop
static inline void merge_flush_func_0017F480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F480 */

/* merge_units: begin func_0017F520 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cSplinedMotion_cVector_ctor: set up a vector camera curve from v0 toward v1: vtable, the
 * from/current/target/start values, t = 0, the two-key spline (cHermiteSpline_cVector_ctor_cVectorR_cVectorR) built from
 * v0 and v1 scaled by 0 (cVector_opMul), and its cursor reset to the first key (clone of
 * cSplinedMotion_cQuaternion_ctor). */
struct V4 { float x, y, z, w; V4() {} } __attribute__((aligned(16)));
struct Keys_F520 { V4 e[4]; };
struct KeySet_F520 { Keys_F520 keys; int count; int cur; };
struct CamCurve_F520 {
    void* vt;
    char pad4[0xC];
    V4 from;          /* +0x10 */
    V4 now;           /* +0x20 */
    V4 to;            /* +0x30 */
    V4 start;         /* +0x40 */
    float t;          /* +0x50 */
    char pad54[0xC];
    KeySet_F520 set;  /* +0x60, 0x50 bytes with alignment */
    KeySet_F520* it;  /* +0xB0 */
    int itIndex;      /* +0xB4 */
};
extern "C" {
extern char D_004DA3B0[];
V4 cVector_opMul(const V4* b, float s);
Keys_F520* cHermiteSpline_cVector_ctor_cVectorR_cVectorR(Keys_F520* m, const V4* a, const V4* b);
CamCurve_F520* cSplinedMotion_cVector_ctor(CamCurve_F520* c, const V4* q0, const V4* q1);
}
/* 16-byte lq/sq copy macro */
#define QCOPY(d, s) { const V4* s_ = (s); V4* d_ = (d); __int128 q_; asm volatile { lq q_, 0(s_); sq q_, 0(d_) } }
CamCurve_F520* cSplinedMotion_cVector_ctor(CamCurve_F520* c, const V4* q0, const V4* q1)
{
    c->vt = D_004DA3B0;
    QCOPY(&c->from, q0)
    QCOPY(&c->now, q0)
    QCOPY(&c->to, q1)
    QCOPY(&c->start, q0)
    c->t = 0.0f;
    {
        KeySet_F520* k = &c->set;
        V4 z = cVector_opMul(q1, 0.0f);
        cHermiteSpline_cVector_ctor_cVectorR_cVectorR(&k->keys, q0, &z);
        k->count = 0;
        k->cur = 0;
    }
    c->it = &c->set;
    c->itIndex = 0;
    return c;
}
static inline void merge_flush_func_0017F520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F520 */
