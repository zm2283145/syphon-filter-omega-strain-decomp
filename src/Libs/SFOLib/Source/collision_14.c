/*
 * Libs/SFOLib/Source/collision: 5 files, 003C3110-003C3170
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C3110 */
#pragma push /* merge_units */
#include "types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Constructor: null pointer wrapper. */
int* cArray_FixedCapacity_cGOBJPtr_2_ctor(int* self) {
    *self = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C3110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C3110 */

/* merge_units: begin func_003C3120 */
#pragma push /* merge_units */
typedef struct Obj3C3 {
    char pad[0xC];
    char flag;
} Obj3C3;

#if 0 /* merge_units */
extern void std_vector_imp_cGOBJPtr_1_ctor(Obj3C3* self, int* src, int flag);
#endif /* merge_units */
Rel * std_vector_imp_cGOBJPtr_1_ctor(); /* merge_units */

extern void std_vector_pod_int_reserve(Obj3C3* self, int value);

/* Constructor: base init, applies *src, then stores the flag byte at +0xC. */
Obj3C3* cArray_cGOBJPtr_ctor(Obj3C3* self, int* src, int flag) {
    std_vector_imp_cGOBJPtr_1_ctor(self, src, flag);
    std_vector_pod_int_reserve(self, *src);
    self->flag = flag;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C3120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C3120 */

/* merge_units: begin func_003C3170 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* std_vector_imp_cGOBJPtr_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_003C3170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C3170 */

/* merge_units: begin func_003C3190 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vector_resize.h"
#pragma pop

#pragma cplusplus on
DEFINE_RESIZE_ELEMENT(Elem96_3190, 96)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_cCollisionEdge_resize, Elem96_3190, std_vector_imp_cCollisionEdge_insert, std_vector_imp_cCollisionEdge_erase)
#pragma opt_common_subs reset
static inline void merge_flush_func_003C3190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C3190 */

/* merge_units: begin func_003C3220 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies, sq zero and VU0 math as GCC-style volatile asm; the unused xx locals keep retail's dead addius */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
    float& X() { return x; }
    float& Y() { return y; }
    float& Z() { return z; }
    void Clear() { __asm__ volatile("sq $0, 0x0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct M { V a, b, c, d; };
extern "C" void cVector_ctor_void(void* p);
static inline void Xform(V* d, const V* s, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(d), "r"(m), "r"(s) : "memory"); }
static inline void Fix(V& v, const M& m) { v.X() *= v.Y(); v.Z() *= v.Y(); Xform(&v, &v, &m); }
struct CQ {
    unsigned char b0; char pad1[0xF];
    V v10; V v20; V v30; V v40; V v50; V v60; V v70; V v80;
    char pad90[0x40];
    int xD0; char padD4[0x45];
    unsigned char b119; unsigned char b11A; char pad11B[5];
    M m120;
};
struct PV { float x, y, z, w; } __attribute__((aligned(16)));
struct ATri {
    PV v[3];
    V n;
    char x40[0x20];
    char x60[0x10];
    ATri(V* src);
};
extern "C" {
unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects(CQ* q, int a, int b);
unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects(CQ* q, int a, int b);
void cCollisionModel_FaceProperties_ctor(void* p);
void cCollisionModel_FaceLocator_ctor(void* p);
void cCollisionFace_Set_cCollisionModelFaceLocatorR(ATri* t, V* src);
}
inline ATri::ATri(V* src) { ATri* p = this; PV* it = p->v; do { cVector_ctor_void(it); it++; } while (it != p->v + 3); cVector_ctor_void(&p->n); cCollisionModel_FaceProperties_ctor(p->x40); cCollisionModel_FaceLocator_ctor(p->x60); cCollisionFace_Set_cCollisionModelFaceLocatorR(p, src); }
extern "C" unsigned char ColQuery_ExecuteSweep(CQ* q, int a, int b)
{
    unsigned char hit;
    if (q->xD0) {
    if (q->b119) hit = cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects(q, a, b);
    else hit = cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects(q, a, b);
    if (hit) {
        q->v20 = q->v10;
        q->v50 = q->v40;
    }
    q->v80 = q->v70;
    if (q->b11A) {
        if (hit) {
            q->v20.Clear();
            Fix(q->v50, q->m120);
        }
        Fix(q->v80, q->m120);
    }
    if (hit) {
        if (q->b0 == 1) q->v30 = q->v20;
        else {
            ATri t(&q->v60);
            const V& r = t.n;
            q->v30 = r;
        }
    }
    } else hit = 0;
    return hit;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C3220(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C3220 */
