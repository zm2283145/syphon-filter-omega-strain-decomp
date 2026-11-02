/*
 * Libs/SFOLib/Source/ska: 4 files, 003AF2D0-003AFCB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AF2D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies as GCC-style volatile asm; unused xx locals reproduce retail's dead addius (they survive only after an earlier GCC asm) */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Plc;
extern "C" void cQuatVec_ctor_cQuatVecR(Plc* d, const Plc* s);
struct Plc { V rot; V pos; Plc() {} Plc(const Plc& o) { cQuatVec_ctor_cQuatVecR(this, &o); void* xx = this; } };
extern "C" {
extern signed char D_004E1D80;
extern Plc D_00497F00;
void cQuaternion_GetIdentity(V* q);
void cVector_Get0001(V* v);
void cQuatVec_ctor_cQuaternionR_cVectorR(Plc* p, V* q, V* v);
void std_vector_cSkaAnimAnchorListEntry_ctor(void* self);
}
static inline Plc Ident()
{
    if (!D_004E1D80) {
        V q; V v;
        cQuaternion_GetIdentity(&q);
        cVector_Get0001(&v);
        cQuatVec_ctor_cQuaternionR_cVectorR(&D_00497F00, &q, &v);
        D_004E1D80 = 1;
    }
    return D_00497F00;
}
struct S { char pad0[0xC]; unsigned char bC; Plc p10; Plc p30; };
extern "C" S* cSkaAnimAnchorList_ctor_void(S* s);
S* cSkaAnimAnchorList_ctor_void(S* s)
{
    std_vector_cSkaAnimAnchorListEntry_ctor(s);
    s->bC = 1;
    s->p10 = Ident();
    s->p30 = Ident();
    return s;
}
static inline void merge_flush_func_003AF2D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AF2D0 */

/* merge_units: begin func_003AF400 */
#pragma push /* merge_units */
/* cSkaAnimAnchor_Update (003AF400) - ska.cc */
#pragma cplusplus on
#pragma inline_depth(8)
#pragma fp_contract off

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float ax, float ay, float az) { x = ax; y = ay; z = az; }
    float& W() { return w; }
    const float& W() const { return w; }
    cVector(const cVector& o) { void* xx = this; cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(d) : "memory"); }
    cVector& operator=(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(d) : "memory"); return *this; }
    cVector operator+(const cVector& o) const { cVector r; AddTo(o, r); return r; }
    void AddTo(const cVector& b, cVector& r) const { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(this), "r"(&b), "r"(&r) : "memory"); }
    cVector& AddXYZ(const cVector& o) { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
    cVector& operator+=(const cVector& o) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&o), "r"(this) : "memory"); return *this; }
    cVector operator*(float s) const { cVector r; __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2 %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(&r), "r"(this), "f"(s) : "memory"); return r; }
    cVector& operator*=(float s) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %2; qmtc2 %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(this), "f"(s) : "memory"); return *this; }
    void ScaleBy(float s) { __int128 t = 0; cVector* d = this; const cVector* src = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2 %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(src), "r"(d), "f"(s) : "memory"); }
    void AddXYZW(cVector t) { AddXYZ(t); W() = t.W(); }
    float Length() const { float ret = 0.0f; int t; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2 %1, $vf4; mtc1 %1, %0" : "+f"(ret), "=&r"(t) : "r"(this) : "memory"); return ret; }
    void Normalize() { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory"); }
    int IsZero() const {
        int k, fl;
        void* xx = (void*)this;
        unsigned char r = 0;
        const cVector* v = this;
        asm {
            .set noreorder
            lqc2 vf1, 0(v)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni fl, vi17
            bne k, fl, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return r;
    }
} __attribute__((aligned(16)));

struct cQuaternion : cVector {
    cQuaternion() {}
    cQuaternion(const cQuaternion& o) { const cVector* s = &o; cVector* xx = this; cVector* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(d) : "memory"); }
    cQuaternion& operator=(const cQuaternion& o) { __int128 q; cVector* d = this; const cVector* s = &o; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(d) : "memory"); return *this; }
    cQuaternion(const cVector& e);
    cQuaternion operator*(const cQuaternion& b) const {
        cQuaternion r;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%1)" : : "r"(this), "r"(&r), "r"(&b) : "memory");
        return r;
    }
    void Normalize() { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyzw $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddaz.w $ACC, $vf0, $vf2z; vmaddw.w $vf3, $vf0, $vf2w; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyzw $vf4, $vf1, $Q; sqc2 $vf4, 0x0(%0)" : : "r"(this) : "memory"); }
    void Negate() { cVector* d = this; cVector* s = this; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%1)" : : "r"(s), "r"(d) : "memory"); }
    cQuaternion& operator*=(const cQuaternion& b) { cQuaternion& t = *this; t = t * b; return t; }
    void Set(const cQuaternion& o) { void* xx = this; *this = o; }
    void SetIdentity() { __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(this) : "memory"); }
    cVector RotateV(cVector v) const { Rotate(v); return v; }
    void RotateTo(cVector& out, cVector v) const { RotateIn(v); void* xx = &out; out = v; }
    void RotateIn(cVector& v) const { Rotate(v); }
    void Rotate(cVector& v) const {
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmove.w $vf6, $vf1; vmr32.w $vf1, $vf0; lqc2 $vf2, 0x0(%1); vmove.w $vf3, $vf2; vsub.xyz $vf3, $vf0, $vf2; vmul.xyzw $vf4, $vf2, $vf1; vopmula.xyz $ACC, $vf2, $vf1; vmaddaw.xyz $ACC, $vf1, $vf2w; vopmsub.xyz $vf5, $vf1, $vf2; vsubaz.w $ACC, $vf4, $vf4z; vmsubay.w $ACC, $vf0, $vf4y; vmsubx.w $vf5, $vf0, $vf4x; vopmula.xyz $ACC, $vf5, $vf3; vmaddaw.xyz $ACC, $vf5, $vf3w; vmaddaw.xyz $ACC, $vf3, $vf5w; vopmsub.xyz $vf6, $vf3, $vf5; sqc2 $vf6, 0x0(%0)" : : "r"(&v), "r"(this) : "memory");
    }
} __attribute__((aligned(16)));

