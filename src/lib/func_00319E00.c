extern float D_004E1BCC;
extern float Math_Cos(float x);
void func_00319E00(float *buf, int n, float a, float b)
{
    int half = n >> 1;
    float *lo = buf;
    float *hi = buf + n - 1;
    float p2 = b;
    float k, p1, t, w;
    int i;
    k = Math_Cos(D_004E1BCC / (float)(n - 1));
    p1 = k * b;
    k = k + k;
    w = a - b;
    *lo++ *= w;
    *hi-- *= w;
    w = a - p1;
    *lo++ *= w;
    *hi-- *= w;
    for (i = 2; i + 2 < half; i += 3) {
        t = k * p1; t -= p2;
        w = a - t;
        *lo++ *= w;
        *hi-- *= w;
        p2 = k * t; p2 -= p1;
        w = a - p2;
        *lo++ *= w;
        *hi-- *= w;
        p1 = k * p2; p1 -= t;
        w = a - p1;
        *lo++ *= w;
        *hi-- *= w;
    }
    if (i < half) {
        t = k * p1; t -= p2;
        w = a - t;
        *lo++ *= w;
        *hi-- *= w;
        i++;
        if (i < half) {
            p2 = k * t; p2 -= p1;
            w = a - p2;
            *lo++ *= w;
            *hi-- *= w;
        }
    }
    if (n & 1)
        *lo *= a + b;
}


