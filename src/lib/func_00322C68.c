extern const float D_004B66A0[];
extern const float D_004B6A98[];
void func_00322C68(float *re, float *im, int n)
{
    float *rp = re, *rq = re + n, *ip = im, *iq = im + n;
    float *tw;
    float a, b, c, d, hr, hi, gr, gi, wr, wi, tr, ti;
    int i;
    a = *rp;
    b = *ip;
    c = *rq--;
    d = *iq--;
    *rp++ = (a + c) - (b + d);
    *ip++ = (a - c) + (b - d);
    if (n == 256) tw = ((float*)D_004B66A0);
    else tw = ((float*)D_004B6A98);
    n >>= 1;
    re[n] += re[n];
    im[n] += im[n];
    for (i = 1; i < n; i++) {
        b = *ip;
        a = *rp;
        c = *rq;
        d = *iq;
        hr = a - c;
        hi = b + d;
        gi = b - d;
        gr = a + c;
        wr = *tw++;
        wi = *tw++;
        tr = hr * wr + hi * wi;
        ti = hi * wr - hr * wi;
        *rp++ = gr - ti;
        *ip++ = gi + tr;
        *rq-- = gr + ti;
        *iq-- = -(gi - tr);
    }
}
