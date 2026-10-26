#include "types.h"
typedef struct { char data[0x18]; } Sub002C3280;
typedef struct { int unk0; float f[5]; Sub002C3280 sub; char sub30[8]; unsigned char flag; } Obj002C3280;
extern void cHermiteSplineWithScaledDuration_float_opAssign(Sub002C3280* dst, Sub002C3280* src);
extern float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(void* src);
extern void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(void* dst, Sub002C3280* sub, float value);
/* Copy-assign. */
Obj002C3280* cSplinedMotion_Scalar0To1_opAssign(Obj002C3280* dst, Obj002C3280* src)
{
    dst->f[0] = src->f[0];
    dst->f[1] = src->f[1];
    dst->f[2] = src->f[2];
    dst->f[3] = src->f[3];
    dst->f[4] = src->f[4];
    cHermiteSplineWithScaledDuration_float_opAssign(&dst->sub, &src->sub);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(dst->sub30, &dst->sub, cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(src->sub30));
    dst->flag = src->flag;
    return dst;
}
