/*
 * Libs/SFOLib/Source/collision: 10 files, 003C3110-003C36C0
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
#if 0 /* merge_units */
unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects(CQ* q, int a, int b);
#endif /* merge_units */
unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects(void*, int, int); /* merge_units */
#define cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects(a0, a1, a2) (cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects(CQ* q, int a, int b);
#endif /* merge_units */
unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects(void*, int, int); /* merge_units */
#define cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects(a0, a1, a2) (cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects((void *)(a0), (a1), (a2))) /* merge_units */

void cCollisionModel_FaceProperties_ctor(void* p);
void cCollisionModel_FaceLocator_ctor(void* p);
#if 0 /* merge_units */
void cCollisionFace_Set_cCollisionModelFaceLocatorR(ATri* t, V* src);
#endif /* merge_units */
void cCollisionFace_Set_cCollisionModelFaceLocatorR(void*, void*); /* merge_units */
#define cCollisionFace_Set_cCollisionModelFaceLocatorR(a0, a1) (cCollisionFace_Set_cCollisionModelFaceLocatorR((void *)(a0), (void *)(a1))) /* merge_units */

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
#undef cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects /* merge_units */
#undef cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects /* merge_units */
#undef cCollisionFace_Set_cCollisionModelFaceLocatorR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C3220 */

/* merge_units: begin func_003C3450 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies, sq zero and VU0 math as GCC-style volatile asm; the unused xx locals keep retail's dead addius */
struct V_003C3450 {
    float x, y, z, w;
    V_003C3450() {}
    V_003C3450(const V_003C3450& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V_003C3450& operator=(const V_003C3450& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
    float& X() { return x; }
    float& Y() { return y; }
    float& Z() { return z; }
    void Normalize() { void* xx = this; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory"); }
    void Clear() { __asm__ volatile("sq $0, 0x0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct M_003C3450 { V_003C3450 a, b, c, d; };
static inline void Xform_003C3450(V_003C3450* d, const V_003C3450* s, const M_003C3450* m) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(d), "r"(m), "r"(s) : "memory"); }
static inline void Fix_003C3450(V_003C3450& v, const M_003C3450& m) { Xform_003C3450(&v, &v, &m); }
struct CQ_003C3450 {
    unsigned char b0; char pad1[0xF];
    V_003C3450 v10; V_003C3450 v20; V_003C3450 v30; V_003C3450 v40; V_003C3450 v50; V_003C3450 v60; V_003C3450 v70; V_003C3450 v80;
    char pad90[0x40];
    int xD0; char padD4[0x45];
    unsigned char b119; unsigned char b11A; char pad11B[5];
    M_003C3450 m120;
    M_003C3450 m160;
};
struct ATri_003C3450 {
    PV v[3];
    V_003C3450 n;
    char x40[0x20];
    char x60[0x10];
    ATri_003C3450(V_003C3450* src);
};
extern "C" {
#if 0 /* merge_units */
unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects(CQ_003C3450* q, int a, int b);
#endif /* merge_units */
#define cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects(a0, a1, a2) (cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects(CQ_003C3450* q, int a, int b);
#endif /* merge_units */
#define cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects(a0, a1, a2) (cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cCollisionFace_Set_cCollisionModelFaceLocatorR(ATri_003C3450* t, V_003C3450* src);
#endif /* merge_units */
#define cCollisionFace_Set_cCollisionModelFaceLocatorR(a0, a1) (cCollisionFace_Set_cCollisionModelFaceLocatorR((void *)(a0), (void *)(a1))) /* merge_units */

}
inline ATri_003C3450::ATri_003C3450(V_003C3450* src) { ATri_003C3450* p = this; PV* it = p->v; do { cVector_ctor_void(it); it++; } while (it != p->v + 3); cVector_ctor_void(&p->n); cCollisionModel_FaceProperties_ctor(p->x40); cCollisionModel_FaceLocator_ctor(p->x60); cCollisionFace_Set_cCollisionModelFaceLocatorR(p, src); }
extern "C" unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_uchar_uchar(CQ_003C3450* q, int a, int b)
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
            if (q->b0 == 1) Fix_003C3450(q->v20, q->m160);
            else Fix_003C3450(q->v20, q->m120);
            q->v20.Normalize();
            Fix_003C3450(q->v50, q->m120);
        }
        Fix_003C3450(q->v80, q->m120);
    }
    if (hit) {
        if (q->b0 == 1) q->v30 = q->v20;
        else {
            ATri_003C3450 t(&q->v60);
            const V_003C3450& r = t.n;
            q->v30 = r;
        }
    }
    } else hit = 0;
    return hit;
}
#undef cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects /* merge_units */
#undef cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects /* merge_units */
#undef cCollisionFace_Set_cCollisionModelFaceLocatorR /* merge_units */
static inline void merge_flush_func_003C3450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C3450 */

