typedef struct {
    char pad[0x808];
    float x[65];
    float y[65];
} S_00321D18;
extern float fSetKLFactor(float a, float b);
/* float/int parameter interleaving only changes argument setup order (the EE ABI assigns float and int registers independently); these orders give retail's */
extern void SetAmpAndPhase(float add, float step, float unused, int n, int start, S_00321D18* p, float* out1, float* ta, float* out2, float* tb, float mix);
extern void NellyHFRegeneration(float* s, float* out, float x, int n);
extern void excitePhaseInvertAmps(int n, float* a, float* b, float x, float y);
extern void insertSubHarmonics(int total, int n, int factor, float* b, float* a, int lo);
extern void unvoicedPhase(int start, int end, int* state, float* out);
extern void scaleAmps(int n, float* a);
typedef void* (*Hook_00321D18)(void* p, int c, int n);
extern Hook_00321D18 D_004E1D3C;
void NellyAltSWSynth(float x, float y, float r, float* a, int b, S_00321D18* c, float* d, float* e, float* f,
                   float* g, int* buf, float* osk, int* ototal)
{
    float out;
    int n = (int)(x * 0.5f);
    float k = 512.0f / x;
    int fac, total, start, mid;
    float sk, add;
    y = y * 256.0f;
    if ((int)(k * (float)n + 0.5f) >= 256) n = n - 1;
    if (n > 100) n = 100;
    if (y < 256.0f)
        fac = 100 / n;
    else
        fac = 1;
    start = (int)(y * 0.001953125f * x);
    total = n * fac;
    sk = k / (float)fac;
    add = fSetKLFactor(x, sk);
    mid = start * fac;
    D_004E1D3C(c, 0, 0x808);
    SetAmpAndPhase(add, k, sk, n, start, c, g, d, f, e, r);
    NellyHFRegeneration(a, &out, k, 80);
    excitePhaseInvertAmps(n, f, g, out, x);
    insertSubHarmonics(total, n, fac, f, g, start);
    unvoicedPhase(mid, total, buf, f);
    scaleAmps(total, g);
    *osk = sk;
    *ototal = total;
}
