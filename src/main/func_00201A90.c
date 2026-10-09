/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern ObjVec* func_00201AF0(ObjVec*, ObjVec*);
extern int func_00201B30(ObjVec*);
extern MotionNode* func_00201C30(MotionNode*, MotionNode*);

/* Copy of a MotionSlider-layout node (vtable left to the caller). */
MotionSlider* func_00201A90(MotionSlider* dst, MotionSlider* src) {
    func_00201C30(&dst->base, &src->base);
    dst->unk20 = src->unk20;
    func_00201AF0(&dst->children, &src->children);
    dst->unk34 = src->unk34;
    dst->unk35 = src->unk35;
    return dst;
}

ObjVec* func_00201AF0(ObjVec* dst, ObjVec* src) {
    func_00201B30(dst);
    dst->owned = src->owned;
    return dst;
}
