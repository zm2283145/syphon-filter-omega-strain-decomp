/* func_0031D680: gcc296 (ee-gcc2.96 -O2). The float argument of func_0031BAF0/func_0031D5C8/func_0031D2A8 is
   declared in the position matching retail's argument-load order (EABI-equivalent: floats go in \ regardless). */
extern int func_00323250(void);
extern void func_0031BB28(float *a, int n, int *outIdx, float *outVal);
extern void func_0031BAF0(float *src, int n, float s, float *dst);
extern void func_0031D5C8(float *in, int n, float scale, float *out);
extern void func_0031A9A0(float *x, float *y, int n, float *o1, float *o2, int *cnt, int max, float f);
extern void func_0031D2A8(float f, float *a, float *b, int n, float *r0, float *r1, float *r2);
extern float func_0031D9E8(float lo, float hi, float p);

void func_0031D680(float *pa, float *pb, float *pc, float *pd, float *x, float *y, int n, int max)
{
    float buf0[256];
    float buf1[100];
    float buf2[100];
    int idx;
    float m1;
    float m2;
    int k;
    float r0;
    float r1;
    float r2;
    float c;
    float inv;
    float lim;
    float t;
    float r;
    float scale;
    int i;
    int j;
    int cnt;
    int top;
    int q;

    c = *pc;
    lim = c * 0x1.58p-3f;
    inv = 512.0f / c;
    if (lim >= 0.0f) i = (int)lim;
    else i = (int)(lim - 1.0f);
    if (i < 5) i = 5;
    t = ((float)i + 0.125f) * inv;
    if (t > 160.0f) t = 160.0f;
    top = (int)(t + 0.5f);
    top++;
    for (idx = 0; idx < n; idx++) if (t < y[idx]) break;
    cnt = idx;
    if (cnt > 0) {
        func_0031BB28(x, cnt, &idx, &m1);
        func_0031BB28(pb, top, &idx, &m2);
        m1 = (m2 < m1) ? m1 : m2;
        if (m1 == 0.0f) scale = 1.0f;
        else scale = 1.0f / m1;
        if (func_00323250()) func_0031BAF0(x, cnt, scale, x);
        else func_0031D5C8(x, cnt, scale, x);
        if (func_00323250()) func_0031BAF0(pb, top, scale, buf0);
        else func_0031D5C8(pb, top, scale, buf0);
        for (q = 0; q < cnt; q++) {
            m2 = y[q];
            j = (int)(m2 + 0.5f);
            if (x[q] < buf0[j]) {
                m2 = x[q] / buf0[j];
                m2 = m2 * m2;
                x[q] = x[q] * (m2 * m2);
            }
        }
        func_0031A9A0(x, y, cnt, buf1, buf2, &k, max, 0x1.b3333p+5f);
        func_0031D2A8(c, buf1, buf2, k, &r0, &r1, &r2);
    } else {
        r1 = c;
        r2 = 0.0f;
    }
    r = func_0031D9E8(*pa * -0.5f + 4.5f, 13.0f, r2);
    *pa = r;
    *pc = r1;
    *pd = r;
}
