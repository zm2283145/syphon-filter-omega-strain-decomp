/*
 * SFOGame/Source/human: 5 files, 001A0890-001A09F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A0890 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(char* self) {
    return *(int*)(self + 8);
}
static inline void merge_flush_func_001A0890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0890 */

/* merge_units: begin func_001A08D0 */
#pragma push /* merge_units */
#pragma opt_common_subs off
typedef struct { char pad[0x10]; int set; } E_1A08D0;
typedef struct { E_1A08D0*** p; } It_1A08D0;
typedef struct { int n; } SIt_1A08D0;
typedef struct { char pad[0x108]; int vec; } O_1A08D0;
#if 0 /* merge_units */
extern E_1A08D0*** std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(int* v);
#endif /* merge_units */
#define std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(a0) ((E_1A08D0 * * *)std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void((char *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern E_1A08D0*** std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(int* v);
#endif /* merge_units */
#define std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(a0) ((E_1A08D0 * * *)std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void((PtrVec *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(It_1A08D0* out, int* v, E_1A08D0**** p);
#endif /* merge_units */
#define std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(a0, a1, a2) (std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR((Iter *)(a0), (void *)(a1), (Iter *)(a2))) /* merge_units */


#if 0 /* merge_units */
extern void* cSkaParams_GetAnimAnchorList(int* s);
#endif /* merge_units */
void * cSkaParams_GetAnimAnchorList(); /* merge_units */

#if 0 /* merge_units */
extern void cArray_cSkaAnimAnchorListEntry_Begin(SIt_1A08D0* out, void* s);
#endif /* merge_units */
void cArray_cSkaAnimAnchorListEntry_Begin(); /* merge_units */

#if 0 /* merge_units */
extern void cArray_cSkaAnimAnchorListEntry_End(SIt_1A08D0* out, void* s);
#endif /* merge_units */
void cArray_cSkaAnimAnchorListEntry_End(); /* merge_units */

#if 0 /* merge_units */
extern int cArray_cSkaAnimAnchorListEntry_Iterator_opNe(SIt_1A08D0* a, SIt_1A08D0* b);
#endif /* merge_units */
int cArray_cSkaAnimAnchorListEntry_Iterator_opNe(); /* merge_units */

#if 0 /* merge_units */
extern void* cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(SIt_1A08D0* a);
#endif /* merge_units */
int cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(); /* merge_units */

#if 0 /* merge_units */
extern void* cSkaAnimAnchorListEntry_Anchor(void* p);
#endif /* merge_units */
void * cSkaAnimAnchorListEntry_Anchor(); /* merge_units */

#if 0 /* merge_units */
extern void cSkaAnimAnchor_DetachParent(void* p);
#endif /* merge_units */
void cSkaAnimAnchor_DetachParent(); /* merge_units */

#if 0 /* merge_units */
extern void cArray_cSkaAnimAnchorListEntry_Iterator_opInc(SIt_1A08D0* a);
#endif /* merge_units */
Iter16 * cArray_cSkaAnimAnchorListEntry_Iterator_opInc(); /* merge_units */

static inline int Eq_1A08D0(E_1A08D0*** a, E_1A08D0*** b) { return a == b; }
void cSkaSystem_DetachChildrenAnchors_All(O_1A08D0* self)
{
    It_1A08D0 b;
    It_1A08D0 e;
    E_1A08D0*** t0;
    E_1A08D0*** t1;
    SIt_1A08D0 i;
    SIt_1A08D0 ie;
    int* v = &self->vec;
    E_1A08D0*** it;
    E_1A08D0*** end;
    t0 = std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(v);
    std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(&b, v, &t0);
    it = b.p;
    t1 = std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(v);
    std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(&e, v, &t1);
    end = e.p;
    while (Eq_1A08D0(it, end) ^ 1) {
        void* s = cSkaParams_GetAnimAnchorList(&(**it)->set);
        cArray_cSkaAnimAnchorListEntry_Begin(&i, s);
        cArray_cSkaAnimAnchorListEntry_End(&ie, s);
        while (cArray_cSkaAnimAnchorListEntry_Iterator_opNe(&i, &ie)) {
            cSkaAnimAnchor_DetachParent(cSkaAnimAnchorListEntry_Anchor(cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(&i)));
            cArray_cSkaAnimAnchorListEntry_Iterator_opInc(&i);
        }
        it++;
    }
}
#undef std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void /* merge_units */
#undef std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void /* merge_units */
#undef std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR /* merge_units */
static inline void merge_flush_func_001A08D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A08D0 */

/* merge_units: begin func_001A09F0 */
#pragma push /* merge_units */
int cArray_cSkaAnimAnchorListEntry_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Iterator ++ over 384-byte elements. */
Iter16* cArray_cSkaAnimAnchorListEntry_Iterator_opInc(Iter16* it) {
    it->p = it->p + 384;
    return it;
}
static inline void merge_flush_func_001A09F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A09F0 */

/* merge_units: begin func_001A0A30 */
#pragma push /* merge_units */
typedef struct { Q a; Q b; } VP_1A0A30;
typedef struct { Q a; } V4_1A0A30;
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(void* self);
extern VP_1A0A30* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* self);
extern V4_1A0A30* cSkaAnimAnchor_TreeNode_GetDeltaPos_WorldSpace(void* self);
extern VP_1A0A30* cSkaAnimAnchor_TreeNode_GetSkeletonTarget_WorldSpace(void* self);
extern void cQuatVec_ctor_cQuatVecR(VP_1A0A30* d, VP_1A0A30* s);
extern void cVector_ctor_cVectorR(V4_1A0A30* d, V4_1A0A30* s);
extern void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(void* self);
extern void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(void* self, VP_1A0A30* p);
extern void cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(void* self, V4_1A0A30* m);
extern void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(void* self, VP_1A0A30* p);
void cSkaAnimAnchor_DetachParent(void* self)
{
    VP_1A0A30 place;
    V4_1A0A30 motion;
    VP_1A0A30 other;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(self)) {
        cQuatVec_ctor_cQuatVecR(&place, cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(self));
        cVector_ctor_cVectorR(&motion, cSkaAnimAnchor_TreeNode_GetDeltaPos_WorldSpace(self));
        cQuatVec_ctor_cQuatVecR(&other, cSkaAnimAnchor_TreeNode_GetSkeletonTarget_WorldSpace(self));
        cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(self);
        cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(self, &place);
        cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(self, &motion);
        cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(self, &other);
    }
}
static inline void merge_flush_func_001A0A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0A30 */

/* merge_units: begin func_001A0AD0 */
#pragma push /* merge_units */
void* cSkaAnimAnchorListEntry_Anchor(char* self) {
    return self + 16;
}

int cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(char* self) {
    return *(int*)(self + 0);
}

/* end() over 384-byte elements. */
void cArray_cSkaAnimAnchorListEntry_End(Iter16* out, PtrVec* v) {
    int count = v->count;
    char* data = (char*)v->data;

    out->p = data + count * 384;
}

void cArray_cSkaAnimAnchorListEntry_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cSkaParams_GetAnimAnchorList(char* self) {
    return self + 160;
}
static inline void merge_flush_func_001A0AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0AD0 */
