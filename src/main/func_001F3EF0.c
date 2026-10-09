/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DFBF0;
extern MotionNode* MotionNode_BaseCtor(MotionNode*, int, int);
extern ObjVec* func_001F3B20(ObjVec*);
extern void func_001F3F80(int, ObjVec*);

MotionSlider* MotionSlider_Ctor(MotionSlider* self, int a1, int a2, int a3, int t0, int t1) {
    MotionNode_BaseCtor(&self->base, 2, t1);
    self->base.vtable = &D_004DFBF0;
    self->unk20 = a1;
    func_001F3B20(&self->children);
    self->unk34 = a3;
    self->unk35 = t0;
    func_001F3F80(a2, &self->children);
    return self;
}
