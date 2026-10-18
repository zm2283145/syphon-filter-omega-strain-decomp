extern float D_004B3968[];
extern float D_004E1C54;
extern void func_0031BB28(float* a, int n, int* outIdx, float* outVal);
void func_0031CDC0(float *x, int *pos, int *cnt, int *flag)
{
    int n = *cnt;
    int k = pos[n - 1];
    float t = D_004B3968[k];
    int st = *flag;
    int hit;
    float th, lim;
    int idx;
    float val;
    if (t <= 30.0f) {
        th = x[k] * D_004E1C54;
        lim = t + t;
        hit = 0;
        do
            k++;
        while (D_004B3968[k] < lim);
        if (x[k - 1] < th && x[k] < th)
            hit = 1;
        lim = t * 3.0f;
        do
            k++;
        while (D_004B3968[k] < lim);
        if (x[k - 1] < th && x[k] < th)
            hit = 1;
        if (hit == 1) {
            if (n == 1) {
                func_0031BB28(x + k, 74 - k, &idx, &val);
                *pos = idx + k;
            } else {
                n--;
                if (st == n)
                    st = 0;
            }
        }
    }
    *flag = st;
    *cnt = n;
}
