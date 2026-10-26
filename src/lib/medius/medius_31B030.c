/*
 * lib/medius: 4 files, 0031B030-0031B190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031B030 */
extern float Math_Asinf(float x);
void K2ASK(unsigned int n, float *in, float *out)
{
    while (n != 0) {
        *out++ = Math_Asinf(*in++);
        n--;
    }
}
/* merge_units: end func_0031B030 */

/* merge_units: begin func_0031B090 */
#include "types.h"
void NellyKsToAs(float* k, float* a, int n)
{
    float tmp[20];
    float *p, *q, *t;
    int i, j;
    a[0] = 1.0f;
    if (n & 1) { q = a; p = tmp; } else { q = tmp; p = a; }
    for (i = 0; i < n; i++) {
        float ki = k[i];
        t = p; p = q; q = t;
        p[i + 1] = -ki;
        for (j = 1; j <= i; j++) p[j] = q[j] - ki * q[i + 1 - j];
    }
}
/* merge_units: end func_0031B090 */

/* merge_units: begin func_0031B140 */
extern void BitRev(void *a, int n);
extern void Fft(void *a, int n);
extern void Unpack(void *a, int n);
void RealFft(void *a, int bits)
{
    BitRev(a, (1 << bits) >> 1);
    Fft(a, bits - 1);
    Unpack(a, bits);
}
/* merge_units: end func_0031B140 */

/* merge_units: begin func_0031B190 */
extern void InverseUnpack(float* data, int bits);
#if 0 /* merge_units */
extern void BitRev(float* data, int n);
#endif /* merge_units */
#define BitRev(a0, a1) (BitRev((void *)(a0), (a1))) /* merge_units */

extern void InverseFft(float* data, int bits);
void RealInverseFft(float* data, int bits, int flags)
{
    int n = 1 << bits;
    int i;
    float s;
    InverseUnpack(data, bits);
    BitRev(data, n >> 1);
    InverseFft(data, bits - 1);
    if (!(flags & 8)) {
        s = 1.0f / n;
        for (i = 0; i < n; i++) data[i] *= s;
    }
}
#undef BitRev /* merge_units */
/* merge_units: end func_0031B190 */
