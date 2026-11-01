/* 003BDA00 cCollisionProbe_SphereSweptRay::DetectForCollision_AccountForMovementOfCollidingObjects(unsigned char, unsigned char)
 * (collision.cc), rebuilt from the prototype DWARF/.line data. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

struct M;
struct V {
    float x, y, z, w;
    V() {}
    /* 128-bit lq/sq quadword copy: MW splits a C struct copy into words */
    V(const V& o, unsigned char) { const V* src = &o; void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(src) : "memory"); }
    V(const V& o, unsigned short) { void* xx = this; const V* src = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(src) : "memory"); }
    V(const V& o, unsigned long) { const V* src = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(src) : "memory"); }
    V(const V& o, signed char) { V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(&o) : "memory"); }
    V(const V& o, int) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V(const V& o, short) { V* d = this; const V* src = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(src) : "memory"); }
    V(const V& o, char) { const V* src = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(src) : "memory"); }
    V(const V& o, long) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V(const V& o, float) { __int128 t; void* xx = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; };

/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void AddM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void SubM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void XformM(V* v, const M* m) { asm volatile { lqc2 vf8, 0x0(v); lqc2 vf4, 0x0(m); lqc2 vf5, 0x10(m); lqc2 vf6, 0x20(m); lqc2 vf7, 0x30(m); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(v) } }

static inline V operator+(const V& a, const V& b) { V r; V* pd = &r; const V* pa = &a; const V* pb = &b; AddM(pd, pa, pb); return r; }
static inline V operator-(const V& a, const V& b) { V r; SubM(&r, &a, &b); return r; }
static inline void XfI(V* p, const M* m) { XformM(p, m); }
static inline V Xf(const M& m, const V& v) { V r(v, 0L); V* p = &r; XfI(p, &m); return *p; }
static inline V XA0(const M& m, const V& v) { V r(v, 0L); V* p = &r; XfI(p, &m); return *p; }
static inline V XB0(const M& m, V v) { return XA0(m, v); }
static inline V XC0(const M& m, const V& v) { return XA0(m, v); }
static inline V XA1(const M& m, const V& v) { V r(v, 0L); V* p = &r; XformM(p, &m); return *p; }
static inline V XB1(const M& m, V v) { return XA1(m, v); }
static inline V XC1(const M& m, const V& v) { return XA1(m, v); }
static inline V XA2(const M& m, const V& v) { V r(v, 0L); V* p = &r; const M* pm = &m; XfI(p, pm); return *p; }
static inline V XB2(const M& m, V v) { return XA2(m, v); }
static inline V XC2(const M& m, const V& v) { return XA2(m, v); }
static inline V XA3(const M& m, const V& v) { const M* pm = &m; V r(v, 0L); V* p = &r; XfI(p, pm); return *p; }
static inline V XB3(const M& m, V v) { return XA3(m, v); }
static inline V XC3(const M& m, const V& v) { return XA3(m, v); }
static inline V XA4(const M& m, const V& v) { V r(v, 0L); XfI(&r, &m); return r; }
static inline V XB4(const M& m, V v) { return XA4(m, v); }
static inline V XC4(const M& m, const V& v) { return XA4(m, v); }
static inline V XA5(const M& m, const V& v) { V r(v, 0L); V* p = &r; XfI(p, &m); return V(*p, 0L); }
static inline V XB5(const M& m, V v) { return XA5(m, v); }
static inline V XC5(const M& m, const V& v) { return XA5(m, v); }
static inline V XA6(const M& m, const V& v) { V r(v); V* p = &r; XfI(p, &m); return *p; }
static inline V XB6(const M& m, V v) { return XA6(m, v); }
static inline V XC6(const M& m, const V& v) { return XA6(m, v); }
static inline V XA7(const M& m, const V& v) { V r(v, (signed char)0); V* p = &r; XfI(p, &m); return *p; }
static inline V XB7(const M& m, V v) { return XA7(m, v); }
static inline V XC7(const M& m, const V& v) { return XA7(m, v); }
static inline V XA8(const M& m, const V& v) { V r(v, (unsigned short)0); V* p = &r; XfI(p, &m); return *p; }
static inline V XB8(const M& m, V v) { return XA8(m, v); }
static inline V XC8(const M& m, const V& v) { return XA8(m, v); }
static inline V XA9(const M& m, const V& v) { V r(v, (unsigned char)0); V* p = &r; XfI(p, &m); return *p; }
static inline V XB9(const M& m, V v) { return XA9(m, v); }
static inline V XC9(const M& m, const V& v) { return XA9(m, v); }
static inline V XA10(const M& m, const V& v) { V r(v, (short)0); V* p = &r; XfI(p, &m); return *p; }
static inline V XB10(const M& m, V v) { return XA10(m, v); }
static inline V XC10(const M& m, const V& v) { return XA10(m, v); }
static inline V XA11(const M& m, const V& v) { V r(v, (char)0); V* p = &r; XfI(p, &m); return *p; }
static inline V XB11(const M& m, V v) { return XA11(m, v); }
static inline V XC11(const M& m, const V& v) { return XA11(m, v); }
static inline V XA12(const M& m, const V& v) { V r(v, 0.0f); V* p = &r; XfI(p, &m); return *p; }
static inline V XB12(const M& m, V v) { return XA12(m, v); }
static inline V XC12(const M& m, const V& v) { return XA12(m, v); }
static inline V XA13(const M& m, const V& v) { V r(v, 0); V* p = &r; XfI(p, &m); return *p; }
static inline V XB13(const M& m, V v) { return XA13(m, v); }
static inline V XC13(const M& m, const V& v) { return XA13(m, v); }
static inline V XA14(const M& m, const V& v) { V r(v, 0L); V* p = &r; XfI(p, &m); return V(*p, (signed char)0); }
static inline V XB14(const M& m, V v) { return XA14(m, v); }
static inline V XC14(const M& m, const V& v) { return XA14(m, v); }
static inline V XA15(const M& m, const V& v) { V r(v, 0L); V* p = &r; XfI(p, &m); return V(*p, (unsigned short)0); }
static inline V XB15(const M& m, V v) { return XA15(m, v); }
static inline V XC15(const M& m, const V& v) { return XA15(m, v); }

