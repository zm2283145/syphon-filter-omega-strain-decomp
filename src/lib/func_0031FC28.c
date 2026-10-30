extern void *(*D_004E1D3C)(void *p, int c, int n);
extern float *D_004E1D5C;
extern float *D_004E1D58;
extern const float D_004E1D60;
extern int func_00323250(void);
extern void nvuInverseRealFft(float *re, float *im, int n);
extern void inverseRealFft(float *re, float *im, int n);

void FftSumCosOlAdd(int n, int len, short *out, int unused, float *ola, float *fa, float *am, float d)
{
    float re[257];
    float im[257];
    int i, half, idx, k, j;
    float ph, a, v, w, x, y, st;
    float *p, *q, *o;

    ph = d;
    half = len >> 1;
    D_004E1D3C(re, 0, sizeof(re));
    D_004E1D3C(im, 0, sizeof(im));
    {
        register float* ip __asm__("$4") = im;
        /* Keep the loop-entry base copy in a0 without emitting an instruction. */
        __asm__("" : "+r"(ip));
        i = 0;
        if (n > 0) {
            float hs = 0.5f;
            float* loopIm = ip;
            float cf = D_004E1D60;
            float* ct = D_004E1D5C;
            float* stbl = D_004E1D58;
            do {
                idx = (int)(ph + hs);
                a = am[i] * hs;
                k = (int)(fa[i] * cf + hs);
                k &= 0xFF;
                re[idx] = a * ct[k];
                *(float*)((int)loopIm + (idx << 2)) = a * stbl[k];
                ph += d;
                i++;
            } while (i < n);
        }
    }
    if (func_00323250())
        nvuInverseRealFft(re, im, 512);
    else
        inverseRealFft(re, im, 512);
    if (half > 0)
        st = 1.0f / half;
    else
        st = 0.0f;
    v = 0.0f;
    w = 1.0f;
    o = ola;
    p = &re[216];
    q = &im[216];
    for (j = 40; j > 0; j--) {
        register float t0 asm("$f2");
        register float t1 asm("$f0");
        register float t2 asm("$f3");
        register float t3 asm("$f1");
        t0 = *o++ * w;
        t1 = *p++ * v;
        v += st;
        w -= st;
        t2 = *o * w;
        t3 = *q++ * v;
        o++;
        t0 = t0 + t1;
        t1 = t0 + 0.5f;
        t0 = t2 + t3;
        *out++ = (int)t1;
        t3 = t0 + 0.5f;
        *out++ = (int)t3;
        v += st;
        w -= st;
    }
    {
        /* Preserve the retail copy-loop base initialization order. */
        register float* qi __asm__("$4") = im;
        o = ola;
        p = re;
        for (j = 0; j < 40; j++) {
            *o++ = *p++;
            *o++ = *qi++;
        }
    }
}