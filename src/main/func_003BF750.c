#include "types.h"
extern void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2(void* q, float a, float b, float c, float d, float e, float f, float g);
/* Calls cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2 with the last two parameters zeroed. */
void ColQuery_InitTransformedThunk(void* q, float a, float b, float c, float d, float e)
{
    cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2(q, a, b, c, d, e, 0.0f, 0.0f);
}
