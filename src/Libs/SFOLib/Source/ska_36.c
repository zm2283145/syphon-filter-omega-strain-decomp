/*
 * Libs/SFOLib/Source/ska: 8 files, 003B2250-003B2450
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B2250 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x180]; V4 v180; } B2250;
#pragma push
#pragma opt_common_subs off
#pragma peephole off
void cBone_AnimationAccumulateOffset(B2250* b, V4* d, float s) {
    V4* p = &b->v180;
    int t;
    /* VU0: p += d * s (xyz) */
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(d)
        mfc1 t, s
        qmtc2.ni t, vf3
        vaddax.xyz ACC, vf1, vf0x
        vmaddx.xyz vf1, vf2, vf3x
        sqc2 vf1, 0(p)
    }
    b->v180.w = 1.0f;
}
#pragma pop
static inline void merge_flush_func_003B2250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2250 */

/* merge_units: begin func_003B2290 */
#pragma push /* merge_units */
typedef struct { char pad[0x110]; V4 v[1]; } A_2290;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cSkaAnimAnchor_AccumulateDeltaPos(A_2290* a, V4* v, unsigned char i, float s) {
    V4 u;
    V4* d;
    V4* e;
    V4* p;
    {
        V4 r; int t; V4* q = &r;
        asm {
            .set noreorder
            lqc2 vf1, 0x0(v)
            mfc1 t, s
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(q)
            .set reorder
        }
        {
            V4* pd;
            __int128 t2;
            pd = &u;
            __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t2) : "r"(q));
            __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t2), "r"(pd) : "memory");
        }
    }
    p = &u; d = (V4*)((char*)&a->v[0] + (i << 4)); e = d;
    asm {
        lqc2 vf1, 0x0(e)
        lqc2 vf2, 0x0(p)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
#pragma pop
static inline void merge_flush_func_003B2290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2290 */

/* merge_units: begin func_003B22F0 */
#pragma push /* merge_units */
typedef struct { char pad[0xF0]; V4 v; } A_22F0;
static inline V4 Scale_(V4* v, float s) {
    V4 r; int t; V4* q = &r;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(q)
        .set reorder
    }
    return *q;
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cSkaAnimAnchor_AccumulatePos(A_22F0* a, V4* v, float s) {
    V4 u;
    V4* d;
    V4* e;
    V4* p;
    u = Scale_(v, s);
    d = &a->v; e = &a->v; p = &u;
    asm {
        lqc2 vf1, 0x0(e)
        lqc2 vf2, 0x0(p)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B22F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B22F0 */

/* merge_units: begin func_003B2340 */
#pragma push /* merge_units */
void cBone_AnimationAccumulateRotation(V4* a, V4* b, float s) {
    int rv1;
    a = (V4*)((char*)a + 0x190);
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddx.xyzw vf1, vf2, vf3x
        sqc2 vf1, 0x0(a)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B2340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B2340 */

/* merge_units: begin func_003B2370 */
#pragma push /* merge_units */
typedef struct { char pad[0xE0]; V4 acc; char pad2[0x60]; V4 q; } A_2370;
static inline float Dot_2370(V4* a, V4* b) {
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline V4 Scale_2370(V4* v, float s) {
    V4 r; int t; V4* q = &r;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(q)
        .set reorder
    }
    return *q;
}
static inline void ScaleTo_2370(V4* out, V4* v, float s) {
    V4 r; int t; V4* q = &r;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(q)
        .set reorder
    }
    {
        V4* pd;
        __int128 t2;
        pd = out;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t2) : "r"(q));
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t2), "r"(pd) : "memory");
    }
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cSkaAnimAnchor_AccumulateRot(A_2370* a, V4* v, unsigned char flag, float s) {
    if (!flag || Dot_2370(v, &a->q) >= 0.0f) {
        V4 u;
        V4* d;
        V4* e;
        V4* p;
        u = Scale_2370(v, s);
        d = &a->acc; e = &a->acc; p = &u;
        asm {
            lqc2 vf1, 0x0(e)
            lqc2 vf2, 0x0(p)
            vadd.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
    } else {
        V4 u;
        V4* d;
        V4* e;
        V4* p;
        ScaleTo_2370(&u, v, s);
        d = &a->acc; e = &a->acc; p = &u;        asm {
            lqc2 vf1, 0x0(e)
            lqc2 vf2, 0x0(p)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
    }
}
#pragma pop
static inline void merge_flush_func_003B2370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2370 */

/* merge_units: begin func_003B2450 */
#pragma push /* merge_units */
int cQuaternion_IsUnitQuatIdentity(int a0) {
    int v0, v1;
    float f0, f1;
    int cond, fcc;

    f1 = *(float*)((char*)a0 + 12);
    v1 = 0x3f800000;
    f0 = 1.0f;
    fcc = f0 == f1;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003B2470;
    v0 = 0;
L003B2470:;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B2450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B2450 */

/* merge_units: begin func_003B2480 */
#pragma push /* merge_units */
V4* cQuaternion_Negate(V4* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B2480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B2480 */

/* merge_units: begin func_003B24A0 */
#pragma push /* merge_units */
void cSkaAnim_Lerp(V4* a, V4* b, V4* c, V4* d, V4* e) {
    asm {
        lqc2 vf1, 0x0(c)
        lqc2 vf2, 0x0(d)
        lqc2 vf3, 0x0(e)
        vmulax.xyzw ACC, vf2, vf3x
        vmaddy.xyzw vf4, vf1, vf3y
        sqc2 vf4, 0x0(b)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B24A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B24A0 */
