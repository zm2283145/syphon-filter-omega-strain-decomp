void func_00322258(int total, int n, int factor, float *b, float *a, int lo)
{
    int j = total - 1;
    int i, k;
    for (i = n - 1; i >= lo; i--) {
        for (k = 0; k < factor; k++) {
            a[j] = a[i];
            b[j] = b[i];
            j--;
        }
    }
    for (; i >= 0; i--) {
        a[j] = a[i];
        b[j] = b[i];
        j--;
        for (k = 1; k < factor; k++) {
            a[j] = 0;
            b[j] = 0;
            j--;
        }
    }
}
