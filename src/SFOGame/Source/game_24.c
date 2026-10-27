/*
 * SFOGame/Source/game: 6 files, 001322F0-00132400
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001322F0 */
#pragma push /* merge_units */
#pragma peephole off
#include "types.h"
typedef struct { float v[4]; } __attribute__((aligned(16))) V4D4;
typedef struct { float m[3][4]; V4D4 pos; } MtxD4;
MtxD4* cMatrix_Set_cMatrixR_cVectorR(MtxD4* d, MtxD4* b, V4D4* p)
{
    
    d->m[0][0] = b->m[0][0];
    d->m[0][1] = b->m[0][1];
    d->m[0][2] = b->m[0][2];
    d->m[1][0] = b->m[1][0];
    d->m[1][1] = b->m[1][1];
    d->m[1][2] = b->m[1][2];
    d->m[2][0] = b->m[2][0];
    d->m[2][1] = b->m[2][1];
    d->m[2][2] = b->m[2][2];
    d->m[0][3] = b->m[0][3];
    d->m[1][3] = b->m[1][3];
    d->m[2][3] = b->m[2][3];
    d->pos = *p;
    return d;
}
#pragma peephole reset
static inline void merge_flush_func_001322F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001322F0 */

/* merge_units: begin func_00132370 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cQuatVec_Translation(char* self) {
    return self + 16;
}
static inline void merge_flush_func_00132370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132370 */

/* merge_units: begin func_00132380 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cMatrix_ctor_cQuaternionR(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(b)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(a)
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
    }
    return a;
}
static inline void merge_flush_func_00132380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132380 */

/* merge_units: begin func_001323F0 */
#pragma push /* merge_units */
void* cQuatVec_Rotation(void* self) {
    return self;
}
static inline void merge_flush_func_001323F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001323F0 */

/* merge_units: begin func_00132400 */
#pragma push /* merge_units */
V4* cQuatVec_Translate(V4* a, V4* b); /* gsynth: defined below */typedef struct { Vec4 q; Vec4 pos; } F8Plc;
typedef struct { F8Plc world; char pad20[0x30]; F8Plc local; } F8RootW;
typedef struct F8Root { char pad0[0xA0]; unsigned char dirty; char padA1[0xF]; struct F8Root* parent; } F8Root;
extern F8RootW* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* self);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(F8Root* r);
extern void cSkaAnimAnchor_TreeNode_UpdateTransform(F8Root* r);
extern Vec4* cQuaternion_opAssign(Vec4* d, Vec4* s);
extern Vec4* cVector_opAssign(Vec4* d, Vec4* s);
#if 0 /* merge_units */
extern void* cQuatVec_Rotation(F8Plc* p);
#endif /* merge_units */
#define cQuatVec_Rotation(a0) (cQuatVec_Rotation((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void* cQuatVec_Translation(F8Plc* p);
#endif /* merge_units */
#define cQuatVec_Translation(a0) (cQuatVec_Translation((char *)(a0))) /* merge_units */

extern void cQuatVec_Rotate(F8RootW* w, void* q);
#if 0 /* merge_units */
extern void cQuatVec_Translate(F8RootW* w, void* pos);
#endif /* merge_units */
#define cQuatVec_Translate(a0, a1) ((void)cQuatVec_Translate((V4 *)(a0), (V4 *)(a1))) /* merge_units */


static inline void F8PlcCopy(F8Plc* d, F8Plc* s)
{
    cQuaternion_opAssign(&d->q, &s->q);
    cVector_opAssign(&d->pos, &s->pos);
}
F8RootW* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(F8Root* r)
{
    F8Root* p = r->parent;
    if (p != 0) {
        if (p && r->dirty) {
            F8Plc* pp;
            F8Plc* local;
            F8RootW* world;
            F8RootW* w;
            if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(p)) {
                cSkaAnimAnchor_TreeNode_UpdateTransform(p);
                pp = &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(p)->world;
            } else {
                pp = &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(p)->local;
            }
            F8PlcCopy(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->world, &cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r)->local);
            w = cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
            cQuatVec_Rotate(w, cQuatVec_Rotation(pp));
            cQuatVec_Translate(w, cQuatVec_Translation(pp));
            r->dirty = 0;
        }
        return (F8RootW*)r;
    }
    return (F8RootW*)&((F8RootW*)r)->local;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132400(void) {}
#undef cQuatVec_Rotation /* merge_units */
#undef cQuatVec_Translation /* merge_units */
#undef cQuatVec_Translate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132400 */

/* merge_units: begin func_00132510 */
#pragma push /* merge_units */
V4* cQuatVec_Translate(V4* a, V4* b) {
    char* pv0 = (char*)a + 0x10;
    asm {
        lqc2 vf1, 0x0(pv0)
        lqc2 vf2, 0x0(b)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(pv0)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132510 */
