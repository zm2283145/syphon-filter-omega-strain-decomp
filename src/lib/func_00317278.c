extern float *D_004E1D5C;

void func_00317278(float *best, int n, float *x, int *y, float *pos, float step, float f, float end, float init)
{
    int i, v;
    float sum;
    float k = 4096.0f;
    for (; f <= end; f += step) {
        v = (int)(f * k + 0.5f);
        sum = init;
        for (i = 0; i < n; i++)
            sum += x[i] * D_004E1D5C[(unsigned)(v * y[i] + 0x800000) >> 24];
        if (*best < sum) { *best = sum; *pos = f; }
    }
}

