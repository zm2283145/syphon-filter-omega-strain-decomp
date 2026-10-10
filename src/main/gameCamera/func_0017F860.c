#include "types.h"
extern float D_004A3FD8;
extern float func_001212E0(float);
/* Returns 2 * f(1 / (x * scale)). */
float func_0017F860(float x) { return 2.0f * func_001212E0(1.0f / (x * D_004A3FD8)); }
