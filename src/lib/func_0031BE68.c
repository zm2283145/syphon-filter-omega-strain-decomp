#include "types.h"
/* sqrtf is expanded inline by gcc (sqrt.s + NaN fallback call); alias the libcall to the retail sqrtf. */
__asm__("sqrtf = func_00121B48");
float sqrtf(float);
float func_00317780(float* a, float* b, int n);
float func_0031AB38(float a, float b, float c, float* out);
extern float D_004E1D2C[];
extern float D_004E1BB4;

float func_0031BE68(float rate, float scale, float* buf, int n, float* out) {
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
        v = func_00317780(buf, &buf[i], n - i);
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
        res = (float)pk + func_0031AB38(vals[0], best, vals[2], out);
    } else {
        res = (float)pk;
        *out = best;
    }
    m = n - pk;
    e = func_00317780(buf, buf, m);
    e = e * func_00317780(&buf[pk], &buf[pk], m);
    *out = *out / sqrtf(e + D_004E1BB4);
    return res;
}





