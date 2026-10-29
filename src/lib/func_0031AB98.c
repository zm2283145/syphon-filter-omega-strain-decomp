extern void *(*D_004E1D3C)(void *d, int c, int n);
void NellyWarpSC36(float *in, float *out);
float NellyInvLog2(float);
float NellyLog2(float);
int func_00323250(void);
void nvuInverseRealFft(float *a, float *b, int n);
void inverseRealFft(float *a, float *b, int n);
void NellyDurbin(float *v, int n, int a, int b, float *res);

void NellyLogEnvelopeToAs(float *a, int n, float *outp, int p3, int p4)
{
    float out[16];
    float buf[65];
    float buf2[65];
    float res;
    float *b, *b2;
    float *p, *q, *q2, *d;
    int i;
    int half;
    NellyWarpSC36(a, a);
    p = a;
    b = q = buf;
    for (i = 0xFC; i >= 0; i -= 4) {
        *q++ = NellyInvLog2(*p);
        p += 4;
    }
    *q = NellyInvLog2(a[255]);
    b2 = buf2;
    D_004E1D3C(b2, 0, sizeof(buf2));
    if (func_00323250())
        nvuInverseRealFft(b, b2, 0x80);
    else
        inverseRealFft(b, b2, 0x80);
    half = n >> 1;
    out[0] = b[0] * 0.0078125f;
    out[1] = b2[0] * 0.0078125f * 0.999998987f;
    q = buf + 1;
    q2 = buf2 + 1;
    d = out + 2;
    for (i = 0; i < half; i++) {
        *d++ = *q++ * 0.0078125f * 0.999998987f;
        *d++ = *q2++ * 0.0078125f * 0.999998987f;
    }
    if (half * 2 != n)
        *d = *q * 0.0078125f * 0.999998987f;
    NellyDurbin(out, n, p3, p4, &res);
    *outp = NellyLog2(res) * 0.5f;
}


