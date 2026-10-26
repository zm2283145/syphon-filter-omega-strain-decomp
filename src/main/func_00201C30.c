/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DFBF0;
extern MotionNode* MotionNode_BaseCopy(MotionNode*, MotionNode*);
extern ObjVec* MotionSlider_CopyChildren(ObjVec*, ObjVec*);
extern int Quat_Assign(int*, int*);
extern int std_vector_cSkaBlendSequenceItem_ctor_vectorR(ObjVec*);

/* Copy of the MotionNode base part (type byte and name). */
MotionNode* cSkaNode_opAssign(MotionNode* dst, MotionNode* src) {
    dst->type = src->type;
    Quat_Assign(&dst->name, &src->name);
    return dst;
}

/* MotionSlider copy constructor. */
MotionSlider* MotionSlider_Copy(MotionSlider* dst, MotionSlider* src) {
    MotionNode_BaseCopy(&dst->base, &src->base);
    dst->base.vtable = &D_004DFBF0;
    dst->unk20 = src->unk20;
    MotionSlider_CopyChildren(&dst->children, &src->children);
    dst->unk34 = src->unk34;
    dst->unk35 = src->unk35;
    return dst;
}

ObjVec* MotionSlider_CopyChildren(ObjVec* dst, ObjVec* src) {
    std_vector_cSkaBlendSequenceItem_ctor_vectorR(dst);
    dst->owned = src->owned;
    return dst;
}