static inline V operator*(const M& m, const V& v) { return Xf(m, v); }
static inline V AddW(const V& a, const V& b) { return a + b; }

struct cBox { V mn, mx; };
struct cCollisionFace;
struct Probe;
extern "C" {
V* cVector_opAssign(V* d, const V* s);
unsigned char cVector_IsZero(const V* v);
V cVector_GetNormalized_void(const V* v);
const V* cVector_GetZero(void);
V* cVector_ctor_cVectorR(V* d, const V* s);
float cVector_Dot(const V* a, const V* b);
void cBox_Empty(cBox* b);
void cBox_Include(cBox* b, const V* v);
V cVector_opAdd(const V* a, const V* b);
void cBox_Grow(cBox* b, float f);
struct FaceVec { cCollisionFace* data; };
struct FaceList { int pad0; int count; };
FaceVec* std_vector_deleter_cCollisionFace_data_void(FaceList* l);
void cCollisionProbe_SphereSweptRay_DetectForCollision_cCollisionFaceR(Probe* p, const cCollisionFace* f);
}

struct cMovement { unsigned char active; char pad01[0x50 - 1]; M deltaTransform; };
struct cGOBJ { char pad0[0x54]; cMovement* mMovement; };
struct cCollisionModel_FaceLocator { cGOBJ* gobj; };
struct cCollisionFace {
    V vertices[3];
    V unitNormal;
    unsigned char properties;
    char pad41[0x64 - 0x41];
    cCollisionModel_FaceLocator* faceLocator;
    char pad68[0x70 - 0x68];
};
struct WrapIt { cCollisionFace* p; WrapIt(cCollisionFace* q) { p = q; } };
struct ConstIterator {
    cCollisionFace* p;
    ConstIterator(const WrapIt& w) { p = w.p; }
    const cCollisionFace& operator*() const { return *p; }
    void operator++() { p++; }
    bool operator==(const ConstIterator& o) const { cCollisionFace* b = o.p; return p == b; }
    bool operator!=(const ConstIterator& o) const { return !(*this == o); }
};

