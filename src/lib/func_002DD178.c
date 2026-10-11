extern int D_0048C458;
extern int func_002E51B8(unsigned int, char **);
int func_002DD178(int *out, unsigned int idx)
{
    char *p = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0x100;
    if (D_0048C458 == 0) return 0x11;
    if (idx >= 4) return 0x17;
    r = func_002E51B8(idx, &p);
    if (r) return r;
    if (p == 0) return r;
    *out = *(int *)(p + 0x400);
    return r;
}
