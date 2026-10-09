/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DFC50;
extern int func_00132800(int*, int);

void* func_001F31B0(void* self) {
    return self;
}

MotionNode* MotionNode_BaseCtor(MotionNode* self, int type, int name) {
    self->vtable = &D_004DFC50;
    self->type = type;
    func_00132800(&self->name, name);
    return self;
}
