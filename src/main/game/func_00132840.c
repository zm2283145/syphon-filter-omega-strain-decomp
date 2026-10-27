/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cQuaternion_ctor_void(void* self) {
    return self;
}

int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(char* self) {
    return *(int*)(self + 176);
}
