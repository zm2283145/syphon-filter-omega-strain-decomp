extern int func_002ED680(char *, int, int, int);
int func_002D9DD8(char *o, int a, int b)
{
    int r = func_002ED680(o, *(int *)(o + 0x64), a, b);
    if (*(int *)(o + 0x64) == 0) *(int *)(o + 0x64) = r;
    return r;
}