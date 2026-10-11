#include "types.h"
extern float D_004B66A0[];
extern float D_004B6A98[];
void func_00322B40(float* re, float* im, int n)
{
    float *rp = re, *rq = re + n, *ip = im, *iq = im + n;
    float* tw;
    float a, b, c, d, hr, hi, gr, gi, wr, wi, tr, ti;
    int i;
    a = *rp;
    b = *ip;
    *rp++ = a + b;
    *rq-- = a - b;
    *ip++ = 0;
    *iq-- = 0;
    if (n == 256) tw = D_004B66A0;
    else tw = D_004B6A98;
    n >>= 1;
    for (i = 1; i < n; i++) {
        b = *ip;
        a = *rp;
        c = *rq;
        d = *iq;
        hr = (a - c) * 0.5f;
        hi = (b + d) * 0.5f;
        gi = (b - d) * 0.5f;
        gr = (a + c) * 0.5f;
        wr = *tw++;
        wi = *tw++;
        tr = hr * wr - hi * wi;
        ti = hi * wr + hr * wi;
        *rp++ = gr + ti;
        *rq-- = gr - ti;
        *ip++ = gi - tr;
        *iq-- = -(gi + tr);
    }
    im[i] = -im[i];
}