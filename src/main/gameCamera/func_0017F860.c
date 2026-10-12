#include "types.h"
unsigned int D_004A3FD8[2] = { 0x0, 0x0 };
extern float Math_Atan(float);
/* Returns 2 * f(1 / (x * scale)). */
float func_0017F860(float x) { return 2.0f * Math_Atan(1.0f / (x * (*(float*)D_004A3FD8))); }
