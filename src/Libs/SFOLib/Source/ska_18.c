/*
 * Libs/SFOLib/Source/ska: 4 files, 003AE740-003AEBA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AE740 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "types.h"

void* func_003AE740(char* self) {
    return self + 8;
}
static inline void merge_flush_func_003AE740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE740 */

/* merge_units: begin func_003AE750 */
#pragma push /* merge_units */
/* cSkaAnimAnchorList_Update (proto cSkaAnimAnchorList::Update): rebuilds the skeleton target as the
 * hemisphere-aligned sum of every anchor's weighted target transform, then the blend of the anchors'
 * world transforms weighted by each anchor's weight; both rotations are normalised (identity when zero)
 * and the positions get w = 1. */
#pragma cplusplus on
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
static inline void merge_flush_func_003AE750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE750 */

/* merge_units: begin func_003AEBA0 */
#pragma push /* merge_units */
/* cSkaAnimAnchorList_ClearAccumulation (ska.cc): reset every root entry's accumulation state.
 * The asm zero stores (VZeroF) keep the iterators in stack slots like retail. */
#include "vc_copy.h"
#pragma cplusplus on
#pragma bool on
typedef int Q128 __attribute__((mode(TI)));
struct RSub_3AEBA0 { char pad[0xE0]; Q128 a; Q128 b; float w; int pad2[3]; Q128 q[4]; char pad3[0x20]; };
struct REnt_3AEBA0 { int pad0[4]; RSub_3AEBA0 sub; };
struct RColl_3AEBA0 { int pad0; int count; };
struct RIt_3AEBA0;
static inline bool REq(const RIt_3AEBA0* a, const RIt_3AEBA0* b);
struct RIt_3AEBA0 {
    REnt_3AEBA0* p;
    RIt_3AEBA0(REnt_3AEBA0* x) : p(x) {}
    RIt_3AEBA0(const RIt_3AEBA0& o) : p(o.p) {}
    bool operator==(const RIt_3AEBA0& o) const { return REq(this, &o); }
    bool operator!=(const RIt_3AEBA0& o) const { return !(*this == o); }
    REnt_3AEBA0* operator->() const { return p; }
    RIt_3AEBA0& operator++() { p++; return *this; }
};
static inline bool REq(const RIt_3AEBA0* a, const RIt_3AEBA0* b) { REnt_3AEBA0* bp = b->p; return a->p == bp; }
#if 0 /* merge_units */
extern "C" REnt_3AEBA0** std_vector_deleter_cSkaAnimAnchorListEntry_data(RColl_3AEBA0*);
#endif /* merge_units */
#define std_vector_deleter_cSkaAnimAnchorListEntry_data(a0) ((REnt_3AEBA0 * *)std_vector_deleter_cSkaAnimAnchorListEntry_data((cSkaAnimAnchorList *)(a0))) /* merge_units */

static inline RIt_3AEBA0 RBegin(RColl_3AEBA0* c) { RIt_3AEBA0 r(*std_vector_deleter_cSkaAnimAnchorListEntry_data(c)); return r; }
static inline RIt_3AEBA0 REnd(RColl_3AEBA0* c) { RIt_3AEBA0 r(*std_vector_deleter_cSkaAnimAnchorListEntry_data(c) + c->count); return r; }
static inline void RSubReset(RSub_3AEBA0* s, float z) {
    *(int*)((char*)s + 0xD0) = 0;
    VZeroF(&s->a);
    VZeroF(&s->b);
    s->w = z;
    for (Q128* q = s->q; q != s->q + 4; q++) VZeroF(q);
}
#pragma opt_rotateloops off
#pragma opt_propagation off
extern "C" void cSkaAnimAnchorList_ClearAccumulation(RColl_3AEBA0* self) {
    RIt_3AEBA0 it = RBegin(self);
    RIt_3AEBA0 end = REnd(self);
    for (; it != end; ++it) {
        RSubReset(&it->sub, 0.0f);
    }
}
#undef std_vector_deleter_cSkaAnimAnchorListEntry_data /* merge_units */
static inline void merge_flush_func_003AEBA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AEBA0 */

/* merge_units: begin func_003AEC80 */
#pragma push /* merge_units */
/* Temporary model description built by cSkaAnimAnchorList_ctor_cArrayR. */
typedef struct ModelDesc {
    char header[0x10];
    char first[0x20];
    char second[0x20];
} ModelDesc;

extern void cSkaAnimAnchorList_ctor_cArrayR(ModelDesc* desc);
extern void cArray_cSkaAnimAnchorListEntry_opAssign(void* self, ModelDesc* desc);
extern void cQuatVec_opAssign(void* dst, void* src);
extern void std_vector_deleter_cSkaAnimAnchorListEntry_dtor(ModelDesc* desc, int flags);

/* Initializes a root collection from a temporary model description. */
void cSkaAnimAnchorList_Reset(char* self) {
    ModelDesc desc;
    cSkaAnimAnchorList_ctor_cArrayR(&desc);
    cArray_cSkaAnimAnchorListEntry_opAssign(self, &desc);
    cQuatVec_opAssign(self + 0x10, desc.first);
    cQuatVec_opAssign(self + 0x30, desc.second);
    std_vector_deleter_cSkaAnimAnchorListEntry_dtor(&desc, 0);
}
static inline void merge_flush_func_003AEC80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AEC80 */
