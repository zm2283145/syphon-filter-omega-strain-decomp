/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern SkaFlaggedVec* std_vector_pod_int_ctor(SkaFlaggedVec* dst, SkaFlaggedVec* src);
extern SkaFlaggedVec* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_cArrayR(SkaFlaggedVec* dst, SkaFlaggedVec* src);
extern SkaRecordB0* cSkaAnimAnchor_TreeNodeData_ctor_cSkaAnimAnchorTreeNodeDataR(SkaRecordB0* dst, SkaRecordB0* src);

/* Copy-construct: base part, word +0xB0, flagged array +0xB4. */
SkaRecordB0* cSkaAnimAnchor_TreeNode_ctor_cSkaAnimAnchorTreeNodeR(SkaRecordB0* dst, SkaRecordB0* src) {
    cSkaAnimAnchor_TreeNodeData_ctor_cSkaAnimAnchorTreeNodeDataR(dst, src);
    dst->unkB0 = src->unkB0;
    cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_cArrayR(&dst->unkB4, &src->unkB4);
    return dst;
}

/* Copy-construct: copy the array part, then the flag byte. */
SkaFlaggedVec* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_cArrayR(SkaFlaggedVec* dst, SkaFlaggedVec* src) {
    std_vector_pod_int_ctor(dst, src);
    dst->flag = src->flag;
    return dst;
}
