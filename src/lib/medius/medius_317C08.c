#include "types.h"
extern int NellyAdaptiveWindow(float);
extern int EstOnset(void* a, void* b, int n, int m, float* buf);
extern void GetFrameSpCBM(void* b, int n, int m, float* buf);
extern void ScaleVector(float* a, int m, float* b, float x);
extern void HammingWindowNormSC(float* a, int m);
extern int func_00323250(void);
extern void nvuFftCenter512(float* a, int m, int n, void* c, void* d);
extern void NellyFftCenter512(float* a, int m, int n, void* c, void* d);
void PitchAdaptiveSpectrum(void* a, void* b, float x, void* c, void* d, int* outm, int* outn)
{
    float buf[264];
    int m = NellyAdaptiveWindow(x);
    int n = EstOnset(a, b, 0x91, m, buf);
    *outn = n;
    GetFrameSpCBM(b, n + 0x91, m, buf);
    ScaleVector(buf, m, buf, 2.0f);
    HammingWindowNormSC(buf, m);
    if (func_00323250())
        nvuFftCenter512(buf, m, 9, c, d);
    else
        NellyFftCenter512(buf, m, 9, c, d);
    *outm = m;
}