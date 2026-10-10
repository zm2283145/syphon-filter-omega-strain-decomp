#include "types.h"

extern float Math_Atan2f(float y, float x);

/* Heading angle of a 2D vector: atan2(-v[0], v[1]). */
float func_0019D170(float* v)
{
    return Math_Atan2f(-v[0], v[1]);
}
