#include "types.h"
extern float D_004E1C54;
extern float D_004E1CA4;
extern float D_004E1CA8;
extern float D_004E1CAC;
extern void func_0031A418(float* a, int start, int end, int max, int* out, int* count);
extern float func_00121570(float x);
extern void func_00318E48(float* a, int n, float* r, int k);
extern void func_0031A2D0(float* r, int k, float* c, float* e, float* g);
extern void func_0031A960(float* in, float* out, int n, float x);
extern void func_00318FC8(float* c, int k, float* s, int n);

void func_00318C60(float* a, int n, int* out, int* count, float thr)
{
    float c[8];
    float r[8];
    float e[8];
    float s[0x58];
    float g;
    int k;
    int i, j;
    int* o;

    func_0031A418(a, 0, 0x57, 0x2B, out, count);
    k = (int)func_00121570(n * 5.0f / 86.0f);
    if (k >= 8) k = 7;
    func_00318E48(a, n, r, k);
    r[0] *= D_004E1CA4;
    func_0031A2D0(r, k, c, e, &g);
    func_0031A960(c, c, k, D_004E1CA8);
    func_00318FC8(c, k, s, n);
    g *= D_004E1C54;
    thr *= D_004E1CAC;
    j = 0;
    for (i = 0; i < *count; i++) {
        int idx = out[i];
        if (idx < n) {
            float v = a[idx];
            if (g <= v * s[idx] && thr < v) {
                out[j] = idx;
                j++;
            }
        }
    }
    out[j + 0] = 0x7FFF;
    out[j + 1] = 0x7FFF;
    out[j + 2] = 0x7FFF;
    out[j + 3] = 0x7FFF;
    *count = j;
}



