#include "types.h"
typedef struct E4Rid {
    char pad00[0x50];
    char orientation[0x50];
    unsigned char dirty;
} E4Rid;
typedef struct { Q a; Q b; } E4Pair;
extern E4Rid* Root_IdentityAccessor(void* root);
extern void* VecCurve_GetPrevious(void* o);
extern void Vec4_Copy(void* dst, void* src);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(void* root);
extern void cQuatVec_ctor_void(E4Pair* m);
extern void* Root_GetParentInverse(void* root, E4Pair* m);
extern void Placement_TransformPointConj(void* p, void* m);
extern void Root_PropagateChildren(void* root);
void Root_PublishPosition(void* root, void* pos)
{
    int one;
    Vec4_Copy(VecCurve_GetPrevious(Root_IdentityAccessor(root)->orientation), pos);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(root)) {
        E4Pair m;
        void* p;
        cQuatVec_ctor_void(&m);
        p = VecCurve_GetPrevious(Root_IdentityAccessor(root)->orientation);
        Placement_TransformPointConj(p, Root_GetParentInverse(root, &m));
    }
    one = 1;
    Root_IdentityAccessor(root)->dirty = one;
    Root_PropagateChildren(root);
}