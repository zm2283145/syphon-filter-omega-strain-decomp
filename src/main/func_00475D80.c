#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { Q16(this, &o); }
    V& operator=(const V& o) { Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct P4 : V {
    P4() {}
    /* xx: retail keeps the dead address addiu before the copy */
    P4& Set(const V& o) { void* xx = this; Q16(this, &o); return *this; }
    V& Pt() { w = 1.0f; return *this; }
};
struct Rung { char pad[0x990]; float f990; float f994; float f998; };
struct Ladder { char pad[0x3298]; void* root; char pad2[0x3310 - 0x329C]; Rung* rung; };
extern float D_004A0410;
extern "C" V cHuman_CalculateClosestLadderRungToStopAt(Ladder* l, int i);
extern "C" void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
extern "C" V* cQuatVec_Translation(void*);
extern "C" void cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(void*, V*);
extern "C" void cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(Ladder* l, float t);
static inline bool Rung_Valid(Rung* r) { return r->f990 > -3.4028235e38f && r->f998 < 3.4028235e38f; }
void cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(Ladder* l, float t)
{
    void* root = l->root;
    V tgt = cHuman_CalculateClosestLadderRungToStopAt(l, 0);
    float k = 9.0f * t;
    V* pos = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(root));
    /* declaration order fixes the stack slots: tgt 0x70, p 0x60, tp 0x50, l0 0x40 */
    V p;
    P4 tp;
    V l0;
    V* q1 = &l0;
    V* c = &tgt;
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
