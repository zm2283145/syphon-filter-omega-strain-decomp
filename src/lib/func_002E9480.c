extern void *memset(void *, int, unsigned int);
extern int func_00476998(void);
int func_002E9480(int *p)
{
    int v;
    if (p == 0) return 0x17;
    memset(p, 0, 0x1C);
    v = func_00476998();
    p[0] = 1;
    p[3] = 0xE4A;
    p[6] = 0;
    p[2] = 0;
    p[5] = 0;
    p[1] = v;
    return 0;
}