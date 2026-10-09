/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern int Curve_Bind(void* binding, CurveSegment* segment);
extern int Curve_InitConstant(CurveSegment*, int, int, float);
extern float D_0048A1B8;    /* 0.0f */
extern float D_0048A1C0;
extern char D_004DA380[];   /* CurveChannel base vtable */
extern char D_004DA7D0[];   /* AngleCurve vtable */

Rel* func_001B7A20(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Scalar angle curve constructor (actor member +0x3050). */
CurveChannel* AngleCurve_Construct(CurveChannel* self) {
    self->vtable = D_004DA380;
    self->previous = D_0048A1B8;
    self->current = D_0048A1B8;
    self->target = D_0048A1C0;
    self->rate = D_0048A1B8;
    self->damping = 0.0f;
    Curve_InitConstant(&self->segment, (int)&D_0048A1B8, (int)&D_0048A1C0, 0.0f);
    Curve_Bind(self->binding, &self->segment);
    self->vtable = D_004DA7D0;
    return self;
}

Rel* func_001B7AE0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
