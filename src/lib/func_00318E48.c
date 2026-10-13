extern void *(*D_004E1D3C)(void *d, int c, int n);
extern int func_00323250(void);
extern void func_003234B0(float *re, float *im, int n);
extern void func_003226E0(float *re, float *im, int n);

void func_00318E48(float *in, int f, float *out, int n)
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
    if (func_00323250()) func_003234B0(re, im, 128);
    else func_003226E0(re, im, 128);
    m = (n + 1) >> 1;
    p = re; q = im;
    for (i = 0; i < m; i++) { *out++ = *p++ * 0.0078125f; *out++ = *q++ * 0.0078125f; }
    if (m * 2 != n + 1) *out = *p * 0.0078125f;
}
