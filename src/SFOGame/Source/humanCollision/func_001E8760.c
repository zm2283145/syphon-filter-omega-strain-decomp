#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { const cVector* s = &o; cVector* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    float LengthSquared() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
    void Normalize() {
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory");
    }
    cVector GetNormalized() const { cVector r(*this); cVector* p = &r; p->Normalize(); return *p; }
    float& Z() { return z; } float GX() const { return x; } float PX() const { const cVector* p = this; return p->x; }
    float& Y() { cVector* p = this; return p->y; }
    cVector& ZSet0() { z = 0.0f; return *this; } cVector GetXY() const { return cVector(*this).ZSet0(); }
} __attribute__((aligned(16)));

static inline void SubV(cVector* r, const cVector* a, const cVector* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline cVector operator-(const cVector& a, const cVector& b) { cVector r; SubV(&r, &a, &b); return r; }

struct cMatrix { float m[16]; } __attribute__((aligned(16)));
struct cBox {
    cVector min, max;
    cBox(const cBox& o) : min(o.min), max(o.max) {}
};

extern "C" {
cVector* cVector_ctor_cVectorR(cVector* d, const cVector* s);
void cVector_WSet1(cVector* v);
void cBox_Empty(cBox* b);
cVector cVector_GetTransformed(const cVector* v, const cMatrix* m);
cVector* cVector_Transform_cMatrixR(cVector* v, const cMatrix* m);
cVector* cVector_ctor_float_float_float_float(cVector* o, float x, float y, float z, float w);
void cBox_Include(cBox* b, const cVector* v);
}

static inline void TB0(cBox* b, const cMatrix* m)
{
    cVector mn; cVector_ctor_cVectorR(&mn, &b->min); cVector_WSet1(&mn);
    cVector mx; cVector_ctor_cVectorR(&mx, &b->max); cVector_WSet1(&mx);
    cBox_Empty(b);
    { cVector t = cVector_GetTransformed(&mn, m); cBox_Include(b, &t); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mn.x, mn.y, mx.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mn.x, mx.y, mn.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mn.x, mx.y, mx.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mx.x, mn.y, mn.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mx.x, mn.y, mx.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mx.x, mx.y, mn.z, 1.0f), m)); }
    { cVector t = cVector_GetTransformed(&mx, m); cBox_Include(b, &t); }
}

static inline void TB(cBox* b, const cMatrix* m) { TB0(b, m); }
struct cXform {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad4[0xC];
    cMatrix mMatrix;
    unsigned char mDirty;
    const cMatrix& GetMatrix() { if (mDirty) Update(); return mMatrix; }
};
struct cController {
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual unsigned char IsActive();
};
struct cTreeNode; extern "C" unsigned char cTreeNode_cSkaSystemPtr_IsAttached(const cTreeNode* a, const cTreeNode* b);
struct cTreeNode { char pad[4]; unsigned char IsAttached(const cTreeNode& o) const { return cTreeNode_cSkaSystemPtr_IsAttached(this, &o); } };
struct cSkaSystem { char pad[0x100]; cTreeNode node; };
extern "C" unsigned char cTreeNode_cSkaSystemPtr_IsAttached(const cTreeNode* a, const cTreeNode* b);

class cSKM_GOBJ {
public:
    VPAD32(a)
    virtual cBox& GetBox();
    VPAD16(b) VPAD4(c) VPAD1(d)
    virtual cVector GetPosition() const;
    VPAD8(e) VPAD1(f)
    virtual unsigned char GetState();
    int pad4[10];
    unsigned char b2C, b2D, b2E;
    char pad2F[0x50 - 0x2F];
    cXform* mXform;
    int pad54;
    cController* mController;
    char pad5C[0x2EC0 - 0x5C];
    cSkaSystem mSkaSystem;
    cSkaSystem* GetSkaSystem() const { return (cSkaSystem*)&mSkaSystem; }
};

struct cHumanCollisionRoutine {
    void* vt;
    cSKM_GOBJ* mGobj;
    void* skeleton;
    cSkaSystem* animationSystem;
    char pad10[0x3D0 - 0x10];
    unsigned char mDoCollisionWithHumans;
};

static inline unsigned char Att(cHumanCollisionRoutine* self, cSKM_GOBJ& g) { const cSkaSystem* m = self->animationSystem; const cSkaSystem* o = g.GetSkaSystem(); return m->node.IsAttached(o->node); }
static inline unsigned char IsActive(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    cController* c = g->mController;
    if (c && c->IsActive()) r = 1;
    return r;
}
static inline unsigned char IsSpawned(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    if (g->b2D && g->b2C) r = 1;
    return r;
}
static inline bool Not(unsigned char x) { return !x; }
static inline unsigned char IsAlive(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    if (IsSpawned(g) && Not(g->b2E)) r = 1;
    return r;
}
static inline unsigned char IsDying(cSKM_GOBJ* g)
{
    bool r; unsigned char s = g->GetState();
    r = 1;
    if (s != 3 && s != 2) r = 0;
    return r;
}
static inline unsigned char ZOverlap(const cBox& a, const cBox& b)
{
    unsigned char r = 0;
    if (a.max.z >= b.min.z && a.min.z <= b.max.z) r = 1;
    return r;
}
static inline float Lerp(float a, float b, float t) { return a + t * (b - a); }
static inline float Push(float o, float d, float p, float t) { return p + Lerp(o, 2.8f * d, t); }

extern "C" unsigned char cHumanCollisionRoutine_DetectForAndHandleCollisionWithHuman(cHumanCollisionRoutine* self, cVector& detector_NewPosition, const cBox& detector_Box_WorldSpace, cSKM_GOBJ& detectee_Gobj, float scale)
{
    unsigned char collisionDetected = 0;
    if (IsActive(self->mGobj) || IsActive(&detectee_Gobj)) {
        if (IsAlive(&detectee_Gobj) && !IsDying(&detectee_Gobj) && self->mDoCollisionWithHumans && &detectee_Gobj != self->mGobj
            && !Att(self, detectee_Gobj)) {
            cVector position_OfOtherHuman = detectee_Gobj.GetPosition();
            cVector offsetVector = detector_NewPosition - position_OfOtherHuman;
            cVector xyOffsetVector = offsetVector.GetXY();
            float xyDistSquared = xyOffsetVector.LengthSquared();
            unsigned char xyIntersects = xyDistSquared < 2.8f * 2.8f;
            if (xyIntersects) {
                cBox& box_OfOtherHuman = detectee_Gobj.GetBox();
                cBox detector_Box_WorldSpace_OfOtherHuman = box_OfOtherHuman;
                TB(&detector_Box_WorldSpace_OfOtherHuman, &detectee_Gobj.mXform->GetMatrix());
                if (ZOverlap(detector_Box_WorldSpace_OfOtherHuman, detector_Box_WorldSpace) && xyDistSquared != 0.0f) {
                    cVector xyOffsetDir = xyOffsetVector.GetNormalized();
                    
                    detector_NewPosition.x = Push(xyOffsetVector.GX(), xyOffsetDir.GX(), position_OfOtherHuman.GX(), scale);
                    detector_NewPosition.Y() = Push(xyOffsetVector.y, xyOffsetDir.y, position_OfOtherHuman.y, scale); collisionDetected = 1;
                }
            }
        }
    }
    return collisionDetected;
}
