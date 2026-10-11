extern int func_002F6770(int, char **);
int func_002F6568(int a, int *out)
{
    char *p = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    *out = (int)(p + 4);
    return 0;
}