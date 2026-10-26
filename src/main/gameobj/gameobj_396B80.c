/*
 * main/gameobj: range (6 files, 00396B80-00396F30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vector_destroy_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

/* merge_units: begin func_00396B80 */
#pragma push /* merge_units */
/* Destroy every 0x1D0-byte element from the back, then empty the array. */
typedef struct { unsigned char b[0x1D0]; } Elem_396B80;
typedef struct { int pad0; int count; Elem_396B80* data; } Arr_396B80;
extern void cBone_dtor(Elem_396B80* e, int flag);

void std_vector_deleter_cBone_clear(Arr_396B80* a)
{
    Elem_396B80* first = a->data;
    Elem_396B80* last = first + a->count;
    while (first < last) {
        last--;
        cBone_dtor(last, -1);
    }
    a->count = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396B80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396B80 */

/* merge_units: begin func_00396C10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
extern "C" {
char D_004BC4C0[] = "allocator.hh";
}
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_00396C10, MotionGroup_ClearContributions, D_004BC4C0)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396C10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396C10 */

/* merge_units: begin func_00396D00 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct P1C9F10 { char pad[0x10]; char memberA[0x110]; char memberB[4]; };
extern "C" P1C9F10* cSkaAnimAnchorListEntry_dtor(P1C9F10* self, short deleteFlag); /* gsynth: defined below */
#pragma pop
typedef struct { char d[0x180]; } g2E180;
typedef struct { int pad0; int size; g2E180* data; } g2Vec180;
#if 0 /* merge_units */
extern void cSkaAnimAnchorListEntry_dtor(g2E180* e, int flag);
#endif /* merge_units */
#define cSkaAnimAnchorListEntry_dtor(a0, a1) ((void)cSkaAnimAnchorListEntry_dtor((void *)(a0), (short)(a1))) /* merge_units */

void std_vector_deleter_cSkaAnimAnchorListEntry_clear(g2Vec180* v) {
    g2E180* b = v->data;
    g2E180* e = b + v->size;
    while (b < e) {
        --e;
        cSkaAnimAnchorListEntry_dtor(e, -1);
    }
    v->size = 0;
}
#undef cSkaAnimAnchorListEntry_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396D00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396D00 */

/* merge_units: begin func_00396D80 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct Root_396DF0 { unsigned char pad[0xB4]; int list; };
extern "C" Root_396DF0* cSkaAnimAnchor_TreeNode_dtor(Root_396DF0* self, short deleteFlag); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
void cSkaAnimAnchor_TreeNode_dtor(void* member, int flags);
#endif /* merge_units */
#define cSkaAnimAnchor_TreeNode_dtor(a0, a1) ((void)cSkaAnimAnchor_TreeNode_dtor((Root_396DF0 *)(a0), (short)(a1))) /* merge_units */

void cArray_FixedSize_cVector_4_dtor(void* member, int flags);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

}

extern "C" P1C9F10* cSkaAnimAnchorListEntry_dtor(P1C9F10* self, short deleteFlag)
{
    if (self) {
        if (self->memberA) {
            cArray_FixedSize_cVector_4_dtor(self->memberB, -1);
            cSkaAnimAnchor_TreeNode_dtor(self->memberA, -1);
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#undef cSkaAnimAnchor_TreeNode_dtor /* merge_units */
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396D80 */

/* merge_units: begin func_00396DF0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor of an animated root: restore placement, detach children. */
struct V4_396DF0 { __int128 q; };
struct VP_396DF0 { V4_396DF0 a, b; };


extern "C" {
int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(Root_396DF0* r);
VP_396DF0* Root_GetWorldPlacement(Root_396DF0* r);
V4_396DF0* Root_GetWorldMotion(Root_396DF0* r);
VP_396DF0* SceneRoot_GetPoseCache(Root_396DF0* r);
void VecPair_Copy(VP_396DF0* dst, VP_396DF0* src);
void Vec4_Assign(V4_396DF0* dst, V4_396DF0* src);
void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(Root_396DF0* r);
void Root_SetWorldPlacement(Root_396DF0* r, VP_396DF0* p);
void cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(Root_396DF0* r, V4_396DF0* m);
void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(Root_396DF0* r, VP_396DF0* p);
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(Root_396DF0* r);
int cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Empty(void* v);
int* PtrVec_Back(void* v);
void cSkaAnimAnchor_TreeNode_DetachChild(Root_396DF0* r, int child);
void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachChildren(Root_396DF0* r);
void* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_dtor(void* p, short deleteFlag);
void operator_delete(void* allocation);
}

extern "C" Root_396DF0* cSkaAnimAnchor_TreeNode_dtor(Root_396DF0* self, short deleteFlag)
{
    if (self) {
        if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(self)) {
            VP_396DF0 place;
            V4_396DF0 motion;
            VP_396DF0 other;
            VecPair_Copy(&place, Root_GetWorldPlacement(self));
            Vec4_Assign(&motion, Root_GetWorldMotion(self));
            VecPair_Copy(&other, SceneRoot_GetPoseCache(self));
            cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(self);
            Root_SetWorldPlacement(self, &place);
            cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(self, &motion);
            cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(self, &other);
        }
        while (!cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Empty(cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(self)))
            cSkaAnimAnchor_TreeNode_DetachChild(self, *PtrVec_Back(cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(self)));
        if (self) {
            cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(self);
            cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachChildren(self);
            cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_dtor(&self->list, -1);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396DF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396DF0 */

/* merge_units: begin func_00396F30 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_dtor, std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00396F30 */
