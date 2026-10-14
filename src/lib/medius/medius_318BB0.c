extern const float D_004B3B58[];
extern const float D_004B3B60;
int func_00318BB0(float* a, int n, int i)
{
    int r = 0;
    n--;
    if (i < n) {
        if (i == 0 || D_004B3B58[0] * a[0] <= a[i]) {
            float* p = (float*)(i * 4 + (int)a); r = i; if (D_004B3B58[1] * *p <= a[n]) r = n;
        }
    } else if (D_004B3B60 * a[0] <= a[n]) {
        r = n;
    }
    return r;
}
