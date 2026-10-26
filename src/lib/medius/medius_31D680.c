/*
 * lib/medius: 3 files, 0031D680-0031DA90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031D680 */
/* NellySTCVoicing: gcc296 (ee-gcc2.96 -O2). The float argument of ScaleVector/ScaleAndCompress/NellyRefineC0 is
   declared in the position matching retail's argument-load order (EABI-equivalent: floats go in \ regardless). */
extern int func_00323250(void);
extern void FindMaxValueFlt(float *a, int n, int *outIdx, float *outVal);
extern void ScaleVector(float *src, int n, float s, float *dst);
extern void ScaleAndCompress(float *in, int n, float scale, float *out);
extern void NellySquareLawPeaks(float *x, float *y, int n, float *o1, float *o2, int *cnt, int max, float f);
extern void NellyRefineC0(float f, float *a, float *b, int n, float *r0, float *r1, float *r2);
extern float ComputePv(float lo, float hi, float p);

void NellySTCVoicing(float *pa, float *pb, float *pc, float *pd, float *x, float *y, int n, int max)
{
    float buf0[256];
    float buf1[100];
    float buf2[100];
    int idx;
    float m1;
    float m2;
    int k;
    float r0;
    float r1;
    float r2;
    float c;
    float inv;
    float lim;
    float t;
    float r;
    float scale;
    int i;
    int j;
    int cnt;
    int top;
    int q;

    c = *pc;
    lim = c * 0x1.58p-3f;
    inv = 512.0f / c;
    if (lim >= 0.0f) i = (int)lim;
    else i = (int)(lim - 1.0f);
    if (i < 5) i = 5;
    t = ((float)i + 0.125f) * inv;
    if (t > 160.0f) t = 160.0f;
    top = (int)(t + 0.5f);
    top++;
    for (idx = 0; idx < n; idx++) if (t < y[idx]) break;
    cnt = idx;
    if (cnt > 0) {
        FindMaxValueFlt(x, cnt, &idx, &m1);
        FindMaxValueFlt(pb, top, &idx, &m2);
        m1 = (m2 < m1) ? m1 : m2;
        if (m1 == 0.0f) scale = 1.0f;
        else scale = 1.0f / m1;
        if (func_00323250()) ScaleVector(x, cnt, scale, x);
        else ScaleAndCompress(x, cnt, scale, x);
        if (func_00323250()) ScaleVector(pb, top, scale, buf0);
        else ScaleAndCompress(pb, top, scale, buf0);
        for (q = 0; q < cnt; q++) {
            m2 = y[q];
            j = (int)(m2 + 0.5f);
            if (x[q] < buf0[j]) {
                m2 = x[q] / buf0[j];
                m2 = m2 * m2;
                x[q] = x[q] * (m2 * m2);
            }
        }
        NellySquareLawPeaks(x, y, cnt, buf1, buf2, &k, max, 0x1.b3333p+5f);
        NellyRefineC0(c, buf1, buf2, k, &r0, &r1, &r2);
    } else {
        r1 = c;
        r2 = 0.0f;
    }
    r = ComputePv(*pa * -0.5f + 4.5f, 13.0f, r2);
    *pa = r;
    *pc = r1;
    *pd = r;
}
/* merge_units: end func_0031D680 */

/* merge_units: begin func_0031D9E8 */
extern float Libc_Log10f(float x);
float ComputePv(float lo, float hi, float p)
{
    float v;
    float r;
    if (p <= 0.0f) p = 0x1.0c6f7ap-20f;
    if (p >= 1.0f) p = 0x1.ffffdep-1f;
    v = Libc_Log10f(1.0f - p) * -10.0f;
    if (v < lo) r = 0.0f;
    else if (v > hi) r = 1.0f;
    else r = (v - lo) / (hi - lo);
    return r;
}
/* merge_units: end func_0031D9E8 */

/* merge_units: begin func_0031DA90 */
#include "types.h"
extern volatile float D_004E1C48;
extern volatile float D_004E1C5C;
extern volatile float D_004E1CF0;
extern volatile float D_004E1BE0;
extern volatile float D_004E1C50;
extern volatile float D_004E1C4C;
float ModifyPv(float a, float b, float c, float d, float e)
{
    float k;
    if (a <= D_004E1C48) b = 0.0f;
    k = D_004E1C5C;
    if (k <= a) {
        a -= k;
        if (a * (d * 0.5f) < 1.0f) a += D_004E1CF0;
        if (b < a) b = a;
    }
    if (b < c && D_004E1CF0 <= c) {
        if (d < e * 1.25f && e * D_004E1BE0 < d) b = b * D_004E1C50 + c * D_004E1C4C;
        {
            float m = D_004E1CF0;
            if (b < m) b += m;
        }
    }
    return b;
}
/* merge_units: end func_0031DA90 */
