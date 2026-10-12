/* hex literals: this compiler's decimal float parsing is not exact */
static const float D_004B5108[44] = {
    1.0f, 0x1.715476p-1f, 0x1.715486p-2f, 0x1.ec7086p-3f, 0x1.715486p-3f, 0x1.27768p-3f,
    0x1.ec710cp-4f, 0x1.a617cp-4f, 0x1.7154p-4f, 0x1.484b5cp-4f, 0x1.277706p-4f, 0x1.0c9a76p-4f,
    0x1.ec7p-5f, 0x1.c68ec4p-5f, 0x1.a617cp-5f, 0x1.89f40ap-5f, 0x1.7154p-5f, 0x1.5b9a5ap-5f,
    0x1.484b5cp-5f, 0x1.370478p-5f, 0x1.2775fap-5f, 0x1.19652ap-5f, 0x1.0c9b84p-5f, 0x1.00ecfap-5f,
    0x1.ec7p-6f, 0x1.d8be72p-6f, 0x1.c68ec4p-6f, 0x1.b5bb38p-6f, 0x1.a615a8p-6f, 0x1.97891ep-6f,
    0x1.89f40ap-6f, 0x1.7d3d42p-6f, 0x1.7154p-6f, 0x1.66234ap-6f, 0x1.5b9a5ap-6f, 0x1.51ac9ap-6f,
    0x1.484944p-6f, 0x1.3f6c26p-6f, 0x1.370478p-6f, 0x1.2f09d8p-6f, 0x1.277814p-6f, 0x1.204294p-6f,
    0x1.19652ap-6f, 0x1.12dba4p-6f,
};

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
