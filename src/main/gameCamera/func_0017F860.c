#include "types.h"
unsigned int D_004A3FD8[2] = { 0x0, 0x0 };
extern float Libc_Atanf(float);
/* Returns 2 * f(1 / (x * scale)). */
float func_0017F860(float x) { return 2.0f * Libc_Atanf(1.0f / (x * (*(float*)D_004A3FD8))); }
