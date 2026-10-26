/*
 * lib/medius: 5 files, 0031CF58-0031D290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031CF58 */
extern const float D_004E1C90;
extern const float D_004E1C98;

void AddBackTrackCand(float *x, int v, int *list, int *n, int *best)
{
    int cnt = *n;
    int i = 0;
    int b = *best;
    int found = 0;
    int j;
    float xv, tb, t0;

    for (j = 0; j < cnt; j++) {
        if (v == list[j])
            found = 1;
        if (list[j] < v)
            break;
    }
    i = j;
    if (!found) {
        xv = x[v];
        t0 = x[list[0]] * D_004E1C98;
        tb = x[list[b]] * D_004E1C90;        if ((i == cnt && t0 <= xv) || (b < i && tb <= xv)) {
            for (j = cnt; j > i; j--)
                list[j] = list[j - 1];
            list[i] = v;
            if (tb <= xv)
                b = i;
            cnt++;
        }
    }
    *best = b;
    *n = cnt;
}
/* merge_units: end func_0031CF58 */

/* merge_units: begin func_0031D088 */
extern float D_004B3968[];
extern float CalcCostFunc(int a, int b, float f, int c, int d, float g);

float RefineLDPitch(int k, int a, int b, int c, int d, float *best, float g)
{
    float cand[2];
    float res = D_004B3968[k];
    float x, v;
    int n = 0, i;

    if (k > 0) cand[n++] = (res + D_004B3968[k - 1]) * 0.5f;
    k++;
    if (k < 74) cand[n++] = (res + D_004B3968[k]) * 0.5f;
    for (i = 0; i < n; i++) {
        x = cand[i];
        v = CalcCostFunc(a, b, x, c, d, g);
        if (*best < v) {
            *best = v;
            res = x;
        }
    }
    return res;
}
/* merge_units: end func_0031D088 */

/* merge_units: begin func_0031D1D8 */
#include "types.h"
extern float Libc_Logf(float);
extern float D_004E1BE8;
extern float D_004E1CF4;int NellyQuanPitchSC3(float x)
{
    float t;
    float y;
    if (!(x > 8.0f)) x = 8.0f;
    if (x > 160.0f) y = 160.0f; else y = x;
    t = (D_004E1BE8 - Libc_Logf(y)) * D_004E1CF4;
    return (int)(t > 0.0f ? t + 0.5f : t - 0.5f);
}
/* merge_units: end func_0031D1D8 */

/* merge_units: begin func_0031D260 */
extern float D_004E1BE4, D_004E1BE8;
extern float Libc_Expf(float x);
float NellyUnQuanPitchSC3(int n) { return Libc_Expf(D_004E1BE8 - (float)n * D_004E1BE4); }
/* merge_units: end func_0031D260 */

/* merge_units: begin func_0031D290 */
extern float MidEstPitch(float, float, float, float);

float UnQuanMidPitchSC3(float f12, float f13, float f14, float f15) {
    return MidEstPitch(f12, f13, f14, f15);
}
/* merge_units: end func_0031D290 */
