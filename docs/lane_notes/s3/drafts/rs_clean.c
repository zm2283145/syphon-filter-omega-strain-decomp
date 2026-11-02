#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
/* cCollisionProbe_SphereSweptRay::Reset(faceList, radius, minPathCosAngle_ForCollision,
   minPathCosAngle_ForNonGlancingCollision, minStartDist_Normal, maxEndDist_Normal, sphereStartPos, spherePath,
   accountForMovementOfCollidingObjects, rotation, scale) (collision.cc): builds the probe transform
   (scale * rotation/translation), its inverse and the face-normal transforms, copies the face list into the shared
   transformed list and moves every face into probe space, then runs Reset_CommonCode with the probe-space start
   (origin) and path.
   Compiled in MW's less-optimised mode (any volatile asm in the body selects it; the GCC volatile quadword copies
   below do): dead `void* xx = this` defs are kept as dead addiu, as in retail. The pass-through inlines (PointW,
   InverseWW/InverseW/Inv2, DirectionW, CopyOf, CopyOfM, MulVX, CopyR) only control the order in which MW creates
   temporaries/registers, which fixes retail's stack slots and register colours. */
struct M;
/* cVector: 16-byte vector; copies are single quadword lq/sq (no C form) */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); }
    /* copy without the dead this def / with two of them (retail's dead addiu pattern in Direction) */
    V(const V& o, short) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); }
    V(const V& o, char) { void* xx = this; void* yy = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    V& operator*=(const M& m);
    /* VU0 normalise of xyz in place */
    V& Normalize() {
        __asm__ volatile("lqc2 vf1, 0x0(%0); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%0)" : : "r"(this) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void CopyV(V* d, const V& s) { *d = s; }
static inline void CopyV2(V* d, const V& s) { CopyV(d, s); }
static inline void CopyR(V& d, const V& s) { d = s; }
/* cMatrix: 4x4, copies are four quadword lq/sq */
struct M {
    float m[4][4];
    M() {}
    M(const M* p);
    M(float a00, float a01, float a02, float a03, float a10, float a11, float a12, float a13,
      float a20, float a21, float a22, float a23, float a30, float a31, float a32, float a33) {
        m[0][0] = a00; m[0][1] = a01; m[0][2] = a02; m[0][3] = a03;
        m[1][0] = a10; m[1][1] = a11; m[1][2] = a12; m[1][3] = a13;
        m[2][0] = a20; m[2][1] = a21; m[2][2] = a22; m[2][3] = a23;
        m[3][0] = a30; m[3][1] = a31; m[3][2] = a32; m[3][3] = a33;
    }
    /* rotation part of r, translation row t */
    M(const M& r, const V& t) {
        m[0][0] = r.m[0][0]; m[0][1] = r.m[0][1]; m[0][2] = r.m[0][2];
        m[1][0] = r.m[1][0]; m[1][1] = r.m[1][1]; m[1][2] = r.m[1][2];
        m[2][0] = r.m[2][0]; m[2][1] = r.m[2][1]; m[2][2] = r.m[2][2];
        m[0][3] = r.m[0][3]; m[1][3] = r.m[1][3]; m[2][3] = r.m[2][3];
        CopyV2((V*)m[3], t);
    }
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& operator=(const M& o) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    /* VU0 4x4 multiply in place: this = this * o */
    M& operator*=(const M& o) {
        M* p = this;
        __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%0); lqc2 vf9, 0x10(%0); lqc2 vf10, 0x20(%0); lqc2 vf11, 0x30(%0); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(p), "r"(&o) : "memory");
        return *p;
    }
} __attribute__((aligned(16)));
/* VU0 point transform in place: p = p * m */
static inline void MulVA(V* p, const M* q) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(p), "r"(q) : "memory"); }
inline V& V::operator*=(const M& m) {
    V* p = this;
    MulVA(p, &m);
    return *p;
}
struct Face { V vertices[3]; V unitNormal; char pad40[0x30]; };   /* cCollisionFace, 0x70 */
struct FaceVec { unsigned int cap; unsigned int count; Face* data; };
struct Arr { FaceVec mArray; unsigned char mCanExpand; };          /* cArray<cCollisionFace> */
/* std iterator tags: a pointer's category (random access) is sliced to do_assign's forward_iterator_tag */
struct input_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};
struct Probe {                      /* cCollisionProbe_SphereSweptRay */
    char pad0[0x80];
    V spherePath_WorldSpace;        /* 0x80 */
    char pad90[0xF0 - 0x90];
    V sphereStartPos_WorldSpace;    /* 0xF0 */
    char pad100[0x11A - 0x100];
    unsigned char mWasTransformSet; /* 0x11A */
    M mTransform;                   /* 0x120 */
    M mTransform_ForFaceNormals;    /* 0x160 */
    M mInvTransform;                /* 0x1A0 */
};
extern "C" {
extern Arr* D_00542CD0; /* sharedTransformedFaceList */
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
M* cMatrix_InvertRotTrans(M* m);
void std_vector_imp_cCollisionFace_do_assign(FaceVec* v, Face* first, Face* last, forward_iterator_tag tag);
Face** std_vector_deleter_cCollisionFace_data_void_2(FaceVec* v);
void cCollisionProbe_SphereSweptRay_Reset_CommonCode(Probe* self, Arr* faceList, float r, float c1, float c2, float d1, float d2, const V& start, const V& path, unsigned char acc);
}
inline M::M(const M* p) { cMatrix_ctor_cMatrixR(this, p); void* xx = this; }
static inline float Recip(float x) { return 1.0f / x; }
static inline M Inv2(const M& m) { M t; return M(cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&t, &m))); }
static inline M Inverse(const M& m) { return Inv2(m); }
static inline M InverseW(const M& m) { return Inverse(m); }
static inline M InverseWW(const M& m) { return InverseW(m); }
static inline M operator*(const M& a, const M& b) { M r(a); return r *= b; }
static inline M CopyOfM(const M& m) { return m; }
static inline M MulCopy(const M& a, const M& b) { M r(CopyOfM(a)); return r *= b; }
static inline V CopyOf(const V& v) { return v; }
static inline V operator*(const V& v, const M& m) { V r(v); r *= m; return r; }
static inline V MulVX(const V& v, const M& m) { V r(v); r *= m; return CopyOf(r); }
/* v with w = 1 (point) / w = 0 (direction) */
static inline V Point(const V& v) { V r(CopyOf(v)); V* p = &r; p->w = 1.0f; return *p; }
static inline V PointW(const V& v) { return Point(v); }
static inline V Direction(const V& v) { V r(v, (short)0); V* p = &r; p->w = 0.0f; return V(*p, 'x'); }
static inline V DirectionW(const V& v) { return Direction(v); }
/* (0, 0, 0, 1) from VU0 vf0 */
static inline V Origin() { V r; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&r) : "memory"); return r; }
/* vector<cCollisionFace>::operator= / cArray::operator= */
static inline void Assign(FaceVec* v, Face* first, Face* last) { std_vector_imp_cCollisionFace_do_assign(v, first, last, random_access_iterator_tag()); }
static inline void VecCopy(FaceVec* d, const FaceVec* s) { if (d != s) Assign(d, s->data, s->data + s->count); }
static inline void ArrCopy(Arr* d, const Arr& s) { VecCopy(&d->mArray, &s.mArray); d->mCanExpand = s.mCanExpand; }
/* vector iterator (wrap_iterator kept in memory, as in retail) */
struct WrapIt { Face* p; WrapIt(Face* q) : p(q) {} };
static inline bool operator==(const WrapIt& a, const WrapIt& b) { Face* q = b.p; return a.p == q; }
struct Iterator {
    WrapIt mIterator;
    Iterator(const WrapIt& w) : mIterator(w) {}
    bool operator!=(const Iterator& o) const { return !(mIterator == o.mIterator); }
    Face& operator*() const { return *mIterator.p; }
    Iterator& operator++() { ++mIterator.p; return *this; }
};
static inline WrapIt Begin(FaceVec* v) { return WrapIt(*std_vector_deleter_cCollisionFace_data_void_2(v)); }
static inline WrapIt End(FaceVec* v) { return WrapIt(*std_vector_deleter_cCollisionFace_data_void_2(v) + v->count); }

