extern unsigned int D_0048C450;
extern int func_002DD968(unsigned char **, unsigned int);
extern int func_002E51B8(unsigned int, char **);
extern int func_002DEBE0(unsigned int);
extern void func_002DEA68(unsigned int);
int func_002DEC60(unsigned int id)
{
    char *q = 0;
    unsigned char *p = 0;
    int r;
    if (id >= 0x1000) return 0x17;
    if (D_0048C450 >= 4) return 8;
    func_002DD968(&p, id);
    if (p == 0) return 8;
    r = func_002E51B8(D_0048C450, &q);
    if (r) return r;
    if (q == 0) return r;
    if (*(int *)(p + 8) == *(int *)(q + 0x400)) {
        func_002DEBE0(id);
        return 0;
    }
    func_002DEA68(id);
    return 0;
}
