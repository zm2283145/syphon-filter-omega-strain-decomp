extern unsigned int D_0048C450;
extern int func_002E51B8(unsigned int, char **);
extern int func_002DD968(unsigned char **, unsigned int);
int func_002DCC08(unsigned short *out)
{
    char *p = 0;
    unsigned char *e = 0;
    unsigned int i = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (D_0048C450 == 4) return 0;
    if (D_0048C450 >= 4) return 8;
    r = func_002E51B8(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return r;
    if (*(unsigned int *)(p + 0x400) >= 0x100) return 8;
    for (; i < 0x1000; i++) {
        r = func_002DD968(&e, i);
        if (r) return r;
        if (e && (e[2] == 3 || e[2] == 4) && *(int *)(p + 0x400) == *(int *)(e + 8)) (*out)++;
    }
    return 0;
}
