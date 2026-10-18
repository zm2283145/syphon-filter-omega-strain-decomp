typedef struct {
    char pad[0x808];
    float x[65];
    float y[65];
} S_00321AF0;
extern float func_00321FA0(float a, float b);
/* float parameters listed first: same EE register assignment as the int-first definition, but it gives retail argument setup order */
extern void func_00321728(float add, float step, float unused, float mix, int n, int start, S_00321AF0* p, float* out1, float* ta, float* out2, float* tb);
extern void func_00322030(float* s, float* out, int n, float x);
extern void func_00322168(int n, float* a, float* b, float x, float y);
extern void func_00322258(int total, int n, int factor, float* b, float* a, int lo);
extern void func_00322340(int start, int end, int* state, float* out);
extern void func_003223B8(int n, float* a);
extern void func_0031FC28(float r, int n, int m, int b, S_00321AF0* c, float* d, float* g, float* h);
void func_00321AF0(float x, float y, float r, float* a, int b, S_00321AF0* c, float* d, float* e, float* f,
                   float* g, float* h, int* buf)
{
    float out;
    int n = (int)(x * 0.5f);
    float k = 512.0f / x;
    int fac, total, start, mid;
    float sk, add;
    y = y * 256.0f;
    if ((int)(k * (float)n + 0.5f) >= 256) n = n - 1;
    if (n > 100) n = 100;
    if (y < 256.0f)
        fac = 100 / n;
    else
        fac = 1;
    sk = k / (float)fac;
    total = n * fac;
    start = (int)(y * 0.001953125f * x);
    add = func_00321FA0(x, sk);
    func_00321728(add, k, sk, r, n, start, c, h, e, g, f);
    mid = start * fac;
    func_00322030(a, &out, 80, k);
    func_00322168(n, g, h, out, x);
    func_00322258(total, n, fac, g, h, start);
    func_00322340(mid, total, buf, g);
    func_003223B8(total, h);
    func_0031FC28(sk, total, 160, b, c, d, g, h);
}
