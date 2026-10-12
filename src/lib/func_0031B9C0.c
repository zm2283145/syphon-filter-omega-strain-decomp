void func_0031B9C0(float *data, int nn)
{
    int n = nn << 1;
    int i, j = 1, m;
    float t;
    for (i = 1; i < n; i += 2) {
        if (j > i) {
            t = data[j]; data[j] = data[i]; data[i] = t;
            t = data[j - 1]; data[j - 1] = data[i - 1]; data[i - 1] = t;
        }
        m = n >> 1;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
}
