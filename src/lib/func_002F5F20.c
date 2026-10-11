extern int func_002F6770(int, char **);
extern int func_002F7BC0(int, int, unsigned short, int, unsigned short, unsigned short *);
extern int func_002F6878(unsigned short, int, int);
int Socket_WriteAddressed(int a, int b, unsigned short c, int d, unsigned short e, unsigned short *out)
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
    r = func_002F7BC0(*(int *)(p + 4), b, c, d, e, out);
    if (r) return r;
    return func_002F6878(*out, 0, 0x1C);
}
