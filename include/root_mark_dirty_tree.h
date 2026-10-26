#ifndef ROOT_MARK_DIRTY_TREE_H
#define ROOT_MARK_DIRTY_TREE_H

/*
 * Root: set the three dirty flags at 0xA0..0xA2, then, when the node has
 * children, walk the child list (out-of-line iterator helpers) and mark
 * each child through cSkaAnimAnchor_TreeNode_TellNeedToUpdate. Plain C.
 */
typedef struct RootDirtyIt { void* node; } RootDirtyIt;
typedef struct RootDirtyNode {
    char pad[0xA0];
    unsigned char dirty0;
    unsigned char dirty1;
    unsigned char dirty2;
} RootDirtyNode;

extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(RootDirtyNode* self);
extern void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(RootDirtyNode* self);
extern RootDirtyIt* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(RootDirtyIt* it, void* list);
extern RootDirtyIt* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(RootDirtyIt* it, void* list);
extern int cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(RootDirtyIt* a, RootDirtyIt* b);
extern RootDirtyNode** cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(RootDirtyIt* it);
extern RootDirtyIt* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(RootDirtyIt* it);
extern void cSkaAnimAnchor_TreeNode_TellNeedToUpdate(RootDirtyNode* self);

#define DEFINE_ROOT_MARK_DIRTY_TREE(name)                                \
    void name(RootDirtyNode* self)                                       \
    {                                                                    \
        RootDirtyIt it;                                                  \
        RootDirtyIt end;                                                 \
        self->dirty0 = 1;                                                \
        self->dirty1 = 1;                                                \
        self->dirty2 = 1;                                                \
        if (cTreeNode_cSkaAnimAnchor_TreeNodeData_HasChildren(self)) {                                       \
            cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Begin(&it, cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(self));                     \
            cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_End(&end, cTreeNode_cSkaAnimAnchor_TreeNodeData_Children(self));                    \
            for (; cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(&it, &end); cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(&it))         \
                cSkaAnimAnchor_TreeNode_TellNeedToUpdate(*cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opMul(&it));                      \
        }                                                                \
    }

#endif /* ROOT_MARK_DIRTY_TREE_H */