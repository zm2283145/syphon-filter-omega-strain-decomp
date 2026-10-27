#include "types.h"
extern void cSkaAnimAnchor_TreeNode_AttachParent(void* child, void* parent);
extern void cSkaAnimAnchor_ClearLocalTransform(void* child);
void cSkaAnimAnchor_AttachChild(void* parent, void* child, int reset) {
    cSkaAnimAnchor_TreeNode_AttachParent(child, parent);
    if (reset) {
        cSkaAnimAnchor_ClearLocalTransform(child);
    }
}