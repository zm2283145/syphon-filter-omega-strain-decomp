/*
 * SFOGame/Source/human: 1 file, 001A6DF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A6DF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" {
#include "root_mark_dirty_tree.h"
}
struct It { int* p; };
struct Vec { int pad; int count; int* data; };
struct RNode {
    char pad[0xA0];
    unsigned char dirty0;
    unsigned char dirty1;
    unsigned char dirty2;
    char padA3[0x11];
    Vec kids;               /* 0xB4 */
};
extern "C" {
RNode** std_vector_pod_int_begin(Vec* v);
RNode** std_vector_pod_int_end(Vec* v);
unsigned char std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_empty(Vec* v);
It* std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_begin(It* out, Vec* v);
It* std_wrap_iterator_vector_cTreeNodePtr_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtrPtr_ctor(It* d, It* s);
It* std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_end(It* out, Vec* v);
unsigned char std_opEq_wrapiteratorR_wrapiteratorR(It* a, It* b);
RNode** std_wrap_iterator_vector_cTreeNodePtr_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtrPtr_opMul(It* it);
}
static inline bool NotEmpty(Vec* v) { return !(v->count == 0); }
static inline bool NotEmpty2(Vec* v) { return !(std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_empty(v) != 0); }
static inline bool NotEnd(It* a, It* b) { return !(std_opEq_wrapiteratorR_wrapiteratorR(a, b) != 0); }
static inline bool Neq(RNode** a, RNode** b) { return !(a == b); }
/* Marks each child (and each grandchild's subtree) dirty. */
extern "C" void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(RNode* self)
{
    if (NotEmpty(&self->kids)) {
        RNode* n;
        RNode** end;
        RNode** it;
        it = std_vector_pod_int_begin(&self->kids);
        end = std_vector_pod_int_end(&self->kids);
        for (; Neq(it, end); it++) {
            n = *it;
            n->dirty0 = 1;
            n->dirty1 = 1;
            n->dirty2 = 1;
            if (NotEmpty2(&n->kids)) {
                It cur;
                It last;
                It t0;
                It t1;
                std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_begin(&t0, &n->kids);
                std_wrap_iterator_vector_cTreeNodePtr_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtrPtr_ctor(&cur, &t0);
                std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_end(&t1, &n->kids);
                std_wrap_iterator_vector_cTreeNodePtr_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtrPtr_ctor(&last, &t1);
                for (; NotEnd(&cur, &last); cur.p++) {
                    RootDirtyNode* c = (RootDirtyNode*)*std_wrap_iterator_vector_cTreeNodePtr_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtrPtr_opMul(&cur);
                    RootDirtyIt ci;
                    RootDirtyIt ce;
                    c->dirty0 = 1;
                    c->dirty1 = 1;
                    c->dirty2 = 1;
                    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(c)) {
                        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(&ci, cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(c));
                        cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(&ce, cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(c));
                        for (; cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(&ci, &ce); cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(&ci))
                            cSkaAnimAnchor_TreeNode_TellNeedToUpdate(*cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(&ci));
                    }
                }
            }
        }
    }
}
static inline void merge_flush_func_001A6DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A6DF0 */
