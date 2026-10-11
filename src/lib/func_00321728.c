#include "types.h"
typedef struct {
    char pad[0x808];
    float x[65];
    float y[65];
} S_00321728;
extern float func_003216E0(float x);
void func_00321728(int n, int start, S_00321728* p, float* out1, float* ta, float* out2, float* tb,
                   float add, float step, float unused, float mix)
{
    int i, k;
    float ph, t, f, v, u;
    float* x = p->x; float* y = p->y;
    x[64] = x[63];
    y[64] = y[63];
    ph = step;
    for (i = 0; i < n; i++) {
        t = func_003216E0(ph) * 0.25f;
        ph += step;
        k = (int)t;
        f = t - (float)k;
        out1[i] = ta[k] + f * (ta[k + 1] - ta[k]) + mix * ((x[k] + f * (x[k + 1] - x[k])) - (ta[k] + f * (ta[k + 1] - ta[k])));
        out2[i] = tb[k] + f * (tb[k + 1] - tb[k]) + mix * ((y[k] + f * (y[k + 1] - y[k])) - (tb[k] + f * (tb[k + 1] - tb[k])));
    }
    for (i = start; i < n; i++)
        out1[i] += add;
}