extern "C" float Libc_Cosf(float);
extern "C" float Libc_Sinf(float);

inline cQuaternion::cQuaternion(const cVector& e) {
    float hx = 0.5f * e.x;
    float hy = 0.5f * e.y;
    float hz = 0.5f * e.z;
    float cx = Libc_Cosf(hx);
    float cy = Libc_Cosf(hy);
    float cz = Libc_Cosf(hz);
    float sx = Libc_Sinf(hx);
    float sy = Libc_Sinf(hy);
    float sz = Libc_Sinf(hz);
    float cycz = cy * cz;
    float sysz = sy * sz;
    float sycz = sy * cz;
    float cysz = cy * sz;
    w = cx * cycz - sx * sysz;
    x = sx * cycz - cx * sysz;
    y = cx * sycz + sx * cysz;
    z = cx * cysz + sx * sycz;
}

struct cQuatVec {
    cQuaternion rot;
    cVector trans;
    cQuatVec(const cQuatVec& o) : rot(o.rot), trans(o.trans) {}
    cQuatVec& operator=(const cQuatVec& o) { rot = o.rot; void* xx = &trans; trans = o.trans; return *this; }
    static void AddW(cVector& v, const cVector& tr, float w) { cVector t = tr * w; v.AddXYZ(t); v.W() = t.W(); }
    void Transform(cQuaternion& q) const { q = rot * q; }
    void TransformFlat(cVector& v) const {
        const cVector& tr = trans;
        rot.Rotate(v);
        float w = v.W();
        if (w == 1.0f) {
            v.AddXYZ(tr);
        } else {
            cVector t = tr * w;
            v.AddXYZ(t);
            v.W() = t.W();
        }
    }
    void Transform(cQuaternion& q, cVector& v) const { q = rot * q; TransformFlat(v); }
    void Transform(cVector& v) const { TransformFlat(v); }
};

