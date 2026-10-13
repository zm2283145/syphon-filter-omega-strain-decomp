extern float D_004B5BE8[];

void func_0031F138(float *a, float g, float *c)
{
    int n, k;
    int p = 12;
    float sum;

    c[0] = g;
    for (n = 1; n <= p; n++) {
        sum = -(float)n * a[n];
        for (k = 1; k < n; k++)
            sum -= a[k] * c[n - k];
        c[n] = sum;
    }
    for (; n < 44; n++) {
        sum = 0.0f;
        for (k = 1; k <= 12; k++)
            sum -= a[k] * c[n - k];
        c[n] = sum;
    }
    for (n = 1; n < 44; n++)
        c[n] = D_004B5BE8[n] * c[n];
}

