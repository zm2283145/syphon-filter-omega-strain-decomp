extern int func_002E51B8(unsigned int, int *);
int func_002E5550(unsigned int a, int v)
{
    int p = 0;
    int r;
    if (a >= 4) return 8;
    r = func_002E51B8(a, &p);
    if (r) return r;
    if (p) *(int *)(p + 0x404) = v;
    return 0;
}