#include "types.h"
extern void NellyMagSq(void* a, void* b, int n, float* out);
extern void FindMaxValueFlt(float* a, int n, int* outIdx, float* outVal);
extern int FindBaseBand(float* a, int n);
extern void SelectPeaks(float* a, int n, float* out, int* outn, float x);
extern float powerpoly_125(float x);
extern int SelectPitchCandidates(float* a, int n, float* h, int m, float x, float y, float* d, float* e, int* k);
extern int FindBand4VoicLD(int n, float x);
extern float VoicingLD(void* a, void* b, int s, float x);
extern int FindBestCandidates(float* g, int n, int k);
extern void UpdateLDPDA_MBlk(float* self, float a, float b);
float NellyLDPDA(void* a, void* b, float* c)
{
    float buf[92];
    float e[4];
    float d[4];
    float g[4];
    float h[48];
    int i;
    float v;
    int m;
    int k;
    int n, cnt;
    float r;
    NellyMagSq(a, b, 0x5C, buf);
    FindMaxValueFlt(buf, 0x5C, &i, &v);
    n = FindBaseBand(buf, 0x56);
    SelectPeaks(buf, n, h, &m, v);
    if (v > 0.0f) v = 1.0f / v;
    for (i = n - 1; i >= 0; i--) {
        buf[i] *= v;
        buf[i] = powerpoly_125(buf[i]);
    }
    cnt = SelectPitchCandidates(buf, n, h, m, c[0], c[1], d, e, &k);
    n = FindBand4VoicLD(n, d[cnt - 1]);
    for (i = cnt - 1; i >= 0; i--)
        g[i] = VoicingLD(a, b, n, d[i]);
    k = FindBestCandidates(g, cnt, k);
    r = d[k];
    UpdateLDPDA_MBlk(c, r, e[k]);
    return r;
}
