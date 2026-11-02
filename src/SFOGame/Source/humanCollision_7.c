/*
 * SFOGame/Source/humanCollision: 3 files, 001E8760-001E8C90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E8760 */
#pragma push /* merge_units */
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
struct cTreeNode; 
#if 0 /* merge_units */
extern "C" unsigned char cTreeNode_cSkaSystemPtr_IsAttached(const cTreeNode* a, const cTreeNode* b);
#endif /* merge_units */
struct RNode; /* merge_units */
extern "C" unsigned char cTreeNode_cSkaSystemPtr_IsAttached(RNode* n, RNode* t); /* merge_units */
#define cTreeNode_cSkaSystemPtr_IsAttached(a0, a1) (cTreeNode_cSkaSystemPtr_IsAttached((RNode *)(a0), (RNode *)(a1))) /* merge_units */

struct cTreeNode { char pad[4]; unsigned char IsAttached(const cTreeNode& o) const { return cTreeNode_cSkaSystemPtr_IsAttached(this, &o); } };
struct cSkaSystem { char pad[0x100]; cTreeNode node; };

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
#undef cTreeNode_cSkaSystemPtr_IsAttached /* merge_units */
static inline void merge_flush_func_001E8760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8760 */

/* merge_units: begin func_001E8C90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cSKM_GOBJ_GetBBox(char* self) {
    return self + 96;
}
static inline void merge_flush_func_001E8C90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8C90 */

/* merge_units: begin func_001E8CA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
extern "C" {
typedef struct RNode RNode;
typedef struct { RNode** data; int count; } RVec;
typedef struct { RNode** p; } RIt;
struct RNode { int f0; RNode* parent; RVec children; };
extern int cTreeNode_cSkaSystemPtr_HasChildren(RNode* n);
extern unsigned char cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(RNode* n, RNode* t);
extern int func_001E8F60(RIt* a, RIt* b);
extern RIt* func_001E8F80(RIt* it);
extern RIt std_vector_cTreeNode_cSkaSystemPtrPtr_end(RVec* v);
extern RIt* func_001E8FC0(RIt* dst, const RIt& src);
extern RIt func_001E8FD0(RVec* v);
extern int func_001E8FE0(RVec* v);
static inline bool NotEmpty(RVec* v) { return !func_001E8FE0(v); }
extern int cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(RIt* a, RIt* b);
extern RIt* func_001E9010(RIt* it);
extern RNode** func_001E9030(RIt* w);
extern void cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(RIt* out, RVec* v);
extern void func_001E9060(RIt* out, RVec* v);
unsigned char cTreeNode_cSkaSystemPtr_IsAttached(RNode* n, RNode* t);
}

static inline bool Check(RNode* n, RNode* t) {
    if (n == t) return 1;
    if (cTreeNode_cSkaSystemPtr_HasChildren(n)) {
        bool found = 0;
        RIt it, end;
        func_001E9060(&it, &n->children);
        cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(&end, &n->children);
        while (cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(&it, &end)) {
            if (cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(*func_001E9030(&it), t)) { found = 1; break; }
            func_001E9010(&it);
        }
        return found;
    }
    return 0;
}

static inline unsigned char Up2(RNode* g, RNode* t) {
    if (g->parent) return cTreeNode_cSkaSystemPtr_IsAttached(g->parent, t);
    return cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(g, t);
}

static inline unsigned char Up1(RNode* p, RNode* t) {
    if (p->parent) return Up2(p->parent, t);
    return Check(p, t);
}

static inline void ItBegin(RIt* it, RVec* v) { func_001E8FC0(it, func_001E8FD0(v)); }
static inline void ItEnd(RIt* it, RVec* v) { func_001E8FC0(it, std_vector_cTreeNode_cSkaSystemPtrPtr_end(v)); }
static inline bool Search(RNode* n, RNode* t) {
    if (n == t) return 1;
    if (NotEmpty(&n->children)) {
        bool found = 0;
        RIt it, end;
        ItBegin(&it, &n->children);
        ItEnd(&end, &n->children);
        while (!func_001E8F60(&it, &end)) {
            if (Check(*it.p, t)) { found = 1; break; }
            func_001E8F80(&it);
        }
        return found;
    }
    return 0;
}

extern "C" unsigned char cTreeNode_cSkaSystemPtr_IsAttached(RNode* n, RNode* t) {
    if (n->parent) return Up1(n->parent, t);
    return Search(n, t);
}
static inline void merge_flush_func_001E8CA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8CA0 */
