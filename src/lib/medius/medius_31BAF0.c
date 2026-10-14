/*
 * lib/medius: 3 files, 0031BAF0-0031BB78
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031BAF0 */
void func_0031BAF0(float* src, int n, float* dst, float s)
{
    while (n-- > 0) {
        *dst++ = *src++ * s;
    }
}
/* merge_units: end func_0031BAF0 */

/* merge_units: begin func_0031BB28 */
#include "types.h"
void func_0031BB28(float* a, int n, int* outIdx, float* outVal) {
    float m = *a;
    int idx = 0;
    int i;
    a++;
    for (i = 1; i < n; i++) {
        if (m < *a) { m = *a; idx = i; }
        a++;
    }
    *outIdx = idx;
    *outVal = m;
}
/* merge_units: end func_0031BB28 */

/* merge_units: begin func_0031BB78 */
typedef struct {
    int h;
    int pad[6];
    int sub[5];
    float a;
    float b;
} S_bb78;

extern float D_004E1BEC;
extern float func_0031BDB8(float a, float b, float c, float d);
extern void func_0031BD50(int h, float *buf, int *n, int arg, float v);
extern float func_0031BE68(float *buf, int n, float *r, float v, float k);
extern float func_0031BC70(float a, float b, float c, float d, int *sub);

void func_0031BB78(S_bb78 *s, float *out, int arg, int unused, int mode, float x)
{
    float buf[264];
    int n;
    float r;
    float v, t;
    float *p = &out[2];

    v = func_0031BDB8(s->b, p[0], s->a, p[1]);
    if (mode == 1) v += v;
    func_0031BD50(s->h, buf, &n, arg, v);
    t = func_0031BE68(buf, n, &r, v, D_004E1BEC);
    out[0] = t;
    if (mode == 1) out[0] = t * 0.5f;
    out[1] = func_0031BC70(s->a, p[1], x, r, s->sub);
}
/* merge_units: end func_0031BB78 */
