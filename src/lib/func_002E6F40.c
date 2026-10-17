typedef struct { int code; int val; } Msg;
typedef struct { int x0; unsigned short x4; unsigned short x6; } Arg;
extern unsigned char D_0048C454[];
extern int D_0048C478[];
extern int D_0058DF90;
extern void (*D_0058DF88)(Msg *);
extern int D_0058806C;
extern int func_002E51B8(unsigned int, char **);
extern void func_002DB188(char **, unsigned int, unsigned int);
extern int func_002E1A20(unsigned int);
extern int func_002E52D8(unsigned int, unsigned int, char **);
extern void func_002DCA70(unsigned int, int);
extern void func_002E5550(unsigned int, unsigned int);
extern void func_002DD2D8(int);
extern int func_002DB550(unsigned int, int);
extern int func_002DB688(unsigned int, unsigned int);
extern void func_002E1470(unsigned int, int);

int func_002E6F40(unsigned int a, int b, unsigned int c, Arg *d)
{
    char *q = 0;
    char *p = 0;
    char *r = 0;
    unsigned int n;
    Msg m;

    if (d == 0) return -1;
    if (a >= 4) return -1;
    if (c >= 0x100) return -1;
    if (D_0048C454[0] == 1) return 8;
    if (func_002E51B8(a, &p)) return -1;
    if (p == 0) return -1;
    n = *(unsigned int *)(p + 0x400);
    if (n >= 0x100) return -1;
    func_002DB188(&q, a, n);
    if (q == 0) return -1;
    if (D_0058DF90 == 1) {
        func_002E1A20(a);
        if (D_0058DF88) {
            m.code = 7;
            m.val = D_0048C478[0];
            D_0058DF88(&m);
            D_0058DF88 = 0;
            D_0048C478[0] = 0;
        }
        return 8;
    }
    if (func_002E52D8(a, n, &r) || r == 0) return -1;
    *(int *)(r + 0x14) = 4;
    func_002DCA70(a, -1);
    func_002E5550(a, c);
    D_0048C454[0] = 1;
    func_002DD2D8(d->x0);
    *(int *)q = D_0058806C;
    *(unsigned short *)(q + 6) = d->x4;
    *(unsigned short *)(q + 0xA) = d->x6;
    func_002DB550(a, -1);
    func_002DB688(a, n);
    func_002E1470(a, 1);
    return 8;
}