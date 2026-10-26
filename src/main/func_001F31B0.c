/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DFC50;
extern int cQuaternion_ctor_cQuaternionR(int*, int);

void* cAllocator_cSkaSwitchItem_ctor_void(void* self) {
    return self;
}

MotionNode* MotionNode_BaseCtor(MotionNode* self, int type, int name) {
    self->vtable = &D_004DFC50;
    self->type = type;
    cQuaternion_ctor_cQuaternionR(&self->name, name);
    return self;
}
