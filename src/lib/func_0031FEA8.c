typedef struct { float re, im; } Cpx;
typedef struct P1FEA8 {
    int f0;
    Cpx *f4;
    char pad8[0x14 - 0x8];
    float *f14;
    float *f18;
} P1FEA8;
typedef union { float *p; int i; } TblU;
extern TblU D_004E1D5C;
extern TblU D_004E1D58;
extern void RealInverseFft(float *buf, int a, int b);
void FftTripleSumCosOlAdd(int n0, int n1, int n2, int len, short *out,
                   P1FEA8 *p0, P1FEA8 *p1, P1FEA8 *p2,
                   float d0, float d1, float d2)
{
    int i, half, idx; int k;
    float ph, a, step, w;
    float *src;
    float *buf = (float *)p0->f4;
    float *fa0 = p0->f14, *am0 = p0->f18;
    float *fa1 = p1->f14, *am1 = p1->f18;
    float *fa2 = p2->f14, *am2 = p2->f18;

    half = len >> 1;
    ph = d0;
    for (i = 0; i < n0; i++) {
        idx = (int)(ph + 0.5f);
        a = am0[i] * 0.5f;
        k = (int)(fa0[i] * 40.743664f + 0.5f); k &= 0xFF;
        buf[idx * 2] = a * D_004E1D5C.p[k];
        buf[idx * 2 + 1] = a * D_004E1D58.p[k];
        ph += d0;
    }
    ph = d1;
    for (i = 0; i < n1; i++) {
        idx = (int)(ph + 0.5f);
        a = am1[i] * 0.5f;
        k = (int)(fa1[i] * 40.743664f + 0.5f); k &= 0xFF;
        buf[idx * 2] += a * D_004E1D5C.p[k];
        buf[idx * 2 + 1] += a * D_004E1D58.p[k];
        ph += d1;
    }
    ph = d2;
    for (i = 0; i < n2; i++) {
        idx = (int)(ph + 0.5f);
        a = am2[i] * 0.5f;
        k = (int)(fa2[i] * 40.743664f + 0.5f); k &= 0xFF;
        buf[idx * 2] += a * D_004E1D5C.p[k];
        buf[idx * 2 + 1] += a * D_004E1D58.p[k];
        ph += d2;
    }
    RealInverseFft(buf, 9, 8);
    if (half > 0) a = 1.0f / half; else a = 0.0f;
    src = buf + (512 - half);
    /* pinned registers: retail's global/local FP allocation for the crossfade loop */
    {
        register float v asm("$f5");
        v = 0.0f;
        ph = 1.0f;
        for (k = half; k > 0; k--) {
            register float s asm("$f2") = *src * v;
            register float o asm("$f1") = (float)*out * ph;
            register float r asm("$f0") = o + s;
            *out = (int)(r + 32768.5f - 32768.0f);
            src++;
            out++;
            v += a;
            ph -= a;
        }
    }
}