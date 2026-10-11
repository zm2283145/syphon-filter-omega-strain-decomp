extern int func_002E51B8(unsigned int, int *);
int func_002DDB30(int *out, unsigned int i)
{
    int p = 0;
    int r;
    if (i >= 4) return 0x17;
    if (out == 0) return 0x17;
    *out = 0x100;
    r = func_002E51B8(i, &p);
    if (r) return r;
    if (p) *out = *(int *)(p + 0x404);
    return 0;
}