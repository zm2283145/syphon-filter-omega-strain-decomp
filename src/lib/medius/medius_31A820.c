#include "types.h"
extern void NellyMagSq(void* a, void* b, int n, float* out);
extern void PeakPick(float* a, int start, int end, int max, int* out, int* count);
extern float QuadraticPeak(float* out, float y0, float y1, float y2);
void NellySTFTpeaks(void* a, void* b, float* buf, float* val, float* pos, int* count, int max)
{
    int idx[100];
    int i; int k;
    NellyMagSq(a, b, 0x100, buf);
    PeakPick(buf, 0, 0x100, max, idx, count);
    for (i = 0; i < *count; i++) {
        k = idx[i];
        pos[i] = (float)k + QuadraticPeak(&val[i], buf[k - 1], buf[k], buf[k + 1]);
    }
    if (*count < 4) {
        float d = 7.0f; float p = d; for (k = 0; k < 36; k++) { pos[k] = p; p += d; val[k] = buf[(k + 1) * 7];
        }
        *count = 36;
    }
}