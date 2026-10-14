void func_0031A2D0(float *r, int p, float *a, float *k, float *err)
{
    float tmp[20];
    float *prev;
    float *t;
    float e;
    float acc;
    float km;
    int i;
    int j;
    int m;

    e = r[0];
    if (e == 0.0f)
        e = 0x1.1039d4p-123f;
    prev = a;
    if (p & 1)
        a = tmp;
    else
        prev = tmp;
    prev[0] = 1.0f;
    a[0] = 1.0f;
    for (i = 0; i < p; i++) {
        acc = 0.0f;
        for (j = 0; j <= i; j++)
            acc += a[j] * r[i + 1 - j];
        km = acc / e;
        if (km > 0x1.fff2e4p-1f)
            km = 0x1.fff2e4p-1f;
        if (km < -0x1.fff2e4p-1f)
            km = -0x1.fff2e4p-1f;
        t = a;
        a = prev;
        prev = t;
        *k++ = km;
        a[i + 1] = -km;
        for (m = 1; m <= i; m++)
            a[m] = t[m] - km * t[i + 1 - m];
        e *= 1.0f - km * km;
    }
    *err = e;
}
