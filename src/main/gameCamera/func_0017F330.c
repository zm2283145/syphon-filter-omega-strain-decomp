#include "types.h"

typedef struct { char b[0x18]; } Curve;
typedef struct { char b[0x10]; } CurveBinding;
typedef struct {
    void* vtable;
    float min;
    float cur;
    float max;
    float def;
    int unk14;
    Curve curve;
    CurveBinding binding;
} Obj17F;
extern char D_004DA380[];
extern char D_004DA3E0[];
extern float D_0048A158;
extern float D_0048A160;
extern void Curve_InitConstant(Curve* c, float* lo, float* hi, float value);
extern void Curve_Bind(CurveBinding* b, Curve* c);

/* Constructor: default range values, a constant curve and its binding. */
Obj17F* func_0017F330(Obj17F* self)
{
    self->vtable = D_004DA380;
    self->min = D_0048A158;
    self->cur = D_0048A158;
    self->max = D_0048A160;
    self->def = D_0048A158;
    self->unk14 = 0;
    Curve_InitConstant(&self->curve, &D_0048A158, &D_0048A160, 0.0f);
    Curve_Bind(&self->binding, &self->curve);
    self->vtable = D_004DA3E0;
    return self;
}
