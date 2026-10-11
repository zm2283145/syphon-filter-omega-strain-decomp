#include "types.h"
extern void func_0031BA78(void* a, void* b, int n, float* out);
extern void func_0031BB28(float* a, int n, int* outIdx, float* outVal);
extern int func_00318B08(float* a, int n);
extern void func_00318C60(float* a, int n, float* out, int* outn, float x);
extern float func_00318720(float x);
extern int func_0031C8D8(float* a, int n, float* h, int m, float x, float y, float* d, float* e, int* k);
extern int func_0031DD70(int n, float x);
extern float func_0031DB68(void* a, void* b, int s, float x);
extern int func_00318BB0(float* g, int n, int k);
extern void func_00318C50(float* self, float a, float b);
float func_00318848(void* a, void* b, float* c)
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
    func_0031BA78(a, b, 0x5C, buf);
    func_0031BB28(buf, 0x5C, &i, &v);
    n = func_00318B08(buf, 0x56);
    func_00318C60(buf, n, h, &m, v);
    if (v > 0.0f) v = 1.0f / v;
    for (i = n - 1; i >= 0; i--) {
        buf[i] *= v;
        buf[i] = func_00318720(buf[i]);
    }
    cnt = func_0031C8D8(buf, n, h, m, c[0], c[1], d, e, &k);
    n = func_0031DD70(n, d[cnt - 1]);
    for (i = cnt - 1; i >= 0; i--)
        g[i] = func_0031DB68(a, b, n, d[i]);
    k = func_00318BB0(g, cnt, k);
    r = d[k];
    func_00318C50(c, r, e[k]);
    return r;
}
