/*
 * lib/medius: 4 files, 0031BC70-0031BE68
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031BC70 */
extern float D_004E1BEC;
extern float D_004E1BF0;
extern volatile float D_004E1BF4;
float MidFramePv(float* prev, float a, float b, float cur, float d)
{
    float r;
    float lo = D_004E1BEC;
    if (*prev < lo) *prev = lo;
    if (cur < lo) cur = lo;
    if (__builtin_fabsf(b - a) < D_004E1BF0) {
        r = (b + a) * 0.5f;
    } else if (d < D_004E1BF4) {
        if (a < b) r = a * d / *prev;
        else r = b * d / cur;
    } else {
        if (a < b) r = b * d / cur;
        else r = a * d / *prev;
    }
    if (r < 0.0f) r = 0.0f;
    if (1.0f < r) r = 1.0f;
    *prev = cur;
    return r;
}
/* merge_units: end func_0031BC70 */

/* merge_units: begin func_0031BD50 */
#include "types.h"

extern float HammingWindowNormSC(int, int);
extern int GetFrameSpCBM(int, int, int, int);
extern int NellyAdaptiveWindow(float);

float GetWindowedSpeech(int a0, int a1, int a2, int a3, float f12) {
    int tmp0;
    int tmp4;

    tmp0 = NellyAdaptiveWindow(f12);
    *(int*)((char*)a2) = tmp0;
    GetFrameSpCBM(a0, a3, tmp0, a1);
    tmp4 = *(int*)(char*)a2;
    return HammingWindowNormSC(a1, tmp4);
}
/* merge_units: end func_0031BD50 */

/* merge_units: begin func_0031BDB8 */
extern float D_004E1BE0;
float MidEstPitch(float a, float b, float c, float d)
{
    float r, hi;
    if (b <= a * 1.25f && a * D_004E1BE0 <= b) {
        r = (a + b) * 0.5f;
    } else {
        if (d < c) { hi = c; r = a; }
        else { hi = d; r = b; }
        if (r < 30.0f && hi * r * 0.5f < 1.0f) {
            r = b;
            if (!(a < b)) r = a;
        }
    }
    return r;
}
/* merge_units: end func_0031BDB8 */

/* merge_units: begin func_0031BE68 */
/* sqrtf is expanded inline by gcc (sqrt.s + NaN fallback call); alias the libcall to the retail sqrtf. */
__asm__("sqrtf = Libc_Sqrtf");
float sqrtf(float);
float DotProd(float* a, float* b, int n);
float QuadraticPeak(float a, float b, float c, float* out);
extern float D_004E1D2C[];
extern float D_004E1BB4;

float TDPitchRefine(float rate, float scale, float* buf, int n, float* out) {
    float vals[3];
    float best;
    float v;
    float res;
    int w;
    int lo;
    int hi;
    int i;
    int j;
    int bi;
    int pk;
    int m;
    float e;
    float t;

    vals[0] = vals[1] = vals[2] = 0.0f;
    t = scale * rate;
    w = (int)(t + 0.5f);
    if (w > 4) {
        w = 4;
    }
    t = rate - (float)w;
    lo = (int)(t + 0.5f);
    t = rate + (float)w;
    hi = (int)(t + 0.5f);
    if (lo < 8) {
        lo = 8;
    }
    if (hi > 0xA0) {
        hi = 0xA0;
    }
    best = D_004E1D2C[0];
    bi = 0;
    j = 0;
    i = lo;
    do {
        v = DotProd(buf, &buf[i], n - i);
        i++;
        if (v > best) {
            bi = j;
            best = v;
            vals[0] = vals[1];
        } else if (bi == j - 1) {
            vals[2] = v;
        }
        vals[1] = v;
        j++;
    } while (i <= hi);
    pk = bi + lo;
    if (lo < pk && pk < hi) {
        res = (float)pk + QuadraticPeak(vals[0], best, vals[2], out);
    } else {
        res = (float)pk;
        *out = best;
    }
    m = n - pk;
    e = DotProd(buf, buf, m);
    e = e * DotProd(&buf[pk], &buf[pk], m);
    *out = *out / sqrtf(e + D_004E1BB4);
    return res;
}
/* merge_units: end func_0031BE68 */
