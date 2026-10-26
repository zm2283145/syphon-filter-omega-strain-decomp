extern float D_004E1BAC;
extern const float D_004E1BB0;
float NellyLog2(float);
float NellyInvLog2(float);
int NellySeevocPeaksFast(int, int, int, int, float*, float*, int);

void NellySeevocFlattop(float f, int a0, int a1, int a2, int a3, float* out, int t1)
{
    float vals[100];
    float pos[256];
    int j = 0;
    int end = 0;
    int n = NellySeevocPeaksFast(a0, a1, a2, a3, vals, pos, t1);
    float v = NellyInvLog2(NellyLog2(vals[0]) + D_004E1BAC);
    float last = 0.0f;
    int i;
    int k;
    for (i = 0; i < n; i++) {
        float p = pos[i];
        {
            int start = end;
            end = (int)((last + p) * 0.5f + 0.5f);
            for (j = start; j < end; j++) out[j] = v;
        }
        v = vals[i];
        last = p;
    }
    end += (int)f;
    if (end > 256) end = 256;
    for (k = j; k < end; k++) out[k] = v;
    for (k = end; k < 256; k++) out[k] = out[k - 1] * D_004E1BB0;
}



