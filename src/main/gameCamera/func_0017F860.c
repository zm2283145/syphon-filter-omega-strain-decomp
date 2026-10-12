#include "types.h"
extern float D_004A3FD8;
extern float Math_Atan(float);
/* Returns 2 * f(1 / (x * scale)). */
float func_0017F860(float x) { return 2.0f * Math_Atan(1.0f / (x * D_004A3FD8)); }
