extern int func_0034B230(void *cd, int *buf, void *dst, int n);
extern int func_0034B2C0(void *cd, int *buf, int a, int b, void *data, int len);
int func_0034B9E8(void *cd, int *buf, int *out)
{
    int list[256];
    int st;
    int n, i;
    n = func_0034B230(cd, buf, list, 256);
    if (n < 0) return -1;
    if (n == 0) return -2;
    for (i = 0; i < n; i++) {
        if (func_0034B2C0(cd, buf, list[i], 8, &st, 4) < 0) return -1;
        if (st & 2) break;
    }
    if (i == n) return -2;
    *out = list[i];
    return 0;
}