typedef struct { int w[32]; } B_002F0BE0;
extern void __assert(const char *, int, const char *);
extern unsigned int func_002F1C38(B_002F0BE0 *);
extern void func_002F01E0(B_002F0BE0 *, B_002F0BE0 *, B_002F0BE0 *);
extern int func_002EFCD0(B_002F0BE0 *);
extern void func_002EFC00(B_002F0BE0 *, int);
extern void func_002F2958(B_002F0BE0 *, B_002F0BE0 *, B_002F0BE0 *, B_002F0BE0 *);
extern char D_004AE090[];
extern char D_004AE0C0[];
void func_002F0BE0(B_002F0BE0 *out, B_002F0BE0 *base, B_002F0BE0 *exp, B_002F0BE0 *mod)
{
    B_002F0BE0 r;
    B_002F0BE0 t;
    unsigned int i;
    unsigned int n;
    unsigned int bit = 1;
    int k = 0;
    n = func_002F1C38(exp);
    func_002F01E0(&t, base, mod);
    if (func_002EFCD0(mod)) {
        __assert(D_004AE090, 0x297, D_004AE0C0);
        *out = *mod;
        return;
    }
    func_002EFC00(&r, 1);

    for (i = 0; i < n; i++) {
        if (i) {
            bit <<= 1;
            func_002F2958(&t, &t, &t, mod);
            if (!bit) {
                bit = 1;
                k++;
            }
        }
        if (bit & exp->w[k]) func_002F2958(&r, &r, &t, mod);
    }
    *out = r;
}



