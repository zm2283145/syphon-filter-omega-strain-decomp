/*
 * SFOGame/Source/humanCollision: 6 files, 001E5550-001E5700
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E5550 */
#pragma push /* merge_units */
/* RayProbe ctor: function-local static zero V (guard D_004E1D88) written out by hand with externs. */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct P { int a, b; } __attribute__((aligned(16)));
struct S {
    signed char a;
    V v10;
    V v20;
    P v30;
    V v40;
    V v50;
    unsigned char c60;
    unsigned char c61;
    unsigned char c62;
    int i64;
};
extern signed char D_004E1D88; extern V D_004E1D90;
static inline const V& Zero() { if (!D_004E1D88) { D_004E1D90.x = 0.0f; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f; D_004E1D88 = 1; } return D_004E1D90; }
static inline V Unit() { V l0; V* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
extern "C" S* cCollisionProbe_Ray_ctor(S* p, const V& e, const V& s)
{
    p->a = 0;
    p->v10 = Zero();
    p->v20 = Unit();
    p->v30.a = 0;
    p->v30.b = 0;
    p->v40 = s;
    p->v50 = e;
    p->c60 = 0;
    p->c61 = 0;
    p->c62 = 0;
    p->i64 = 0;
    return p;
}
static inline void merge_flush_func_001E5550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5550 */

/* merge_units: begin func_001E5610 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cVector_opAddAssign(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
    return a;
}
static inline void merge_flush_func_001E5610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5610 */

/* merge_units: begin func_001E5630 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Read a scalar (used for the physical mass at actor +0x2E0, research
 * ACTOR_RESPONSE_PROBES.md). */
float cPointMass_GetMass(float* value) {
    return value[0];
}
static inline void merge_flush_func_001E5630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5630 */

/* merge_units: begin func_001E5640 */
#pragma push /* merge_units */
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void* r);
extern void cSkaAnimAnchor_TreeNode_UpdateDeltaPos(void* r);
extern char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* r);
char* cSkaAnimAnchor_GetDeltaPos(void* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateDeltaPos(r);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x20;
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x70;
}
static inline void merge_flush_func_001E5640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5640 */

/* merge_units: begin func_001E56A0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void* r);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(a0) ((void *)cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void((a0))) /* merge_units */

extern void* cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(void* r);
void* cSkaAnimAnchor_GetSkeletonTargetTransform(void* r) {
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r) != 0) {
        cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(r);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x30;
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x80;
}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void /* merge_units */
static inline void merge_flush_func_001E56A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E56A0 */

/* merge_units: begin func_001E5700 */
#pragma push /* merge_units */
#include "loose00_types.h"

FloatPair* cVector_SetY(FloatPair* self, float value) {
    self->b = value;
    return self;
}
static inline void merge_flush_func_001E5700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5700 */
