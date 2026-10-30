register float g2 asm("$f2"), g5 asm("$f5"), g7 asm("$f7"), g8 asm("$f8");
extern float* D_004E1D24;
extern float* D_004E1D28;

void InverseUnpack(float* a, int logn)
{
    int n = 1 << logn;
    int m = n >> 1;
    unsigned int ks = 0x200U >> logn;
    float* wc;
    float* ws;
    register float xi asm("$f3"); register float yr asm("$f0"); register float yi asm("$f1"); register float m2 asm("$f4");
    int j, k;

    g2 = a[0];
    xi = a[1];
    yr = a[n];
    yi = a[n + 1];
    g5 = g2 - yr; g7 = xi + yi; g8 = xi - yi; g2 = g2 + yr;
    g5 = g5 + g8;
    g2 = g2 - g7;
    a[1] = g5;
    a[0] = g2;
    a[m] = a[m] * 2.0f;
    m2 = -2.0f; a[m + 1] = a[m + 1] * m2;
    wc = D_004E1D28;
    ws = D_004E1D24;
    for (j = 2; j < m; j += 2) {
        register float t0r asm("$f4"), t0i asm("$f3"), x0r asm("$f1"), x0i asm("$f5"), wr asm("$f6"), wi asm("$f0");
        register float p0 asm("$f0"), p1 asm("$f1"), ak asm("$f0"), aj asm("$f4"), aj1 asm("$f3");
        k = n - j;
        wc -= ks;
        ws += ks;
        ak = a[k]; g2 = a[k + 1]; aj = a[j]; aj1 = a[j + 1];
        x0r = aj - ak;
        g5 = aj1 + g2;
        t0r = aj + ak;
        t0i = aj1 - g2;
        wr = *wc;
        wi = *ws;
        g7 = wr * x0r;
        g2 = wr * g5;
        p1 = wi * x0r;
        p0 = wi * g5;
        g2 = g2 + p1;
        g7 = g7 - p0;
        g5 = t0r - g2;
        g8 = t0r + g2;
        g2 = t0i + g7;
        g7 = t0i - g7;
        a[j] = g5;
        a[k] = g8;
        a[j + 1] = g2;
        a[k + 1] = -g7;
    }
}
