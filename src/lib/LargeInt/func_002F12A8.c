typedef struct { int w[32]; } B2F12A8;
extern void __assert(const char *, int, const char *);
extern void lintSetSmallValue(B2F12A8 *, int);
extern int IsOne(B2F12A8 *);
extern void lintSetBit(B2F12A8 *, int);
extern void lintIncrement(B2F12A8 *, int);
extern void MOD(B2F12A8 *, B2F12A8 *, B2F12A8 *);
extern void GCD(B2F12A8 *, B2F12A8 *, B2F12A8 *);
extern int lintIsbSPRP(B2F12A8 *, B2F12A8 *);
extern int LucasTest(B2F12A8 *, B2F12A8 *);
extern void lintRandomize(B2F12A8 *, int);
extern int func_002F1C38(B2F12A8 *);
extern B2F12A8 D_0048C4F0;
extern B2F12A8 D_0048C570;
extern int D_0048C5F0[];
extern char D_004AE090[];
extern char D_004AE0C8[];
void lintPrime(B2F12A8 *p, int bits)
{
    B2F12A8 t;
    int ok = 1;
    int n = 0;
    int i;
    int k = bits - 2;
    do {
        lintRandomize(p, bits);
        p->w[0] |= 1;
        if (bits != func_002F1C38(p)) __assert(D_004AE090, 0x360, D_004AE0C8);
        n++;
        lintSetBit(p, k);
        lintSetSmallValue(&t, 0xD2);
        MOD(&t, p, &t);
        lintIncrement(p, 0xD2 - t.w[0]);
        for (i = 0; n & 0x7F; ) {
            i++;
            lintIncrement(p, D_0048C5F0[i - 1]);
            ok = 0;
            GCD(&t, p, &D_0048C4F0);
            if (IsOne(&t)) {
                GCD(&t, p, &D_0048C570);
                ok = IsOne(&t) != 0;
            }
            if (ok) {
                lintSetSmallValue(&t, 2);
                ok = lintIsbSPRP(p, &t);
                if (ok) {
                    lintSetSmallValue(&t, 3);
                    ok = LucasTest(p, &t);
                    if (ok) return;
                }
            }
            if (D_0048C5F0[i] & 1) {
                lintIncrement(p, D_0048C5F0[i]);
                i = 0;
            }
            n++;
        }
    } while (!ok);
}






