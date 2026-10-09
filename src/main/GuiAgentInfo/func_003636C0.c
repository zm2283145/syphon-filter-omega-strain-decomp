/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiAgentInfo_types.h"

extern int Curve_Bind(void* binding, CurveSegment* segment);
extern int Curve_InitConstant(CurveSegment* segment, int from, int to, float t);
extern float D_00492EE8;    /* 0.0f */
extern float D_00492EF0;
extern char D_004DA380[];   /* CurveChannel base vtable */
extern char D_004DA840[];   /* AnimChannel vtable */

/* AnimChannel constructor (inline copy emitted in this unit). */
AnimChannel* AnimChannel_Ctor(AnimChannel* self) {
    self->base.vtable = D_004DA380;
    self->base.previous = D_00492EE8;
    self->base.current = D_00492EE8;
    self->base.target = D_00492EF0;
    self->base.rate = D_00492EE8;
    self->base.damping = 0.0f;
    Curve_InitConstant(&self->base.segment, (int)&D_00492EE8, (int)&D_00492EF0, 0.0f);
    Curve_Bind(self->base.binding, &self->base.segment);
    self->base.vtable = D_004DA840;
    self->wrap = 0;
    return self;
}
