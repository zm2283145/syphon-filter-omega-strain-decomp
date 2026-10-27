#include "types.h"

typedef struct Obj39 {
    int unk0;
    float f[5];
    char sub18[0x18];
    char sub30[8];
    unsigned char flag;
} Obj39;

extern void cHermiteSplineWithScaledDuration_float_opAssign(void*, void*);
extern float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(void*);
extern void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(void*, void*, float);

/* Assignment: copies five floats, the sub-object at +0x18, derived data at +0x30 and the flag. */
Obj39* func_002A5E40(Obj39* self, Obj39* other) {
    self->f[0] = other->f[0];
    self->f[1] = other->f[1];
    self->f[2] = other->f[2];
    self->f[3] = other->f[3];
    self->f[4] = other->f[4];
    cHermiteSplineWithScaledDuration_float_opAssign(self->sub18, other->sub18);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(self->sub30, self->sub18, cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(other->sub30));
    self->flag = other->flag;
    return self;
}
