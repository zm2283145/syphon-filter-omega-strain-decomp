/*
 * SFOGame/Source/humanLadder: 4 files, 00475B40-00475D80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00475B40 */
#pragma push /* merge_units */
#include "types.h"
typedef struct H1Chan { float unk0; float prev; float last; float pad0C; float cur; char pad14[0x3C - 0x14]; } H1Chan;
typedef struct H1Anim { char pad00[0x80]; H1Chan* chans; } H1Anim;
static inline float h1_fabs(float x) { float r; asm { abs.s r, x } return r; }
static inline unsigned char h1_far(float a, float b, float t) { return h1_fabs(a - b) > t; }
unsigned char cSkaParams_HasJustArrivedAtTarget(H1Anim* a, int ch, float thr) {
    H1Chan* c = &a->chans[ch];
    float cur = c->cur;
    unsigned char r = h1_fabs(cur - c->last) <= thr;
    if (r) r = h1_far(cur, c->prev, thr);
    return r;
}
static inline void merge_flush_func_00475B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00475B40 */

/* merge_units: begin func_00475BB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after NetMsgThrottle.cc (ends 0x00472370).
 */

#include "loose05_types.h"

extern int cSkaParams_SetSliderValue_UsingSplineForInterpolation(void* channel, int anim, int arg, float weight, float blend, float start);

/* Clears flag bits 25 and 26, then retargets the animation channel to anim 21. */
int cHuman_LadderClearOneRungOff(Char475BB0* self) {
    unsigned int flags;

    flags = self->flags;
    self->flags = flags & 0xfdffffff;
    flags = self->flags;
    self->flags = flags & 0xfbffffff;
    return cSkaParams_SetSliderValue_UsingSplineForInterpolation(self->animChannel, 21, 0, 1.0f, 0.5f, 0.0f);
}
static inline void merge_flush_func_00475BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00475BB0 */

/* merge_units: begin func_00475C00 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" int cSkaParams_SetSliderValue_UsingSplineForInterpolation(void* channel, int anim, int arg, float weight, float blend, float start);
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { Q16(this, &o); }
    V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; }
} __attribute__((aligned(16)));
struct P4 : V {
    P4() {}
    P4& Set(const V& o) { P4* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(&o) : "memory"); return *this; }
    V& SetZ(float nz) { z = nz; return *this; }
};
struct Rung { char pad[0x990]; float f990; float f994; float f998; };
struct Anim { char pad[0x10]; char chan[1]; void Play() { Anim* a = this; cSkaParams_SetSliderValue_UsingSplineForInterpolation(a->chan, 0x15, 0, 0.0f, 0.5f, 0.0f); } };
struct Ladder { char pad[0x2EC0]; Anim anim; char pad2ED4[0x3248 - 0x2ED1]; unsigned int flags; char pad324C[0x3294 - 0x324C]; void* root; char pad2[0x3310 - 0x3298]; Rung* rung; };
struct LChar { char pad[0x2EC0]; struct { char pad[0x10]; char chan[1]; } anim; };
extern float D_004A0410;
extern "C" void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
#if 0 /* merge_units */
extern "C" V* cQuatVec_Translation(void*);
#endif /* merge_units */
extern "C" void* cQuatVec_Translation(void*); /* merge_units */
#define cQuatVec_Translation(a0) ((V *)cQuatVec_Translation((a0))) /* merge_units */

#if 0 /* merge_units */
extern "C" void cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(void*, V*);
#endif /* merge_units */
extern "C" void cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(void*, void*); /* merge_units */
#define cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(a0, a1) (cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace((a0), (void *)(a1))) /* merge_units */

extern "C" int AnimChannel_SetTarget_(void* channel, int anim, int arg, float weight, float blend, float start);
static inline bool Rung_Valid(Rung* r) { return r->f990 > -3.4028235e38f && r->f998 < 3.4028235e38f; }
extern "C" void cHuman_LadderSetOneRungOff(Ladder* l, int top)
{
    V t1;
    V t2;
    P4 p1;
    P4 p2;
    void* root;
    V* pos;
    if (l->rung && Rung_Valid(l->rung)) {
        root = l->root;
        pos = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(root));
        if (top) {
            float y = l->rung->f998 + D_004A0410;
            V& r = p1.Set(*pos).SetZ(y - 1.0f); t1 = r;
            cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(root, &t1);
            l->flags |= 0x02000000;
        } else {
            Rung* r = l->rung;
            V& q = p2.Set(*pos).SetZ(r->f990); t2 = q;
            cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(root, &t2);
            l->flags |= 0x04000000;
        }
        l->anim.Play();
    }
}
#undef cQuatVec_Translation /* merge_units */
#undef cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace /* merge_units */
static inline void merge_flush_func_00475C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00475C00 */

/* merge_units: begin func_00475D80 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

struct V_00475D80 {
    float x, y, z, w;
    V_00475D80() {}
    V_00475D80(const V_00475D80& o) { Q16(this, &o); }
    V_00475D80& operator=(const V_00475D80& o) { Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct P4_00475D80 : V_00475D80 {
    P4_00475D80() {}
    /* xx: retail keeps the dead address addiu before the copy */
    P4_00475D80& Set(const V_00475D80& o) { void* xx = this; Q16(this, &o); return *this; }
    V_00475D80& Pt() { w = 1.0f; return *this; }
};
struct Ladder_00475D80 { char pad[0x3298]; void* root; char pad2[0x3310 - 0x329C]; Rung* rung; };
extern "C" V_00475D80 cHuman_CalculateClosestLadderRungToStopAt(Ladder_00475D80* l, int i);
#if 0 /* merge_units */
extern "C" V_00475D80* cQuatVec_Translation(void*);
#endif /* merge_units */
#define cQuatVec_Translation(a0) ((V_00475D80 *)cQuatVec_Translation((a0))) /* merge_units */

#if 0 /* merge_units */
extern "C" void cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(void*, V_00475D80*);
#endif /* merge_units */
#define cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(a0, a1) (cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace((a0), (void *)(a1))) /* merge_units */

extern "C" void cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(Ladder_00475D80* l, float t);
void cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(Ladder_00475D80* l, float t)
{
    void* root = l->root;
    V_00475D80 tgt = cHuman_CalculateClosestLadderRungToStopAt(l, 0);
    float k = 9.0f * t;
    V_00475D80* pos = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(root));
    /* declaration order fixes the stack slots: tgt 0x70, p 0x60, tp 0x50, l0 0x40 */
    V_00475D80 p;
    P4_00475D80 tp;
    V_00475D80 l0;
    V_00475D80* q1 = &l0;
    V_00475D80* c = &tgt;
    int rv1;
    /* VU0 lerp (same sequence as src/main/human/Vec4_Lerp.c) */
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf3; vaddax.xyzw ACC, vf1, vf0x; vmaddax.xyzw ACC, vf2, vf3x; vmsubx.xyzw vf4, vf1, vf3x; sqc2 vf4, 0x0(%4)"
                     : "=&r"(rv1) : "r"(pos), "r"(c), "f"(k), "r"(q1) : "memory");
    p = tp.Set(l0).Pt();
    if (l->rung && Rung_Valid(l->rung)) {
        float v = 0.0f;
        float lo = l->rung->f998 + D_004A0410;
        float hi = l->rung->f990;
        float y = p.z;
        asm { max.s v, y, lo; min.s v, v, hi }
        p.z = v;
    }
    cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(root, &p);
}
#undef cQuatVec_Translation /* merge_units */
#undef cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace /* merge_units */
static inline void merge_flush_func_00475D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00475D80 */
