extern unsigned int D_0048C450;
extern signed char D_0058C178[];
extern int func_002E51B8(unsigned int, char **);
extern void func_002DB188(unsigned char **, unsigned int, int);
int func_002DEE30(void)
{
    char *q = 0;
    unsigned char *p = 0;
    int r;
    int i;
    if (D_0048C450 >= 4) return -1;
    r = func_002E51B8(D_0048C450, &q);
    if (r) return r;
    if (q == 0) return r;
    func_002DB188(&p, D_0048C450, *(int *)(q + 0x400));
    if (p == 0) return -1;
    for (i = 0; i < *(unsigned short *)(p + 8); i++) {
        if (D_0058C178[i + *(unsigned short *)(p + 6)] != 2)
            return i + *(unsigned short *)(p + 6);
    }
    return -1;
}