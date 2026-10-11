extern int func_002DD9F8(int, int *);
int func_002DD9B0(int *out, int a)
{
    int t = 0;
    int r = func_002DD9F8(a, &t);
    if (r) return r;
    if (t) *out = t;
    return 0;
}