/*
 * lib/medius: 2 files, 0031A960-0031A9A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031A960 */
#include "types.h"
void BandExpand(float* in, float* out, int n, float x)
{
    float f = 1.0f;
    int i;
    for (i = 0; i <= n; i++) {
        *out++ = *in++ * f;
        f *= x;
    }
}
/* merge_units: end func_0031A960 */

/* merge_units: begin func_0031A9A0 */
extern const float D_004E1BB8;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void NellySquareLawPeaks(float *x, float *y, int n, float *o1, float *o2, int *cnt, int max)
{
    int i, j, k, m;

    k = 0;
    m = MIN(max, n);
    for (i = 0; i < m; i++) {
        o1[k] = x[i];
        o2[k] = y[i];
        k++;
    }
    m = MIN(max - k, n - 1);
    for (i = 0; i < m; i++) {
        o1[k] = x[i + 1] * x[i];
        o2[k] = y[i + 1] - y[i];
        k++;
    }
    m = MIN(max - k, n - 2);
    for (i = 0; i < m; i++) {
        o1[k] = x[i + 2] * x[i];
        o2[k] = y[i + 2] - y[i];
        k++;
    }
    *cnt = k;
    if (k >= 10) {
        j = 0;
        for (i = 0; i < k; i++) {
            if (D_004E1BB8 < o1[i]) {
                o1[j] = o1[i];
                o2[j] = o2[i];
                j++;
            }
        }
        *cnt = j;
    }
}
/* merge_units: end func_0031A9A0 */
