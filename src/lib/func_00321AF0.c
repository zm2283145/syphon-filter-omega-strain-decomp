typedef struct {
    char pad[0x808];
    float x[65];
    float y[65];
} S_00321AF0;
extern float fSetKLFactor(float a, float b);
/* float parameters listed first: same EE register assignment as the int-first definition, but it gives retail argument setup order */
extern void SetAmpAndPhase(float add, float step, float unused, float mix, int n, int start, S_00321AF0* p, float* out1, float* ta, float* out2, float* tb);
extern void NellyHFRegeneration(float* s, float* out, int n, float x);
extern void excitePhaseInvertAmps(int n, float* a, float* b, float x, float y);
extern void insertSubHarmonics(int total, int n, int factor, float* b, float* a, int lo);
extern void unvoicedPhase(int start, int end, int* state, float* out);
extern void scaleAmps(int n, float* a);
extern void FftSumCosOlAdd(float r, int n, int m, int b, S_00321AF0* c, float* d, float* g, float* h);
void NellySWSynth(float x, float y, float r, float* a, int b, S_00321AF0* c, float* d, float* e, float* f,
                   float* g, float* h, int* buf)
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
    sk = k / (float)fac;
    total = n * fac;
    start = (int)(y * 0.001953125f * x);
    add = fSetKLFactor(x, sk);
    SetAmpAndPhase(add, k, sk, r, n, start, c, h, e, g, f);
    mid = start * fac;
    NellyHFRegeneration(a, &out, 80, k);
    excitePhaseInvertAmps(n, g, h, out, x);
    insertSubHarmonics(total, n, fac, g, h, start);
    unvoicedPhase(mid, total, buf, g);
    scaleAmps(total, h);
    FftSumCosOlAdd(sk, total, 160, b, c, d, g, h);
}
