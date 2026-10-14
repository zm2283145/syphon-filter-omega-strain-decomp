/*
 * lib/medius: 3 files, 00321728-003219F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00321728 */
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
/* merge_units: end func_00321728 */

/* merge_units: begin func_003218F8 */
typedef struct { int w0, w4, w8, wC, w10, w14, w18; char pad1C[0x14]; float rate; float pos; char pad38[0xC]; short hold; short pad46; int buf[1]; } V3218F8;
extern void func_00321AF0(float x, float y, float r, int a, int b, int c, int d, int e, int f, int g, int h, int* buf);
void func_003218F8(V3218F8* s, float (*tbl)[2], int arg, int* cnt)
{
    float step = s->rate * 160.0f;
    if (s->pos <= step) {
        float r = s->pos / step;
        float* p;
        if (r < 0.75f) p = tbl[0]; else p = tbl[1];
        func_00321AF0(p[0], p[1], r, s->w0, arg, s->w4, s->w8, s->wC, s->w10, s->w14, s->w18, s->buf);
        s->pos += 80.0f;
        *cnt += 80;
    }
    if (s->hold == 0 && s->pos > step) s->pos -= step;
}
/* merge_units: end func_003218F8 */

/* merge_units: begin func_003219F0 */
typedef struct { int w0, w4, w8, wC, w10, w14, w18; char pad1C[0x14]; float rate; float pos; char pad38[0xC]; short hold; short pad46; int buf[1]; } V3219F0;
extern void func_00321D18(float x, float y, float r, int a, int b, int c, int d, int e, int f, int g, int* buf, int h, int i);
void func_003219F0(V3219F0* s, float (*tbl)[2], int arg, int* cnt, int e5, int e6)
{
    float step = s->rate * 160.0f;
    if (s->pos <= step) {
        float r = s->pos / step;
        float* p;
        if (r < 0.75f) p = tbl[0]; else p = tbl[1];
        func_00321D18(p[0], p[1], r, s->w0, arg, s->w4, s->wC, s->w10, s->w14, s->w18, s->buf, e5, e6);
        s->pos += 80.0f;
        *cnt += 80;
    }
    if (s->hold == 0 && s->pos > step) s->pos -= step;
}
/* merge_units: end func_003219F0 */
