extern int func_002FB3C0(int *);
int func_002FB518(int *p)
{
    int r;
    if (p == 0) return 1;
    if (p[0]) {
        r = func_002FB3C0(p);
        if (r) return r;
        p[0] = 0;
    }
    p[1] = 0;
    return 0;
}