extern unsigned int D_0048C450;
extern int func_002E51B8(unsigned int, char **);
extern int func_002DD9B0(char **, unsigned int);
int func_002E2B18(unsigned int id)
{
    char *q = 0;
    char *p = 0;
    int r;
    if (id >= 0x800) return 0x17;
    if (D_0048C450 >= 4) return 9;
    r = func_002E51B8(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return 0;
    if (func_002DD9B0(&q, id)) return 9;
    if (q == 0 || *(int *)(q + 0xC) != *(int *)(p + 0x400)) return 9;
    q[4] = 1;
    return 0;
}
