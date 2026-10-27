/*
 * SFOGame/Source/gameCamera: 1 file, 0017F6A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017F6A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* cSplinedMotion_cQuaternion_ctor: set up a quaternion camera curve from q0 toward q1: vtable, the
 * from/current/target/start orientations, t = 0, the two-key spline (cHermiteSpline_cQuaternion_ctor_cQuaternionR_cQuaternionR) built from
 * q0 and q1 scaled by 0 (cQuaternion_opMul_float), and its cursor reset to the first key. */
struct V4 { float x, y, z, w; V4() {} } __attribute__((aligned(16)));
struct Keys_F6A0 { V4 e[4]; };
struct KeySet_F6A0 { Keys_F6A0 keys; int count; int cur; };
struct CamCurve_F6A0 {
    void* vt;
    char pad4[0xC];
    V4 from;          /* +0x10 */
    V4 now;           /* +0x20 */
    V4 to;            /* +0x30 */
    V4 start;         /* +0x40 */
    float t;          /* +0x50 */
    char pad54[0xC];
    KeySet_F6A0 set;  /* +0x60, 0x50 bytes with alignment */
    KeySet_F6A0* it;  /* +0xB0 */
    int itIndex;      /* +0xB4 */
};
extern "C" {
extern char D_004DA350[];
V4 cQuaternion_opMul_float(const V4* b, float s);
Keys_F6A0* cHermiteSpline_cQuaternion_ctor_cQuaternionR_cQuaternionR(Keys_F6A0* m, const V4* a, const V4* b);
CamCurve_F6A0* cSplinedMotion_cQuaternion_ctor(CamCurve_F6A0* c, const V4* q0, const V4* q1);
}
/* 16-byte lq/sq copy macro */
#define QCOPY(d, s) { const V4* s_ = (s); V4* d_ = (d); __int128 q_; asm volatile { lq q_, 0(s_); sq q_, 0(d_) } }
CamCurve_F6A0* cSplinedMotion_cQuaternion_ctor(CamCurve_F6A0* c, const V4* q0, const V4* q1)
{
    c->vt = D_004DA350;
    QCOPY(&c->from, q0)
    QCOPY(&c->now, q0)
    QCOPY(&c->to, q1)
    QCOPY(&c->start, q0)
    c->t = 0.0f;
    {
        KeySet_F6A0* k = &c->set;
        V4 z = cQuaternion_opMul_float(q1, 0.0f);
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
