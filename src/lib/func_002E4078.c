extern unsigned int D_0048C450;
extern int D_00590318[];
extern int D_005983F8;
extern int func_002E51B8(unsigned int, char **);
extern int func_002DD9B0(unsigned char **, unsigned int);
extern int func_002DDB30(int *, unsigned int);
extern void func_002DE880(int, unsigned int, int, int, int, unsigned char *);
void func_002E4078(int x, unsigned int id)
{
    unsigned char *e = 0;
    char *p = 0;
    int st;
    unsigned char b[1];
    if (id >= 0x1000) return;
    if (D_0048C450 >= 4) return;
    if (func_002E51B8(D_0048C450, &p)) return;
    if (p == 0) return;
    if (func_002DD9B0(&e, id)) return;
    if (p == 0) return;
    if (func_002DDB30(&st, D_0048C450)) return;
    if (st < 0) return;
    if (st >= 0x100) return;
    if (D_00590318[e[3]] && *(int *)(p + 0x400) != st && x == -1) x = st;
    b[0] = id;
    func_002DE880(0x50, D_0048C450, x, D_005983F8, 1, b);
}
