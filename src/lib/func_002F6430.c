extern int func_002F6770(int, char **);
extern int func_002F7CA0(int, int);
int func_002F6430(int a, int b)
{
    char *p = 0;
    int r, t;
    if (b == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    t = *(int *)(p + 8);
    if (t != 0 && t != 2) return 0xC;
    r = func_002F7CA0(*(int *)(p + 4), b);
    __asm__ __volatile__("");
    return r;
}