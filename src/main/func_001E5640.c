#include "types.h"
extern int Root_GetParent(void* r);
extern void cSkaAnimAnchor_TreeNode_UpdateDeltaPos(void* r);
extern char* Root_Identity(void* r);
char* cSkaAnimAnchor_GetDeltaPos(void* r)
{
    if (Root_GetParent(r)) {
        cSkaAnimAnchor_TreeNode_UpdateDeltaPos(r);
        return Root_Identity(r) + 0x20;
    }
    return Root_Identity(r) + 0x70;
}