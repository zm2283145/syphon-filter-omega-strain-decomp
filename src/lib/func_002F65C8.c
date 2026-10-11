extern int func_002F6770(int, char **);
int func_002F65C8(int a, unsigned short *out)
{
    char *p = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    *out = *(unsigned short *)(p + 0x14);
    return 0;
}