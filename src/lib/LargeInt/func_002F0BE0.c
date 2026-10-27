typedef struct { int w[32]; } B_002F0BE0;
extern void __assert(const char *, int, const char *);
extern unsigned int func_002F1C38(B_002F0BE0 *);
extern void MOD(B_002F0BE0 *, B_002F0BE0 *, B_002F0BE0 *);
extern int LargeInt_IsZero(B_002F0BE0 *);
extern void lintSetSmallValue(B_002F0BE0 *, int);
extern void XMOD(B_002F0BE0 *, B_002F0BE0 *, B_002F0BE0 *, B_002F0BE0 *);
extern char D_004AE090[];
extern char D_004AE0C0[];
void EMOD(B_002F0BE0 *out, B_002F0BE0 *base, B_002F0BE0 *exp, B_002F0BE0 *mod)
{
    B_002F0BE0 r;
    B_002F0BE0 t;
    unsigned int i;
    unsigned int n;
    unsigned int bit = 1;
    int k = 0;
    n = func_002F1C38(exp);
    MOD(&t, base, mod);
    if (LargeInt_IsZero(mod)) {
        __assert(D_004AE090, 0x297, D_004AE0C0);
        *out = *mod;
        return;
    }
    lintSetSmallValue(&r, 1);

    for (i = 0; i < n; i++) {
        if (i) {
            bit <<= 1;
            XMOD(&t, &t, &t, mod);
            if (!bit) {
                bit = 1;
                k++;
            }
        }
        if (bit & exp->w[k]) XMOD(&r, &r, &t, mod);
    }
    *out = r;
}



