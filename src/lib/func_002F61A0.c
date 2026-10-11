extern int func_002F6770(int, char **);
extern int func_002F7C10(int, int, int, int, unsigned short, unsigned short *);
extern int func_002F6878(int, unsigned short, int);
int func_002F61A0(int a, int b, int c, int d, unsigned short e, unsigned short *out)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (d == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 1) return 0xC;
    r = func_002F7C10(*(int *)(p + 4), b, c, d, e, out);
    if (r) return r;
    return func_002F6878(0, *out, 0x1C);
}
