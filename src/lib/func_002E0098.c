extern void *memset(void *, int, unsigned int);
extern unsigned short D_0058C0B0;
extern int func_00314430(int *);
int func_002E0098(int *p)
{
    int r;
    if (p == 0) return 0x17;
    memset(p, 0, 0x128);
    p[1] = 0x100;
    p[2] = 0;
    p[0x49] = D_0058C0B0 + 1;
    p[0x29] = 0;
    p[0x2B] = 0;
    p[0x2D] = 0;
    p[0x2F] = 0;
    p[0x31] = 0;
    p[0x32] = 0;
    r = func_00314430(p + 0x33);
    if (r) return r;
    p[0] = 1;
    return 0;
}
