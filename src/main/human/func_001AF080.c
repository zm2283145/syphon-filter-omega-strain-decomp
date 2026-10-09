/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern int Curve_Bind(void* binding, CurveSegment* segment);
extern int Curve_InitConstant(CurveSegment*, int, int, float);
extern float D_0048A198;    /* 0.0f */
extern float D_0048A1A0;
extern char D_004DA380[];   /* CurveChannel base vtable */
extern char D_004DA840[];   /* AnimChannel vtable */
extern void func_001BB100(int*, int, int);

/* AnimChannel constructor: zero scalars, constant segment, wrapping off. */
AnimChannel* AnimChannel_Construct(AnimChannel* self) {
    self->base.vtable = D_004DA380;
    self->base.previous = D_0048A198;
    self->base.current = D_0048A198;
    self->base.target = D_0048A1A0;
    self->base.rate = D_0048A198;
    self->base.damping = 0.0f;
    Curve_InitConstant(&self->base.segment, (int)&D_0048A198, (int)&D_0048A1A0, 0.0f);
    Curve_Bind(self->base.binding, &self->base.segment);
    self->base.vtable = D_004DA840;
    self->wrap = 0;
    return self;
}

int func_001AF120(int* self) {
    return *self + 24;
}

int func_001AF130(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_001AF150(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Tree lookup wrapper returning the found iterator through out. */
void func_001AF160(int* out) {
    int it[1];
    int a1, a2;

    func_001BB100(it, a1, a2);
    *out = it[0];
}
