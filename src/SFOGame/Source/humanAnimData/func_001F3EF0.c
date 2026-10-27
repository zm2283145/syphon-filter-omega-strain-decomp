/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DFBF0;
extern MotionNode* cSkaNode_ctor_eType_cQuaternionR(MotionNode*, int, int);
extern ObjVec* cArray_cSkaBlendSequenceItem_ctor_void(ObjVec*);
extern void cSkaInitListOfPointers_cSkaBlendSequenceItem_CopyPointerContentsToArray(int, ObjVec*);

MotionSlider* cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(MotionSlider* self, int a1, int a2, int a3, int t0, int t1) {
    cSkaNode_ctor_eType_cQuaternionR(&self->base, 2, t1);
    self->base.vtable = &D_004DFBF0;
    self->unk20 = a1;
    cArray_cSkaBlendSequenceItem_ctor_void(&self->children);
    self->unk34 = a3;
    self->unk35 = t0;
    cSkaInitListOfPointers_cSkaBlendSequenceItem_CopyPointerContentsToArray(a2, &self->children);
    return self;
}