struct cDeltaPosModificationFunction {
    virtual void f0();
    virtual void Modify(cVector& v);
};

struct cSkaAnimAnchor_TreeNodeData {
    cQuatVec world;
    char pad20[0x50 - 0x20];
    cQuatVec local;
    char pad70[0xA0 - 0x70];
    unsigned char dirty;
};

struct cSkaAnimAnchor_TreeNode {
    char pad0[0x50];
    cQuatVec transform;
    cVector deltaPos;
    cQuatVec skeletonTarget;
    char pad[0xA1 - 0xA0];
    unsigned char f161;
    unsigned char f162;
    char padA3[0xB0 - 0xA3];
    cSkaAnimAnchor_TreeNode* parent;
    char padB4[0xD0 - 0xB4];
    const cQuatVec& GetTransform() const { return transform; }
    const cQuatVec& GetSkeletonTarget() const { return skeletonTarget; }
    cQuatVec& SkeletonTarget() { return skeletonTarget; }
};

struct cArray_FixedSize_V4 {
    cVector mArray[4];
    cVector& operator[](int i) { return mArray[i]; }
    const cVector& operator[](int i) const { return mArray[i]; }
} __attribute__((aligned(16)));

struct cSkaAnimAnchor {
    cSkaAnimAnchor_TreeNode mTransformNode;
    float summedWeight;
    cQuaternion summedRot;
    cVector summedPos;
    float summedDeltaRot;
    cArray_FixedSize_V4 summedDeltaPos;
    cQuaternion mPrevSummedRot;
    unsigned int numFramesSinceLastRenormalize;
    cDeltaPosModificationFunction* deltaPosModificationFunction;
};

extern "C" {
cSkaAnimAnchor_TreeNodeData* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(cSkaAnimAnchor_TreeNode* n);
const cSkaAnimAnchor_TreeNodeData* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(const cSkaAnimAnchor_TreeNode* n);
cSkaAnimAnchor_TreeNode* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(const cSkaAnimAnchor_TreeNode* n);
void cSkaAnimAnchor_TreeNode_UpdateTransform(const cSkaAnimAnchor_TreeNode* n);
void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(cSkaAnimAnchor_TreeNode* n);
cQuatVec* cQuatVec_opAssign(cQuatVec* d, const cQuatVec* s);
unsigned char cSkaAnimAnchor_Update(cSkaAnimAnchor* self, cQuaternion& weightedSkeletonTargetRot, cVector& weightedSkeletonTargetPos);
}

static inline const cQuatVec& GetTransform_WorldSpace(const cSkaAnimAnchor_TreeNode* n) {
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(n)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(n);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(n)->world;
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(n)->local;
}

