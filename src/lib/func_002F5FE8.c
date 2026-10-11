extern int func_002F6770(int, char **);
extern int func_002F7BE0(int, char *, int, unsigned short);
extern int func_002F6878(int, int, int);
int func_002F5FE8(int a, char *b, int c, unsigned short d)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    *b = 0;
    if (c == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 3) return 0xC;
    r = func_002F7BE0(*(int *)(p + 4), b, c, d);
    if (r) return r;
    return func_002F6878(0x1C, 0, 0);
}
