/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DFBB0;
extern MotionNode* cSkaNode_ctor_eType_cQuaternionR(MotionNode*, int, int);
extern void cSkaInitListOfPointers_cSkaSwitchItem_CopyPointerContentsToArray(int, ObjVec*);
extern ObjVec* cArray_cSkaSwitchItem_ctor_void(ObjVec*);

/* Constructor of the type-3 motion node (same layout as MotionSlider up to 0x34). */
MotionSlider* cSkaSwitch_ctor(MotionSlider* self, int a1, int a2, int a3) {
    cSkaNode_ctor_eType_cQuaternionR(&self->base, 3, a3);
    self->base.vtable = &D_004DFBB0;
    self->unk20 = a1;
    cArray_cSkaSwitchItem_ctor_void(&self->children);
    cSkaInitListOfPointers_cSkaSwitchItem_CopyPointerContentsToArray(a2, &self->children);
    return self;
}
