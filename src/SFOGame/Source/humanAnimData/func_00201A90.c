/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern ObjVec* cArray_cSkaBlendSequenceItem_opAssign(ObjVec*, ObjVec*);
extern int std_vector_cSkaBlendSequenceItem_opAssign(ObjVec*);
extern MotionNode* cSkaNode_opAssign(MotionNode*, MotionNode*);

/* Copy of a MotionSlider-layout node (vtable left to the caller). */
MotionSlider* cSkaSlider_opAssign(MotionSlider* dst, MotionSlider* src) {
    cSkaNode_opAssign(&dst->base, &src->base);
    dst->unk20 = src->unk20;
    cArray_cSkaBlendSequenceItem_opAssign(&dst->children, &src->children);
    dst->unk34 = src->unk34;
    dst->unk35 = src->unk35;
    return dst;
}

ObjVec* cArray_cSkaBlendSequenceItem_opAssign(ObjVec* dst, ObjVec* src) {
    std_vector_cSkaBlendSequenceItem_opAssign(dst);
    dst->owned = src->owned;
    return dst;
}
