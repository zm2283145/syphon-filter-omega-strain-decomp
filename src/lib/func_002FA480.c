extern int func_0010CE60(int, int);
int func_002FA480(int a, int b, int *c)
{
    if (b >= 0) {
        int n = func_0010CE60(a, b);
        if (n > 0) *c += n;
    }
    return 0;
}