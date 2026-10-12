extern int D_0058806C;
extern void (*D_0058DF8C)(int *);
int D_0048C47C = 0;
extern int func_002E6088(int);
extern void func_002DB188(char **, unsigned int, int);
extern char *func_002DB270(unsigned int, int);
extern int func_002E52D8(unsigned int, int, char **);
extern void func_002DB470(char *);
extern void func_002DB550(unsigned int, int);
void func_002DB720(unsigned int a, int b)
{
    char *q = 0;
    char *e = 0;
    int t[4];
    int st = func_002E6088(b);
    if (st != 1) return;
    if (a >= 4) return;
    func_002DB188(&e, a, b);
    if (e == 0) e = func_002DB270(a, b);
    if (func_002E52D8(a, b, &q)) return;
    if (q == 0) return;
    *(int *)e = D_0058806C;
    q[0x29] = st;
    func_002DB470(e);
    if (D_0058DF8C) {
        t[0] = 0;
        t[1] = a;
        t[2] = b;
        t[3] = D_0048C47C;
        D_0058DF8C(t);
    }
    func_002DB550(a, b);
}
