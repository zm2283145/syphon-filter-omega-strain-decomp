#include "types.h"
extern volatile float D_004E1BDC;
void func_003223B8(int n, float* a) { float scale = 1.0f; float sum = 0.0f; float lim; int i; for (i = 0; i < n; i++) sum += a[i]; lim = D_004E1BDC; if (lim < sum) scale = lim / sum; while (n-- > 0) { *a = *a * scale; a++; } }
