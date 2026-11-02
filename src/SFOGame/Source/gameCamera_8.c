/*
 * SFOGame/Source/gameCamera: 3 files, 0017F5E0-0017F6A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017F5E0 */
#pragma push /* merge_units */
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"

/* cHermiteSpline_cVector_ctor_cVectorR_cVectorR: sub-object ctor (2 x {V4 p,q}) filled from two by-pointer V4s. Hand-matched (auto1 family seed).
 * The empty asm block is a scheduling barrier reproducing retail order. */
#pragma cplusplus on
inline void* operator new(unsigned int, void* p) { return p; }
struct V4_F5E0 { float x, y, z, w; } __attribute__((aligned(16)));
struct E_F5E0 { V4_F5E0 p; V4_F5E0 q; E_F5E0() {} };
struct M_F5E0 { E_F5E0 e[2]; };
#pragma opt_rotateloops off
#pragma opt_unroll_loops off
extern "C" M_F5E0* cHermiteSpline_cVector_ctor_cVectorR_cVectorR(M_F5E0* m, const V4_F5E0* a, const V4_F5E0* b)
{
    V4_F5E0 tb; V4_F5E0 ta;
    V4_F5E0* pa; E_F5E0* pe; V4_F5E0* pb;
    pa = &ta;
    VCopyF(pa, a);
    pb = &tb;
    asm { .set noreorder; .set reorder }
    pe = m->e;
    VCopyF(pb, b);
    do { new (pe) E_F5E0; } while (++pe != m->e + 2);
    {
    int i = 0;
    while (i <= 1) {
        E_F5E0* e = &m->e[i++];
        VCopyF(&e->p, &ta);
        VCopyF(&e->q, &tb);
    }
    }
    return m;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017F5E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017F5E0 */

/* merge_units: begin func_0017F670 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4 cVector_opMul(V4* b, float s) {
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017F670(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017F670 */

/* merge_units: begin func_0017F6A0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cSplinedMotion_cQuaternion_ctor: set up a quaternion camera curve from q0 toward q1: vtable, the
 * from/current/target/start orientations, t = 0, the two-key spline (cHermiteSpline_cQuaternion_ctor_cQuaternionR_cQuaternionR) built from
 * q0 and q1 scaled by 0 (cQuaternion_opMul_float), and its cursor reset to the first key. */
struct V4_0017F6A0 { float x, y, z, w; V4_0017F6A0() {} } __attribute__((aligned(16)));
struct Keys_F6A0 { V4_0017F6A0 e[4]; };
struct KeySet_F6A0 { Keys_F6A0 keys; int count; int cur; };
struct CamCurve_F6A0 {
    void* vt;
    char pad4[0xC];
    V4_0017F6A0 from;          /* +0x10 */
    V4_0017F6A0 now;           /* +0x20 */
    V4_0017F6A0 to;            /* +0x30 */
    V4_0017F6A0 start;         /* +0x40 */
    float t;          /* +0x50 */
    char pad54[0xC];
    KeySet_F6A0 set;  /* +0x60, 0x50 bytes with alignment */
    KeySet_F6A0* it;  /* +0xB0 */
    int itIndex;      /* +0xB4 */
};
extern "C" {
extern char D_004DA350[];
V4_0017F6A0 cQuaternion_opMul_float(const V4_0017F6A0* b, float s);
Keys_F6A0* cHermiteSpline_cQuaternion_ctor_cQuaternionR_cQuaternionR(Keys_F6A0* m, const V4_0017F6A0* a, const V4_0017F6A0* b);
CamCurve_F6A0* cSplinedMotion_cQuaternion_ctor(CamCurve_F6A0* c, const V4_0017F6A0* q0, const V4_0017F6A0* q1);
}
/* 16-byte lq/sq copy macro */
#define QCOPY(d, s) { const V4_0017F6A0* s_ = (s); V4_0017F6A0* d_ = (d); __int128 q_; asm volatile { lq q_, 0(s_); sq q_, 0(d_) } }
CamCurve_F6A0* cSplinedMotion_cQuaternion_ctor(CamCurve_F6A0* c, const V4_0017F6A0* q0, const V4_0017F6A0* q1)
{
    c->vt = D_004DA350;
    QCOPY(&c->from, q0)
    QCOPY(&c->now, q0)
    QCOPY(&c->to, q1)
    QCOPY(&c->start, q0)
    c->t = 0.0f;
    {
        KeySet_F6A0* k = &c->set;
        V4_0017F6A0 z = cQuaternion_opMul_float(q1, 0.0f);
        cHermiteSpline_cQuaternion_ctor_cQuaternionR_cQuaternionR(&k->keys, q0, &z);
        k->count = 0;
        k->cur = 0;
    }
    c->it = &c->set;
    c->itIndex = 0;
    return c;
}
static inline void merge_flush_func_0017F6A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F6A0 */
