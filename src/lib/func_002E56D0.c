extern int D_0048C4B0;
extern int func_002E51B8(unsigned int, char **);
extern int func_00302B88(int, int *);
int func_002E56D0(unsigned char *out)
{
    char *p = 0;
    int st = -2;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    r = func_002E51B8(0, &p);
    if (r) return r;
    if (p == 0) return 0;
    if (func_00302B88(D_0048C4B0, &st)) return 0x25;
    if (*(int *)(p + 0x400) != 0x100 && st == *(int *)(p + 0x400)) *out = 1;
    return 0;
}
