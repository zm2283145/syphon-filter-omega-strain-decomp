extern int func_0034CA38(int a, int b, int c, int *d, int e, int *g, int *h, int *err);
int func_0034CC60(int a, int b, int c, int *out, int *err)
{
    int l0;
    int l4;
    int l8;
    int ret = 2;
    l8 = 0;
    l0 = 0;
    if (out == 0) return ret;
    *out = 0;
    if (b == 0) return ret;
    if (c == 0) return ret;
    if (err == 0) return ret;
    *err = 0;
    if (a == 0) return ret;
    ret = func_0034CA38(a, b, 2, &l0, c, &l4, &l8, err);
    if (l8 == 2) *out = 1;
    return ret;
}