unsigned char cSkaAnimAnchor_Update(cSkaAnimAnchor* self, cQuaternion& weightedSkeletonTargetRot, cVector& weightedSkeletonTargetPos) {
    if (self->summedWeight != 0.0f) {
        float oneOverSummedWeight = 1.0f / self->summedWeight;
        cQuatVec transform = self->mTransformNode.GetTransform();
        cQuatVec skeletonTarget = self->mTransformNode.GetSkeletonTarget();
        cVector deltaPos;
        cQuaternion deltaRot(cVector(0.0f, 0.0f, self->summedDeltaRot * oneOverSummedWeight));
        float xLength;
        float yLength;
        float zLength;
        float length;
        cSkaAnimAnchor_TreeNode* parent;

        transform.rot *= deltaRot;
        if (self->numFramesSinceLastRenormalize >= 20) {
            transform.rot.Normalize();
            self->numFramesSinceLastRenormalize = 0;
        } else {
            self->numFramesSinceLastRenormalize++;
        }
        xLength = self->summedDeltaPos[1].Length();
        yLength = self->summedDeltaPos[2].Length();
        zLength = self->summedDeltaPos[3].Length();
        length = xLength + yLength + zLength;
        cVector summedDeltaPosXYZ = self->summedDeltaPos[1] + self->summedDeltaPos[2] + self->summedDeltaPos[3];
        if (!summedDeltaPosXYZ.IsZero()) {
            summedDeltaPosXYZ.Normalize();
            summedDeltaPosXYZ.ScaleBy(length);
        }
        summedDeltaPosXYZ += self->summedDeltaPos[0];
        transform.rot.RotateTo(deltaPos, summedDeltaPosXYZ * oneOverSummedWeight);
        if (self->deltaPosModificationFunction)
            self->deltaPosModificationFunction->Modify(deltaPos);
        transform.trans.AddXYZ(deltaPos);
        if (self->summedRot.W() < 0.0f)
            self->summedRot.Negate();
        weightedSkeletonTargetRot = self->summedRot;
        transform.Transform(weightedSkeletonTargetRot);
        skeletonTarget.rot = weightedSkeletonTargetRot;
        skeletonTarget.rot.Normalize();
        weightedSkeletonTargetPos = self->summedPos;
        weightedSkeletonTargetPos.W() = self->summedWeight;
        transform.Transform(weightedSkeletonTargetPos);
        skeletonTarget.trans = weightedSkeletonTargetPos;
        (skeletonTarget.trans *= oneOverSummedWeight).W() = 1.0f;
        cQuatVec_opAssign(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(&self->mTransformNode)->local, &transform);
        cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(&self->mTransformNode)->dirty = 1;
        cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(&self->mTransformNode);
        self->mTransformNode.deltaPos = deltaPos;
        self->mTransformNode.f161 = 1;
        self->mTransformNode.SkeletonTarget() = skeletonTarget;
        self->mTransformNode.f162 = 1;
        parent = self->mTransformNode.parent;
        if (parent) {
            const cQuatVec& parentTransform = GetTransform_WorldSpace(parent);
            parentTransform.Transform(weightedSkeletonTargetRot, weightedSkeletonTargetPos);
        }
        self->mPrevSummedRot.Set(self->summedRot);
        return 1;
    } else {
        self->mPrevSummedRot.SetIdentity();
        return 0;
    }
}
static inline void merge_flush_func_003AF400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AF400 */

