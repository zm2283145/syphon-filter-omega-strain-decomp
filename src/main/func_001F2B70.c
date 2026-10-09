/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DFBB0;
extern MotionNode* MotionNode_BaseCtor(MotionNode*, int, int);
extern void func_001F2BE0(int, ObjVec*);
extern ObjVec* func_001F3070(ObjVec*);

/* Constructor of the type-3 motion node (same layout as MotionSlider up to 0x34). */
MotionSlider* func_001F2B70(MotionSlider* self, int a1, int a2, int a3) {
    MotionNode_BaseCtor(&self->base, 3, a3);
    self->base.vtable = &D_004DFBB0;
    self->unk20 = a1;
    func_001F3070(&self->children);
    func_001F2BE0(a2, &self->children);
    return self;
}