/* merge_units: begin func_003C36C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C5Tri { char pad[0x40]; unsigned char flags; char pad2[0x2F]; };
struct C5TriVec { int cap; int count; };
struct C5Trace { unsigned char hit; char pad[0x5F]; unsigned char want; unsigned char reject; };
struct C5TriIt { C5Tri* p; C5TriIt() {} C5TriIt(C5Tri* q) : p(q) {} };
inline bool operator==(const C5TriIt& a, const C5TriIt& b) { return a.p == b.p; }
inline bool operator!=(const C5TriIt& a, const C5TriIt& b) { return !(a == b); }
#if 0 /* merge_units */
extern "C" C5Tri** std_vector_deleter_cCollisionFace_data_void(C5TriVec* v);
#endif /* merge_units */
extern "C" void* std_vector_deleter_cCollisionFace_data_void(void*); /* merge_units */
#define std_vector_deleter_cCollisionFace_data_void(a0) ((C5Tri * *)std_vector_deleter_cCollisionFace_data_void((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern "C" void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(C5Trace* t, C5Tri* tri);
#endif /* merge_units */
extern "C" void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(void*, void*); /* merge_units */
#define cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(a0, a1) (cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR((void *)(a0), (void *)(a1))) /* merge_units */

extern "C" bool cCollisionProbe_Ray_DetectForCollision_cArrayR(C5Trace* t, C5TriVec* v) {
    C5TriIt it(*std_vector_deleter_cCollisionFace_data_void(v));
    const C5TriIt& end = C5TriIt(*std_vector_deleter_cCollisionFace_data_void(v) + v->count);
    for (; it != end; it.p++) {
        if ((unsigned char)(it.p->flags & t->reject) == 0 && t->want == (unsigned char)(it.p->flags & t->want))
            cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(t, it.p);
    }
    return t->hit != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C36C0(void) {}
#undef std_vector_deleter_cCollisionFace_data_void /* merge_units */
#undef cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C36C0 */

/* merge_units: begin func_003C37A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off
struct C6Rec_3C37A0 { char pad[0x40]; unsigned char flags; char pad41[0x2F]; };
struct C6Coll_3C37A0 { int pad0; int count; };
struct C6Query_3C37A0 { unsigned char hit; char pad[0x5F]; unsigned char require; unsigned char reject; };
#if 0 /* merge_units */
extern "C" C6Rec_3C37A0** std_vector_deleter_cCollisionFace_data_void(C6Coll_3C37A0*);
#endif /* merge_units */
#define std_vector_deleter_cCollisionFace_data_void(a0) ((C6Rec_3C37A0 * *)std_vector_deleter_cCollisionFace_data_void((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern "C" void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(C6Query_3C37A0*, C6Rec_3C37A0*);
#endif /* merge_units */
extern "C" void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(void*, void*); /* merge_units */
#define cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(a0, a1) (cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3((void *)(a0), (void *)(a1))) /* merge_units */

static inline int C6Eq(C6Rec_3C37A0* a, C6Rec_3C37A0* b) { return a == b; }
extern "C" int cCollisionProbe_Ray_DetectForCollision_cArrayR_2(C6Query_3C37A0* q, C6Coll_3C37A0* coll) {
    C6Rec_3C37A0** pend;
    C6Rec_3C37A0* end;
    C6Rec_3C37A0* it;
    it = *std_vector_deleter_cCollisionFace_data_void(coll);
    end = *std_vector_deleter_cCollisionFace_data_void(coll) + coll->count;
    pend = &end;
    for (; C6Eq(it, *pend) ^ 1; it++) {
        unsigned char f = it->flags;
        if ((unsigned char)(f & q->reject) == 0 && q->require == (unsigned char)(f & q->require))
            cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(q, it);
    }
    return q->hit != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C37A0(void) {}
#undef std_vector_deleter_cCollisionFace_data_void /* merge_units */
#undef cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C37A0 */

/* merge_units: begin func_003C3880 */
#pragma push /* merge_units */
typedef struct { char pad0[0x40]; unsigned char mask; char pad41[0x2F]; } Pt2_LRec;
typedef struct { int pad0; int count; } Pt2_LVec;
typedef struct { unsigned char hit; char pad1[0x5F]; unsigned char want; unsigned char excl; unsigned char alt; } Pt2_LQ;
#if 0 /* merge_units */
extern Pt2_LRec** std_vector_deleter_cCollisionFace_data_void(Pt2_LVec*);
#endif /* merge_units */
#define std_vector_deleter_cCollisionFace_data_void(a0) ((Pt2_LRec * *)std_vector_deleter_cCollisionFace_data_void((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(Pt2_LQ*, Pt2_LRec*);
#endif /* merge_units */
#define cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(a0, a1) (cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR((void *)(a0), (void *)(a1))) /* merge_units */


extern void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_2(Pt2_LQ*, Pt2_LRec*);
static inline int Pt2_Ne(Pt2_LRec* a, Pt2_LRec** b) { return !(a == *b); }

int cCollisionProbe_Ray_DetectForCollision_cArrayR_3(Pt2_LQ* q, Pt2_LVec* v) {
    unsigned char deferred = 0;
    {
        Pt2_LRec* end[1];
        Pt2_LRec** ep;
        Pt2_LRec* it = *std_vector_deleter_cCollisionFace_data_void(v);
        end[0] = *std_vector_deleter_cCollisionFace_data_void(v) + v->count;
        ep = end;
        for (; Pt2_Ne(it, ep); it++) {
            unsigned char m = it->mask;
            if (!(unsigned char)(m & q->excl)) {
                if (q->want == (unsigned char)(m & q->want)) {
                    if (!(unsigned char)(m & q->alt)) cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(q, it);
                    else deferred = 1;
                }
            }
        }
    }
    if (deferred) {
        Pt2_LRec* end[1];
        Pt2_LRec** ep;
        Pt2_LRec* it = *std_vector_deleter_cCollisionFace_data_void(v);
        end[0] = *std_vector_deleter_cCollisionFace_data_void(v) + v->count;
        ep = end;
        for (; Pt2_Ne(it, ep); it++) {
            unsigned char m = it->mask;
            if ((unsigned char)(m & q->alt)) {
                if (!(unsigned char)(m & q->excl)) {
                    if (q->want == (unsigned char)(m & q->want)) cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_2(q, it);
                }
            }
        }
    }
    return q->hit != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C3880(void) {}
#undef std_vector_deleter_cCollisionFace_data_void /* merge_units */
#undef cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C3880 */

/* merge_units: begin func_003C3A60 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern Pt2_LRec** std_vector_deleter_cCollisionFace_data_void(Pt2_LVec*);
#endif /* merge_units */
#define std_vector_deleter_cCollisionFace_data_void(a0) ((Pt2_LRec * *)std_vector_deleter_cCollisionFace_data_void((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(Pt2_LQ*, Pt2_LRec*);
#endif /* merge_units */
#define cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(a0, a1) (cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3((void *)(a0), (void *)(a1))) /* merge_units */


extern void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_4(Pt2_LQ*, Pt2_LRec*);

int cCollisionProbe_Ray_DetectForCollision_cArrayR_4(Pt2_LQ* q, Pt2_LVec* v) {
    unsigned char deferred = 0;
    {
        Pt2_LRec* end[1];
        Pt2_LRec** ep;
        Pt2_LRec* it = *std_vector_deleter_cCollisionFace_data_void(v);
        end[0] = *std_vector_deleter_cCollisionFace_data_void(v) + v->count;
        ep = end;
        for (; Pt2_Ne(it, ep); it++) {
            unsigned char m = it->mask;
            if (!(unsigned char)(m & q->excl)) {
                if (q->want == (unsigned char)(m & q->want)) {
                    if (!(unsigned char)(m & q->alt)) cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(q, it);
                    else deferred = 1;
                }
            }
        }
    }
    if (deferred) {
        Pt2_LRec* end[1];
        Pt2_LRec** ep;
        Pt2_LRec* it = *std_vector_deleter_cCollisionFace_data_void(v);
        end[0] = *std_vector_deleter_cCollisionFace_data_void(v) + v->count;
        ep = end;
        for (; Pt2_Ne(it, ep); it++) {
            unsigned char m = it->mask;
            if ((unsigned char)(m & q->alt)) {
                if (!(unsigned char)(m & q->excl)) {
                    if (q->want == (unsigned char)(m & q->want)) cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_4(q, it);
                }
            }
        }
    }
    return q->hit != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C3A60(void) {}
#undef std_vector_deleter_cCollisionFace_data_void /* merge_units */
#undef cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C3A60 */