/* merge_units: begin func_003AFCB0 */
#pragma push /* merge_units */
typedef struct {
    int target; int f4; unsigned char b8; unsigned char b9; char padA[2];
    int fC; int f10; int f14; unsigned char b18; char pad19[3];
    int f1C; int f20; int f24;
} AnimTrans_f3;
typedef struct { char pad[0x6C]; int list; } AnimSel_f3;
AnimTrans_f3* cSkaParams_StartTransPlayback(AnimSel_f3* sel, int a, int b, int target); /* gsynth: defined below */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies and VU0 ops as GCC-style volatile asm; unused xx locals reproduce retail's dead addius */
struct V_003AFCB0 {
    float x, y, z, w;
    V_003AFCB0() {}
    V_003AFCB0(const V_003AFCB0& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V_003AFCB0& operator=(const V_003AFCB0& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    bool IsIdent() const { bool b = w == 1.0f; return b; }
    bool NotIdentR() const { return !IsIdent(); }
    bool NotIdent() const { bool b = !IsIdent(); return b; }
    V_003AFCB0 operator*(const V_003AFCB0& b) const {
        V_003AFCB0 c; const V_003AFCB0* r = &b; const V_003AFCB0* l = this; V_003AFCB0* d = &c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
} __attribute__((aligned(16)));

struct Ctx;
struct EvNode {
    virtual void v0();
    virtual void Eval(float t, const V_003AFCB0* q, Ctx* c);
};
struct Child { char pad0[0x1C]; float k; EvNode* a; EvNode* b; };
struct Sel { char pad0[0x10]; V_003AFCB0 rot; int idx; char vec[4]; };

static inline float MaxF(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

/* Combined rotation (q * self->rot); retail keeps the product in the caller's frame after the inline returns. */
static inline const V_003AFCB0* Pick(Sel* self, const V_003AFCB0* q) {
    const V_003AFCB0* r;
    if (self->rot.NotIdent()) {
        if (q->NotIdentR()) {
            V_003AFCB0 a = *q * self->rot;
            V_003AFCB0 b = a;
            r = &b;
        } else {
            r = &self->rot;
        }
        return r;
    }
    return q;
}
extern "C" {
extern float D_004BCD68;
Child* cSkaParams_GetTransPlayback(Ctx* c, Sel* s);
int cSkaParams_GetSwitchCurrGoalState(Ctx* c, int i);
void* cArray_cSkaSwitchItem_opIndex(void* v, int i);
EvNode* cSkaSwitchItem_WhatToPlay(void* e);
void* cSkaSwitch_GetSwitchValue(Sel* s, Ctx* c);
int cSkaSwitchValue_NextGoalState(void* p);
int cSkaSwitchValue_CurrGoalState(void* p);
int cSkaSwitch_GetTransPlayback(Sel* s, Ctx* c);
#if 0 /* merge_units */
void* cSkaParams_StartTransPlayback(Ctx* c, int a, int b, Sel* s);
#endif /* merge_units */
AnimTrans_f3* cSkaParams_StartTransPlayback(AnimSel_f3* sel, int a, int b, int target); /* merge_units */
#define cSkaParams_StartTransPlayback(a0, a1, a2, a3) ((void *)cSkaParams_StartTransPlayback((AnimSel_f3 *)(a0), (a1), (a2), (int)(a3))) /* merge_units */


void cSkaSwitch_UpdateNodes(Sel* self, float t, const V_003AFCB0* q, Ctx* ctx);
}

void cSkaSwitch_UpdateNodes(Sel* self, float t, const V_003AFCB0* q, Ctx* ctx)
{
    if (t < D_004BCD68) return;
    const V_003AFCB0* r = Pick(self, q);
    Child* ch = cSkaParams_GetTransPlayback(ctx, self);
    if (ch) {
        float u = t * ch->k;
        ch->a->Eval(MaxF(0.0f, t - u), r, ctx);
        ch->b->Eval(u, r, ctx);
    } else {
        cSkaSwitchItem_WhatToPlay(cArray_cSkaSwitchItem_opIndex(&self->vec, cSkaParams_GetSwitchCurrGoalState(ctx, self->idx)))->Eval(t, r, ctx);
    }
    void* p = cSkaSwitch_GetSwitchValue(self, ctx);
    int from = cSkaSwitchValue_NextGoalState(p);
    int to = cSkaSwitchValue_CurrGoalState(p);
    if (from != to && !cSkaSwitch_GetTransPlayback(self, ctx))
        cSkaParams_StartTransPlayback(ctx, from, to, self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AFCB0(void) {}
#undef cSkaParams_StartTransPlayback /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AFCB0 */

/* merge_units: begin func_003AFF10 */
#pragma push /* merge_units */
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern void Alloc_Lock(int);
extern void EnableIntc(int);
extern void* cMemMan_Allocate(int, int, char*, int);
extern void std_list_cSkaTransPlaybackPtr_push_back(int* list, AnimTrans_f3** item);
static inline void* AllocL_f3(int size, char* file, int line)
{
    void* p;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = cMemMan_Allocate(0, size, file, line);
    if (g_ProfileLockEnabled) EnableIntc(9);
    g_ProfileLockDepth--;
    return p;
}
AnimTrans_f3* cSkaParams_StartTransPlayback(AnimSel_f3* sel, int a, int b, int target)
{
    AnimTrans_f3* t[1];
    AnimTrans_f3* p;
    p = AllocL_f3(0x28, "ska.icc", 0x47F);
    if (p) {
        p->target = target;
        p->f4 = 0;
        p->b8 = 0;
        p->b9 = 0;
        p->fC = b;
        p->f10 = a;
        p->f14 = 0;
        p->b18 = 0;
        p->f1C = 0;
        p->f20 = 0;
        p->f24 = 0;
    }
    t[0] = p;
    std_list_cSkaTransPlaybackPtr_push_back(&sel->list, t);
    return t[0];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AFF10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AFF10 */
