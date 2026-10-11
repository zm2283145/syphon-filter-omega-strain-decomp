#include "types.h"
extern float D_004E1BC4, D_004E1BC8, D_004E1BCC;
void func_00322030(float* s, float* out, int n, float x) { float a = s[0] + (x + s[2]) * D_004E1BC4 * (float)n; float b = a * D_004E1BC8; int k; if (b > 0.0f) k = (int)(b + 0.5f); else k = (int)(b - 0.5f); a = a - (float)k * D_004E1BCC; *out = a; s[0] = a; s[2] = x; }
