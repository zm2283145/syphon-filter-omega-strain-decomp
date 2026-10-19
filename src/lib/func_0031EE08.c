extern void *(*D_004E1D3C)(void *p, int c, int n);
extern float D_004B7770[];
extern const float D_004E1D60;
extern void func_0031F0A0(float *a, float *b);
extern void func_0031F138(float *a, float g, float *c);
extern int func_00323250(void);
extern void func_00323458(float *re, float *im, int n);
extern void func_00322688(float *re, float *im, int n);
extern void func_00323770(float *a, char *b, float f);
/* src/lib/medius/medius_31F260.c defines (float *buf, float *tmp, float ratio); the float goes in $f12
   either way under the EE ABI, and declaring it second gives retail's argument-setup order. */
extern void func_0031F260(float *buf, float ratio, float *tmp);

void func_0031EE08(float a, float *c, char *base, float *d, float *e, float b)
{
    float re[65];
    float im[65];
    float *o1 = (float *)(base + 2056);
    float *o2 = (float *)(base + 2316);
    float *fb;
    float *q;
    float *s;
    float *p;
    float *r0, *r1, *i0, *i1;
    int i;

    D_004E1D3C(base, 0, 2316);
    fb = (float *)base;
    i = 12;
    do {
        *fb++ = D_004B7770[(unsigned char)(int)(*c++ * D_004E1D60 + 0.5f)];
    } while (--i);
    q = (float *)(base + 224);
    func_0031F0A0((float *)base, q);
    for (i = 0; i < 12; i++) {
        e[i] = q[i];
        d[i] = ((float *)base)[i];
    }
    s = (float *)(base + 48);
    func_0031F138(q, a, s);
    D_004E1D3C(re, 0, sizeof(re));
    D_004E1D3C(im, 0, sizeof(im));
    i0 = im;
    r1 = &re[63];
    i1 = &im[63];
    p = s + 1;
    r0 = &re[1];
    re[0] = s[0];
    for (i = 20; i >= 0; i--) {
        *i0++ = *p * 1.6931471f;
        *i1-- = *p++ * 0.30685288f;
        *r0++ = *p * 1.6931471f;
        *r1-- = *p++ * 0.30685288f;
    }
    *i0 = *p * 1.6931471f;
    *i1 = *p * 0.30685288f;
    if (func_00323250())
        func_00323458(re, im, 128);
    else
        func_00322688(re, im, 128);
    r0 = re;
    i0 = im;
    i = 65;
    while (i-- > 0) {
        *o1++ = *r0++;
        *o2++ = *i0++;
    }
    o1 = (float *)(base + 2056);
    func_00323770(o1, base, a);
    func_0031F260(o1, b, (float *)base);
}
