void func_00322738(float *re, float *im, int n)
{
    int i, j = n >> 1, k;
    float t;
    for (i = 1; i < n - 1; i++) {
        if (i > j) {
            t = re[i]; re[i] = re[j]; re[j] = t;
            t = im[i]; im[i] = im[j]; im[j] = t;
        }
        k = n;
        do {
            k >>= 1;
            j ^= k;
        } while (j < k);
    }
}
