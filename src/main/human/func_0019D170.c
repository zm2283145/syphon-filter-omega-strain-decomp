#include "types.h"

extern float Libc_Atan2f(float y, float x);

/* Heading angle of a 2D vector: atan2(-v[0], v[1]). */
float nSFOMath_GetZRotationFromYAxis(float* v)
{
    return Libc_Atan2f(-v[0], v[1]);
}
