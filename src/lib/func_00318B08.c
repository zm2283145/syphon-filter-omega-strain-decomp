extern volatile float D_004E1BB8;
int func_00318B08(float *a, int n)
{
    int last = n - 1;
    int i;
    float sum = 0.0f;
    float acc;
    for (i = last; i >= 0; i--)
        sum += a[i];
    sum *= D_004E1BB8;
    acc = 0.0f;
    for (i = last; i >= 0; i--) {
        acc = a[i] + acc;
        if (sum <= acc) break;
    }
    i += 2;
    if (i < 76) i = 76;
    return i;
}
