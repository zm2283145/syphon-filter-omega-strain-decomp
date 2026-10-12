extern float D_004B5108[];

void func_0031AD68(float *a, int p, float *c, int n, float gain)
{
    int i, k, lim;
    float sum;

    c[0] = gain;
    n--;
    lim = (n < p) ? n : p;
    for (i = 1; i <= lim; i++) {
        sum = -(float)i * a[i];
        for (k = 1; k < i; k++)
            sum -= a[k] * c[i - k];
        c[i] = sum;
    }
    for (; i <= n; i++) {
        sum = 0;
        for (k = 1; k <= p; k++)
            sum -= a[k] * c[i - k];
        c[i] = sum;
    }
    for (i = 1; i <= n; i++)
        c[i] = D_004B5108[i] * c[i];
}
