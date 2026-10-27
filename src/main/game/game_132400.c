/*
 * main/game: range (2 files, 00132400-00132510)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00132400 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cQuatVec_Translate(V4* a, V4* b); /* gsynth: defined below */typedef struct { Vec4 q; Vec4 pos; } F8Plc;
typedef struct { F8Plc world; char pad20[0x30]; F8Plc local; } F8RootW;
typedef struct F8Root { char pad0[0xA0]; unsigned char dirty; char padA1[0xF]; struct F8Root* parent; } F8Root;
extern F8RootW* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* self);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(F8Root* r);
extern void cSkaAnimAnchor_TreeNode_UpdateTransform(F8Root* r);
extern Vec4* cQuaternion_opAssign(Vec4* d, Vec4* s);
extern Vec4* cVector_opAssign(Vec4* d, Vec4* s);
extern void* cQuatVec_Rotation(F8Plc* p);
extern void* cQuatVec_Translation(F8Plc* p);
extern void cQuatVec_Rotate(F8RootW* w, void* q);
#if 0 /* merge_units */
extern void cQuatVec_Translate(F8RootW* w, void* pos);
#endif /* merge_units */
#define cQuatVec_Translate(a0, a1) ((void)cQuatVec_Translate((void *)(a0), (void *)(a1))) /* merge_units */

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
#undef cQuatVec_Translate /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132400(void) {}
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
