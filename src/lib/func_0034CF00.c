extern int IopRing_Send(int a, void *b, int c, int d, int e, int g, int *h, int *err);
int func_0034CF00(int a, unsigned short v, int c, int *out, int *err)
{
    unsigned short s = v;
    int l4 = 0;
    int ret = 2;
    if (out == 0) return ret;
    *out = 0;
    if (c == 0) return ret;
    if (err == 0) return ret;
    if (a == 0) return ret;
    ret = IopRing_Send(a, &s, 2, 0, c, 0, &l4, err);
    if (l4 == 2) *out = 1;
    return ret;
}