extern void *(*D_004E1D3C)(void *d, int c, int n);
extern int func_00323250(void);
extern void func_00323458(float *re, float *im, int n);
extern void func_00322688(float *re, float *im, int n);

void func_00318FC8(float *in, int n, float *out, int m)
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
        func_00323458(re, im, 0x80);
    else
        func_00322688(re, im, 0x80);
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


