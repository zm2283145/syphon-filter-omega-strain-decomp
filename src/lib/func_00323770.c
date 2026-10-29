extern void FindMaxValueFlt(float* a, int n, int* outIdx, float* outVal);
extern float NellyLog2(float x);
extern float* D_004E1D5C;

void PostFilter(float g, float* out, float* refl)
{
    float env[8];
    int idx0;
    float v0;
    int idx1;
    float v1;
    float p;
    float base;
    float a;
    float m;
    float c;
    int i;
    int j;
    int k;
    int l;
    FindMaxValueFlt(out, 0x40, &idx0, &v0);
    p = 1.0f;
    for (i = 1; i < 12; i++)
        p *= 1.0f - refl[i] * refl[i];
    base = g - NellyLog2(p) * 0.5f;
    a = refl[0];
    c = a * a + 1.0f;
    m = a * -2.0f;
    for (i = 0, j = 0; i < 5; i++, j += 32)
        env[i] = base - NellyLog2(c + m * D_004E1D5C[j]) * 0.5f;
    for (k = 1; k < 64; k++) {
        float lo = env[k >> 4];
        float d;
        float e;
        float f;
        d = (out[k] - (lo + (k & 15) * 0.0625f * (env[(k >> 4) + 1] - lo))) * 0.5f;
        e = 0.26303441f < d ? 0.26303441f : d;
        f = -1.0f < e ? e : -1.0f;
        if (k < 16)
            f *= k * 0.0625f;
        out[k] += f;
    }
    FindMaxValueFlt(out, 0x40, &idx1, &v1);
    for (k = 0; k < 64; k++)
        out[k] += v0 - v1;
}




