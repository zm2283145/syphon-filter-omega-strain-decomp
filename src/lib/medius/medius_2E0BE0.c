extern void *memset(void *, int, unsigned int);
extern int func_00314430(int *);
int func_002E0BE0(int *p)
{
    int r;
    if (p == 0) return 0x17;
    memset(p, 0, 0x78);
    p[1] = 0;
    p[3] = 0;
    p[7] = 8;
    p[5] = 0;
    r = func_00314430(p + 8);
    if (r) return r;
    p[0] = 1;
    return 0;
}