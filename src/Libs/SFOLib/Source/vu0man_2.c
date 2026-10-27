/*
 * Libs/SFOLib/Source/vu0man: 4 files, 003C64C0-003C65C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C64C0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4* cLineSegment_Transform(V4* a, V4* b) {
    char* pv1;
    char* pv0;
    asm {
        lqc2 vf8, 0x0(a)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(a)
    }
    pv0 = (char*)a + 0x10;
    pv1 = (char*)a + 0x10;
    asm {
        lqc2 vf8, 0x0(pv0)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(pv1)
    }
    return a;
}
#pragma pop
static inline void merge_flush_func_003C64C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C64C0 */

/* merge_units: begin func_003C6520 */
#pragma push /* merge_units */
V4* cMatrix_LocalTransform(V4* a, V4* b) {
    asm {
        lqc2 vf4, 0x0(a)
        lqc2 vf5, 0x10(a)
        lqc2 vf6, 0x20(a)
        lqc2 vf7, 0x30(a)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(a)
        sqc2 vf13, 0x10(a)
        sqc2 vf14, 0x20(a)
        sqc2 vf15, 0x30(a)
    }
    return a;
}
static inline void merge_flush_func_003C6520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C6520 */

/* merge_units: begin func_003C65A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cRayMatrix_ctor_void(void* self) {
    return self;
}

void std_vector_cCollisionFace_clear(char* self) {
    *(int*)(self + 4) = 0;
}
static inline void merge_flush_func_003C65A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C65A0 */

/* merge_units: begin func_003C65C0 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline void Q65C0(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Box { V min; V max; };
struct Sphere { float r; int pad[3]; V c; };
extern "C" void cLineSegment_BoundingSphere(Sphere* out, const Box* b)
{
    V Lv; V c; V v; V sub; V sum; V t;
    float r;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&sum), "r"(&b->max), "r"(&b->min) : "memory");
    {
        V* e; __int128 c2; float k; __int128 tt; const V* s; V* p; __int128 cq; V* d; V* q;
        void* xx = &v;
        tt = 0;
        s = &sum;
        d = &v;
        p = &v;
        q = &t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(cq) : "r"(d), "r"(s) : "memory");
        k = 0.5f;
        __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%0); qmtc2.ni %2, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : : "r"(p), "r"(q), "r"(k) : "memory");
        e = &c; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(c2) : "r"(e), "r"(q) : "memory");
    }
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&sub), "r"(&b->max), "r"(&b->min) : "memory");
    {
        V* e3; __int128 c3; float len; void* xx; const V* s; V* lp;
        s = &sub;
        xx = &Lv;
        lp = &Lv;
        len = 0.0f;
        e3 = &Lv; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(c3) : "r"(e3), "r"(s) : "memory");
        __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni %0, vf4" : "=r"(len) : "r"(lp) : "memory");
        r = 0.5f * len;
    }
    out->r = r;
    { void* xx = &out->c; Q65C0(&out->c, &c); }
}
static inline void merge_flush_func_003C65C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C65C0 */
