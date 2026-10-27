/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DFBF0;
extern MotionNode* cSkaNode_ctor_cSkaNodeR_cQuaternionR(MotionNode*, MotionNode*);
extern ObjVec* cArray_cSkaBlendSequenceItem_ctor_cArrayR(ObjVec*, ObjVec*);
extern int cQuaternion_opAssign(int*, int*);
extern int std_vector_cSkaBlendSequenceItem_ctor_vectorR(ObjVec*);

/* Copy of the MotionNode base part (type byte and name). */
MotionNode* cSkaNode_opAssign(MotionNode* dst, MotionNode* src) {
    dst->type = src->type;
    cQuaternion_opAssign(&dst->name, &src->name);
    return dst;
}

/* MotionSlider copy constructor. */
MotionSlider* cSkaSlider_ctor_cSkaSliderR_cQuaternionR(MotionSlider* dst, MotionSlider* src) {
    cSkaNode_ctor_cSkaNodeR_cQuaternionR(&dst->base, &src->base);
    dst->base.vtable = &D_004DFBF0;
    dst->unk20 = src->unk20;
    cArray_cSkaBlendSequenceItem_ctor_cArrayR(&dst->children, &src->children);
    dst->unk34 = src->unk34;
    dst->unk35 = src->unk35;
    return dst;
}

ObjVec* cArray_cSkaBlendSequenceItem_ctor_cArrayR(ObjVec* dst, ObjVec* src) {
    std_vector_cSkaBlendSequenceItem_ctor_vectorR(dst);
    dst->owned = src->owned;
    return dst;
}
