extern int func_002E6088(int);
extern int func_002E52D8(unsigned int, int, unsigned char **);
int func_002E5CC0(unsigned int a, int b, int *out)
{
    unsigned char *p = 0;
    int r;
    if (a >= 4) return 0x17;
    if (func_002E6088(b) != 1) return 0x17;
    if (out == 0) return 0x17;
    *out = 0xFFFFFF;
    r = func_002E52D8(a, b, &p);
    if (r) return r;
    if (p == 0) return r;
    *out = p[0x28] != 0;
    return 0x1E;
}
