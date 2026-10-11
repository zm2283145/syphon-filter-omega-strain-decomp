extern int func_002FB3C0(int *);
int func_002F5348(int *p)
{
    if (p == 0) return 2;
    if (p[4]) func_002FB3C0(p + 4);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    return 0;
}