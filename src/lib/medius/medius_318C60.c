/*
 * lib/medius: 3 files, 00318C60-00318FC8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00318C60 */
#include "types.h"
extern float D_004E1C54;
extern float D_004E1CA4;
extern float D_004E1CA8;
extern float D_004E1CAC;
extern void PeakPick(float* a, int start, int end, int max, int* out, int* count);
extern float Libc_Ceilf(float x);
extern void CalcRSbyPower(float* a, int n, float* r, int k);
extern void NellyDurbin(float* r, int k, float* c, float* e, float* g);
extern void BandExpand(float* in, float* out, int n, float x);
extern void CalcMaskEnvelope(float* c, int k, float* s, int n);

void SelectPeaks(float* a, int n, int* out, int* count, float thr)
{
    float c[8];
    float r[8];
    float e[8];
    float s[0x58];
    float g;
    int k;
    int i, j;
    int* o;

    PeakPick(a, 0, 0x57, 0x2B, out, count);
    k = (int)Libc_Ceilf(n * 5.0f / 86.0f);
    if (k >= 8) k = 7;
    CalcRSbyPower(a, n, r, k);
    r[0] *= D_004E1CA4;
    NellyDurbin(r, k, c, e, &g);
    BandExpand(c, c, k, D_004E1CA8);
    CalcMaskEnvelope(c, k, s, n);
    g *= D_004E1C54;
    thr *= D_004E1CAC;
    j = 0;
    for (i = 0; i < *count; i++) {
        int idx = out[i];
        if (idx < n) {
            float v = a[idx];
            if (g <= v * s[idx] && thr < v) {
                out[j] = idx;
                j++;
            }
        }
    }
    out[j + 0] = 0x7FFF;
    out[j + 1] = 0x7FFF;
    out[j + 2] = 0x7FFF;
    out[j + 3] = 0x7FFF;
    *count = j;
}
/* merge_units: end func_00318C60 */

/* merge_units: begin func_00318E48 */
extern void *(*D_004E1D3C)(void *d, int c, int n);
extern int func_00323250(void);
extern void nvuInverseRealFft(float *re, float *im, int n);
extern void inverseRealFft(float *re, float *im, int n);

void CalcRSbyPower(float *in, int f, float *out, int n)
{
    float re[65], im[65];
    float x;
    int step, i, m;
    float *p, *q;
    x = f * 0.015625f * 32768.0f;
    if (x > 0) step = (int)(x + 0.5f); else step = (int)(x - 0.5f);
    re[0] = 0;
    p = re + 1;
    for (i = 1; i < 64; i++) *p++ = in[(i * step + 0x4000) >> 15];
    *p = 0;
    D_004E1D3C(im, 0, sizeof(im));
    if (func_00323250()) nvuInverseRealFft(re, im, 128);
    else inverseRealFft(re, im, 128);
    m = (n + 1) >> 1;
    p = re; q = im;
    for (i = 0; i < m; i++) { *out++ = *p++ * 0.0078125f; *out++ = *q++ * 0.0078125f; }
    if (m * 2 != n + 1) *out = *p * 0.0078125f;
}
/* merge_units: end func_00318E48 */

/* merge_units: begin func_00318FC8 */
extern void nvuRealFft(float *re, float *im, int n);
extern void realFft(float *re, float *im, int n);

void CalcMaskEnvelope(float *in, int n, float *out, int m)
{
    float re[0x41];
    float im[0x41];
    float *pr = re;
    float *pi = im;
    int half;
    int i;
    float f; float a, b;
    int step;
    int pos;
    int k;

    n++;
    half = n >> 1;
    for (i = 0; i < half; i++) {
        *pr++ = in[2 * i];
        *pi++ = in[2 * i + 1];
    }
    if (half * 2 != n) {
        *pr++ = in[2 * i];
        *pi++ = 0.0f;
        i++;
    }
    D_004E1D3C(pr, 0, (0x41 - i) * 4);
    D_004E1D3C(pi, 0, (0x41 - i) * 4);
    if (func_00323250())
        nvuRealFft(re, im, 0x80);
    else
        realFft(re, im, 0x80);
    f = 64.0f / (float)m * 32768.0f;
    if (f > 0.0f)
        step = (int)(f + 0.5f);
    else
        step = (int)(f - 0.5f);
    for (i = 0; i < m - 1; i++) {
        k = (step * i + 0x4000) >> 15;
        { a = re[k]; b = im[k]; out[i] = a * a + b * b; }
    }
    k = (step * i + 0x4000) >> 15;
    if (k >= 0x40)
        out[i] = out[i - 1];
    else
        { a = re[k]; b = im[k]; out[i] = a * a + b * b; }
}
/* merge_units: end func_00318FC8 */
