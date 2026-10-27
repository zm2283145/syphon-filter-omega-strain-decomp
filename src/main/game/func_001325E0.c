/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Vec4* cVector_opAssign(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}

Vec4* cQuaternion_opAssign(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}

void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* self) {
    return self;
}
