#include "types.h"
extern float Math_Atan2f(float y, float x);
float Vec_HeadingFromYX(float* v) {
    return Math_Atan2f(v[1], v[0]);
}
