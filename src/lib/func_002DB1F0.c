extern int func_002E52D8(unsigned int, unsigned int, int *);
int func_002DB1F0(int *out, unsigned int a, unsigned int i)
{
    int t;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (i < 0x100 && a < 4) {
        t = 0;
        r = func_002E52D8(a, i, &t);
        if (t != 0 && r == 0) *out = ((int *)t)[5];
        return 0;
    }
    return 8;
}
