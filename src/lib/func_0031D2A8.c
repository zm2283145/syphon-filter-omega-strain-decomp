#include "types.h"
extern void GetPitchTable(float **tab, int *cnt);
extern void corrfunc(float step, float lo, float hi, float *best, int n, float *x, float sum, int *y, float *pos);
int NellyRefineC0(float *x, float *y, int n, float *outSum, float *outPos, float *outRatio, float f)
{
    int buf[100];
    float *tab;
    int cnt;
    float best;
    float pos;
    int i;
    int bi;
    float k, w, step, sum, lo, hi, c;

    k = 2048.0f;
    for (i = 0; i < n; i++)
        buf[i] = (int)(y[i] * k + 0.001f + 0.5f);
    GetPitchTable(&tab, &cnt);
    pos = f;
    { int j; float d, e; bi = 0; d = pos - tab[0]; d = d * d; for (j = 1; j < cnt; j++) { e = pos - tab[j]; e = e * e; if (e < d) { d = e; bi = j; } } }
    if (bi != 0) {
        w = tab[bi] - tab[bi - 1];
        if ((unsigned)bi < (unsigned)(cnt - 1))
            w = (tab[bi + 1] - tab[bi - 1]) * 0.5f;
    } else {
        w = tab[1] - tab[0];
    }
    sum = 1e-10f;
    for (i = 0; i < n; i++)
        sum += x[i];
    best = 0.0f;
    step = w * 0.375f;
    lo = pos - w * 0.75f;
    if (lo < 8.0f)
        lo = 8.0f;
    hi = pos + w * 0.75f;
    if (hi > 160.0f)
        hi = 160.0f;
    corrfunc(step, lo, hi, &best, n, x, sum, buf, &pos);
    step = w * 0.125f;
    lo = pos - w * 0.25f;
    if (lo < 8.0f)
        lo = 8.0f;
    hi = pos + w * 0.25f;
    if (hi > 160.0f)
        hi = 160.0f;
    corrfunc(step, lo, hi, &best, n, x, sum, buf, &pos);
    *outSum = sum;
    *outRatio = best * 0.5f / sum;
    *outPos = pos;
    return 0;
}






float NellyQuadRoot(float x) { float y = x + 1e-7f; float s = 1.0f; float r; while (y < 0.1f) { y *= 10.0f; s *= 0.5623413f; } r = y * -0.48015625f + 1.0000972f; r = y * r + 0.46449152f; return r * s; }