struct Probe {
    unsigned char collisionFeature;
    char pad01[0x70 - 1];
    V spherePath;
    V spherePath_WorldSpace;
    V spherePathDir;
    float spherePathSquared;
    char padA4[0xB0 - 0xA4];
    cBox bbox;
    FaceList* mFaceList;
    float sphereRadius;
    float sphereRadiusSquared;
    char padDC[4];
    V sphereStartPos;
    V sphereStartPos_ModelSpace;
    char pad100[0x11A - 0x100];
    unsigned char modelSpace;
    char pad11B[0x1A0 - 0x11B];
    M modelToWorld;

    ConstIterator Begin() { return ConstIterator(WrapIt(std_vector_deleter_cCollisionFace_data_void(mFaceList)->data)); }
    ConstIterator End() { FaceList* l = mFaceList; return ConstIterator(WrapIt(std_vector_deleter_cCollisionFace_data_void(l)->data + l->count)); }
    void CalcBBox()
    {
        cBox_Empty(&bbox);
        cBox_Include(&bbox, &sphereStartPos);
        cBox_Include(&bbox, &cVector_opAdd(&sphereStartPos, &spherePath));
        cBox_Grow(&bbox, sphereRadius);
    }
    void SetDir(const V& path)
    {
        cVector_opAssign(&spherePathDir, !cVector_IsZero(&spherePath) ? &cVector_GetNormalized_void(&path) : cVector_ctor_cVectorR(&V(), cVector_GetZero()));
    }
    void SSP2(const V& path)
    {
        cVector_opAssign(&spherePath, &path);
        SetDir(path);
        spherePathSquared = cVector_Dot(&path, &path);
        CalcBBox();
    }
    void SSP1(const V& path) { SSP2(path); }
    void SetSpherePath(V path) { SSP1(path); }
};

extern "C" unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects(Probe* self, unsigned char requiredProperties, unsigned char rejectedProperties)
{
    V unmodifiedStartPos = self->sphereStartPos;
    V unmodifiedSpherePath = self->spherePath;
    float unmodifiedSpherePathSquared = self->spherePathSquared;
    cMovement* prevMovementInfo = 0;
    ConstIterator currFace = self->Begin();
    const ConstIterator& end = self->End();
    for (; currFace != end; ++currFace) {
        const cCollisionFace& face = *currFace;
        unsigned char properties = face.properties;
        if ((unsigned char)(properties & rejectedProperties) == 0 && (unsigned char)(properties & requiredProperties) == requiredProperties) {
            cGOBJ* currGobj = face.faceLocator->gobj;
            cMovement* currMovementInfo = currGobj->mMovement;
            if (currMovementInfo != prevMovementInfo) {
                if (prevMovementInfo || !currMovementInfo || currMovementInfo->active) {
                    V endPos = AddW(self->sphereStartPos, self->spherePath);
                    if (currMovementInfo) {
                        const M& deltaTransform = currMovementInfo->deltaTransform;
                        if (!self->modelSpace)
                            self->sphereStartPos = XC3(deltaTransform, unmodifiedStartPos);
                        else
                            self->sphereStartPos = XB4(self->modelToWorld, XC3(deltaTransform, self->sphereStartPos_ModelSpace));
                    } else {
                        self->sphereStartPos = unmodifiedStartPos;
                    }
                    self->SetSpherePath(endPos - self->sphereStartPos);
                    prevMovementInfo = currMovementInfo;
                }
            }
            cCollisionProbe_SphereSweptRay_DetectForCollision_cCollisionFaceR(self, &face);
        }
    }
    if (prevMovementInfo) {
        V endPos = AddW(self->sphereStartPos, self->spherePath);
        self->sphereStartPos = unmodifiedStartPos;
        self->SetSpherePath(endPos - self->sphereStartPos);
    }
    if (self->collisionFeature) return 1;
    return 0;
}
