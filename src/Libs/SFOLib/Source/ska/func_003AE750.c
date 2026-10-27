/* cSkaAnimAnchorList_Update (proto cSkaAnimAnchorList::Update): rebuilds the skeleton target as the
 * hemisphere-aligned sum of every anchor's weighted target transform, then the blend of the anchors'
 * world transforms weighted by each anchor's weight; both rotations are normalised (identity when zero)
 * and the positions get w = 1. */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

struct cVector {
    float x, y, z, w;
    cVector() {}
    /* quad copy (lq/sq; C has no 128-bit move) */
    cVector(const cVector& o) { const cVector* s = &o; cVector* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(d) : "memory"); }
    /* VU0 add in place */
    cVector& operator+=(const cVector& o) { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
    /* 4D dot product through VU0 (sum in vf4w, moved to an FPR) */
    float Dot(const cVector& o) const
    {
        float ret = 0.0f;
        int t;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $zero, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddaz.w $ACC, $vf0, $vf3z; vmaddw.w $vf4, $vf0, $vf3w; qmfc2 %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "=f"(ret), "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return ret;
    }
    /* q = -q (ACC = 0, vf1 = ACC - vf1 * 1) */
    void Negate() { cVector* d = this; cVector* s = this; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%1)" : : "r"(s), "r"(d) : "memory"); }
    void Normalize() { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyzw $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddaz.w $ACC, $vf0, $vf2z; vmaddw.w $vf3, $vf0, $vf2w; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyzw $vf4, $vf1, $Q; sqc2 $vf4, 0x0(%0)" : : "r"(this) : "memory"); }
    void SetIdentity() { __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(this) : "memory"); }
    void SetW(float f) { cVector* p = this; p->w = f; }
    void Zero() { __asm__ volatile("sq $zero, 0x0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));

struct cQuaternion : cVector {
    /* quad copy; xx is dead on purpose (retail keeps the extra addiu, and reuses it for a following Dot) */
    cQuaternion() {}
    cQuaternion(const cQuaternion& o) { const cVector* s = &o; cVector* xx = this; __int128 q; cVector* d = this; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(d) : "memory"); }
};
/* VU0 scale (vmulx) into a temporary, returned by value (as the ska.cc siblings) */
static inline cQuaternion ScaleGQ(const cVector* v, float s)
{
    cQuaternion r; int t; cQuaternion* q = &r;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2 %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "=r"(t) : "r"(v), "r"(q), "f"(s) : "memory");
    return *q;
}
/* VU0 scale into a temporary, then copied out (the ska.cc ScaleTo form) */
static inline void ScaleTo(cVector* out, const cVector* v, float s)
{
    cVector r; int t; cVector* q = &r;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2 %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "=r"(t) : "r"(v), "r"(q), "f"(s) : "memory");
    { cVector* pd; __int128 t2; pd = out; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t2) : "r"(q)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t2), "r"(pd) : "memory"); }
}
/* VU0 all-components-zero test (status flags) */
static inline int IsZero(const cVector* v)
{
    int k, fl;
    unsigned char r;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
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

struct cQuatVec {
    cQuaternion rot;
    cVector pos;
    void Zero() { rot.Zero(); pos.Zero(); }
};
struct cSkaAnimAnchor_TreeNode;
struct cSkaAnimAnchor {
    char pad0[0xD0];
    float weight;
};
struct cSkaAnimAnchorListEntry {
    char name[0x10];
    cSkaAnimAnchor anchor;
    char pad[0x180 - 0x10 - sizeof(cSkaAnimAnchor)];
};
struct cSkaAnimAnchorList;
extern "C" {
cSkaAnimAnchorListEntry** std_vector_deleter_cSkaAnimAnchorListEntry_data(cSkaAnimAnchorList* l);
unsigned char cSkaAnimAnchor_Update(cSkaAnimAnchor* a, cVector* rot, cVector* pos);
cQuatVec* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cSkaAnimAnchor* a);
cVector* cQuatVec_Rotation(cQuatVec* q);
cVector* cQuatVec_Translation(cQuatVec* q);
void cSkaAnimAnchorList_Update(cSkaAnimAnchorList* self);
}
struct Iterator {
    cSkaAnimAnchorListEntry* p;
    explicit Iterator(cSkaAnimAnchorListEntry* e) { p = e; }
    Iterator(const Iterator& o) { p = o.p; }
    void operator++() { p++; }
    cSkaAnimAnchorListEntry* operator->() const { return p; }
};
inline bool operator==(const Iterator& a, const Iterator& b) { cSkaAnimAnchorListEntry* q = b.p; return a.p == q; }
inline bool operator!=(const Iterator& a, const Iterator& b) { return !(a == b); }
struct cSkaAnimAnchorList {
    int unk0;
    int count;
    char pad8[8];
    cQuatVec skeletonTarget;
    cQuatVec blendOfAnchorTransforms;
    Iterator begin() { Iterator it(*std_vector_deleter_cSkaAnimAnchorListEntry_data(this)); return it; }
    Iterator end() { Iterator it(*std_vector_deleter_cSkaAnimAnchorListEntry_data(this) + count); return it; }
};

void cSkaAnimAnchorList_Update(cSkaAnimAnchorList* self)
{
    cQuaternion prevTargetRot = self->skeletonTarget.rot;
    self->skeletonTarget.Zero();
    for (Iterator curr = self->begin(), end = self->end(); curr != end; ++curr) {
        cSkaAnimAnchor& anchor = curr->anchor;
        cQuaternion weightedSkeletonTargetRot;
        cVector weightedSkeletonTargetPos;
        if (cSkaAnimAnchor_Update(&anchor, &weightedSkeletonTargetRot, &weightedSkeletonTargetPos)) {
            if (weightedSkeletonTargetRot.Dot(prevTargetRot) < 0.0f)
                weightedSkeletonTargetRot.Negate();
            self->skeletonTarget.rot += weightedSkeletonTargetRot;
            self->skeletonTarget.pos += weightedSkeletonTargetPos;
        }
    }
    if (IsZero(&self->skeletonTarget.rot))
        self->skeletonTarget.rot.SetIdentity();
    else
        self->skeletonTarget.rot.Normalize();
    self->skeletonTarget.pos.SetW(1.0f);

    cQuaternion prevBlendOfAnchorTransforms_Rotation = self->blendOfAnchorTransforms.rot;
    self->blendOfAnchorTransforms.Zero();
    for (Iterator curr = self->begin(), end = self->end(); curr != end; ++curr) {
        cSkaAnimAnchor& anchor = curr->anchor;
        if (anchor.weight > 0.0f) {
            cQuaternion weightedAnchorRot = ScaleGQ(cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&anchor)), anchor.weight);
            if (weightedAnchorRot.Dot(prevBlendOfAnchorTransforms_Rotation) < 0.0f)
                weightedAnchorRot.Negate();
            self->blendOfAnchorTransforms.rot += weightedAnchorRot;
            cVector weightedAnchorTrans;
            ScaleTo(&weightedAnchorTrans, cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&anchor)), anchor.weight);
            { cVector* pos = &self->blendOfAnchorTransforms.pos; *pos += weightedAnchorTrans; }
        }
    }
    if (IsZero(&self->blendOfAnchorTransforms.rot))
        self->blendOfAnchorTransforms.rot.SetIdentity();
    else
        self->blendOfAnchorTransforms.rot.Normalize();
    self->blendOfAnchorTransforms.pos.w = 1.0f;
}
