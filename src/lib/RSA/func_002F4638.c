typedef struct { int w[32]; } LI2F4638;
typedef struct { char b[64]; } Key2F4638;
extern void __assert(const char *, int, const char *);
extern void func_002EFC00(LI2F4638 *, int);
extern int func_002EFCD0(LI2F4638 *);
extern int func_002EFD08(LI2F4638 *);
extern void func_002EFE18(LI2F4638 *, int);
extern void func_002F0060(LI2F4638 *, LI2F4638 *, LI2F4638 *);
extern void func_002F0670(LI2F4638 *, LI2F4638 *, LI2F4638 *, LI2F4638 *);
extern LI2F4638 func_002F34A0(void);
extern int func_002F1CB8(LI2F4638 *, LI2F4638 *);
extern int func_002F1D2C(LI2F4638 *, LI2F4638 *);
extern void func_002F2124(LI2F4638 *, LI2F4638 *);
extern void func_002F2244(LI2F4638 *, LI2F4638 *);
extern void func_002F2790(LI2F4638 *, LI2F4638 *, LI2F4638 *);
extern void func_002F2958(LI2F4638 *, LI2F4638 *, LI2F4638 *, LI2F4638 *);
extern char D_004AEFD0[];
extern char D_004AEFF8[];

void func_002F4638(Key2F4638 *pub, Key2F4638 *priv)
{
    LI2F4638 p, q, d, e, r, phi;
    func_002EFC00(&d, 0);
    p = func_002F34A0();
    do {
        q = p;
        p = func_002F34A0();
        func_002F2790(&phi, &p, &q);
        *pub = *(Key2F4638 *)&phi;
        func_002EFE18(&phi, 1);
        func_002F2244(&phi, &p);
        func_002F2244(&phi, &q);
        func_002EFC00(&q, 1);
        func_002EFC00(&e, 0x11);
        func_002F0670(&phi, &e, &d, &r);
        func_002F2124(&d, &q);
        func_002F0060(&r, &e, &r);
        for (;;) {
            if (func_002F1CB8(&e, &r)) {
                if (func_002F1D2C(&q, &d)) func_002F2124(&q, &phi);
                func_002F2244(&q, &d);
                func_002F2244(&e, &r);
                if (func_002EFD08(&e)) {
                    d = q;
                    break;
                }
            } else if (func_002F1D2C(&e, &r)) {
                if (func_002F1D2C(&d, &q)) func_002F2124(&d, &phi);
                func_002F2244(&d, &q);
                func_002F2244(&r, &e);
                if (func_002EFD08(&r)) break;
            } else {
                func_002EFC00(&d, 0);
                break;
            }
        }
    } while (func_002EFCD0(&d));
    func_002EFC00(&p, 0x11);
    func_002F2958(&p, &d, &p, &phi);
    if (!func_002EFD08(&p)) __assert(D_004AEFD0, 0x125, D_004AEFF8);
    *priv = *(Key2F4638 *)&d;
}
