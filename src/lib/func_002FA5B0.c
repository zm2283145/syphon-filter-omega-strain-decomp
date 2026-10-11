extern int func_002FAF18(int *);
extern int func_002FAF48(int *);
int func_002FA5B0(int *p)
{
    int r;
    if (func_002FAF18(p) == 0) return 2;
    p[0] = 0;
    p[1] = 0;
    p[3] = 0;
    r = func_002FAF48(p);
    __asm__ __volatile__("");
    return r;
}