extern "C" void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2(Probe* self, Arr* faceList,
    float iSphereRadius, float iMinPathCosAngle_ForCollision, float iMinPathCosAngle_ForNonGlancingCollision,
    float iMinStartDist_Normal, float iMaxEndDist_Normal, const V& iSphereStartPos, const V& iSpherePath,
    unsigned char accountForMovementOfCollidingObjects, const M& rotation, const V& scale)
{
    Arr* transformedFaceList = D_00542CD0;
    M invTransform_ForFaceNormals;
    M scaleMat(scale.x, 0.0f, 0.0f, 0.0f, 0.0f, scale.y, 0.0f, 0.0f, 0.0f, 0.0f, scale.z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    M invScaleMat(Recip(scale.x), 0.0f, 0.0f, 0.0f, 0.0f, Recip(scale.y), 0.0f, 0.0f, 0.0f, 0.0f, Recip(scale.z), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    M rotTrans(rotation, PointW(iSphereStartPos));
    M invRotTrans = InverseWW(rotTrans);
    self->mTransform = scaleMat * rotTrans;
    self->mInvTransform = invRotTrans * invScaleMat;
    self->mTransform_ForFaceNormals = invScaleMat * rotTrans;
    invTransform_ForFaceNormals = MulCopy(invRotTrans, scaleMat);
    ArrCopy(transformedFaceList, *faceList);
    Iterator curr(Begin(&transformedFaceList->mArray));
    Iterator end(End(&transformedFaceList->mArray));
    for (; curr != end; ++curr) {
        Face& face = *curr;
        CopyR(face.vertices[0], MulVX(face.vertices[0], self->mInvTransform));
        CopyR(face.vertices[1], MulVX(face.vertices[1], self->mInvTransform));
        CopyR(face.vertices[2], MulVX(face.vertices[2], self->mInvTransform));
        face.unitNormal = (face.unitNormal * invTransform_ForFaceNormals).Normalize();
    }
    /* Dead block: emits nothing, but in the less-optimised mode its two matrices and five vector temporaries keep
       their stack slots - retail's frame has exactly these holes (named-local area above start/path, temp area
       between the loop temps and the Origin temp), probably from disabled debug code. */
    if (0) {
        M d0;
        M d1;
        d0 = d1;
        V(iSpherePath).Normalize(); V(iSpherePath).Normalize(); V(iSpherePath).Normalize(); V(iSpherePath).Normalize(); V(iSpherePath).Normalize();
    }
    {
        V start;
        start = Origin();
        V path(DirectionW(iSpherePath) *= self->mInvTransform);
        cCollisionProbe_SphereSweptRay_Reset_CommonCode(self, transformedFaceList, iSphereRadius, iMinPathCosAngle_ForCollision,
            iMinPathCosAngle_ForNonGlancingCollision, iMinStartDist_Normal, iMaxEndDist_Normal, start, path,
            accountForMovementOfCollidingObjects);
    }
    self->sphereStartPos_WorldSpace = iSphereStartPos;
    self->spherePath_WorldSpace = iSpherePath;
    self->mWasTransformSet = 1;
}
