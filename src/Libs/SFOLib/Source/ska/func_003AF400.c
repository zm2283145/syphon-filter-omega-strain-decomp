/* cSkaAnimAnchor_Update (003AF400) - ska.cc */
#pragma cplusplus on
#include "types.h"
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
