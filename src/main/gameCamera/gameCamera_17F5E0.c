/*
 * main/gameCamera: range (2 files, 0017F5E0-0017F670)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"

/* merge_units: begin func_0017F5E0 */
#pragma push /* merge_units */
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
V4 Vec4_Scale(V4* b, float s) {
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
