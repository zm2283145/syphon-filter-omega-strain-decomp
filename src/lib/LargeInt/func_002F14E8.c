typedef struct { unsigned int w[32]; } B;
extern void __assert(const char *, int, const char *);
extern unsigned int func_002F1C38(B *);
extern int LargeInt_IsZero(B *);
/* weak never-linked stub (section discarded at link): steers reorg's delay-slot liveness like retail */
int __attribute__((weak, section(".dtors_drop"))) IsEven(B *p0) { return 0; }
/* weak never-linked stub (section discarded at link): steers reorg's delay-slot liveness like retail */
void __attribute__((weak, section(".dtors_drop"))) LargeInt_SetInt(B *p0, int p1) { }
/* weak never-linked stub (section discarded at link): steers reorg's delay-slot liveness like retail */
int __attribute__((weak, section(".dtors_drop"))) lintGetBit(B *p0, unsigned int p1) { return 0; }
extern void lintSetBit(B *, unsigned int);
extern void LargeInt_AddInt(B *, int);
extern void EMOD(B *, B *, B *, B *);
extern void TrimIP(B *, unsigned int);
extern int IsNotSmaller(B *, B *);
extern void ShiftRight(B *, unsigned int);
extern void ShiftLeft(B *, unsigned int);
extern void LargeInt_Add(B *, B *);
extern void lintAddIPR(B *, B *, unsigned int);
extern void LargeInt_Sub(B *, B *);
extern void lintSubIPR(B *, B *, unsigned int);
extern void MODIP(B *, B *);
extern void LargeInt_Mul(B *, B *, B *);
extern char D_004AE090[];
extern char D_004AE0C0[];

#define MONT(x, y) \
    LargeInt_Mul(&tmp, &x, &y); \
    x = tmp; \
    TrimIP(&x, n); \
    LargeInt_Mul(&x, &x, &c); \
    TrimIP(&x, n); \
    LargeInt_Mul(&x, &x, mod); \
    if (lintGetBit(&x, n - 1) || lintGetBit(&tmp, n - 1)) { \
        ShiftRight(&x, n); \
        ShiftRight(&tmp, n); \
        lintAddIPR(&x, &tmp, n); \
        LargeInt_AddInt(&x, 1); \
    } else { \
        ShiftRight(&x, n); \
        ShiftRight(&tmp, n); \
        lintAddIPR(&x, &tmp, n); \
    } \
    if (IsNotSmaller(&x, mod)) lintSubIPR(&x, mod, n);

void EMODM(B *out, B *base, B *exp, B *mod)
{
    B tmp;
    B t;
    B c;
    B r;
    unsigned int n;
    unsigned int bit;
    unsigned int ne;
    unsigned int i;
    unsigned int k;

    n = func_002F1C38(mod);
    ne = func_002F1C38(exp);
    if (LargeInt_IsZero(mod)) {
        __assert(D_004AE090, 0x3CF, D_004AE0C0);
        *out = *mod;
        return;
    }
    if (IsEven(mod)) {
        __assert(D_004AE090, 0x3D9, D_004AE0C0);
        EMOD(out, base, exp, mod);
        return;
    }
    k = 0;
    LargeInt_SetInt(&c, 0);
    i = 0;
    LargeInt_SetInt(&r, 1);
    while (i + k < n) {
        if (lintGetBit(&r, k)) {
            if (k) {
                i += k;
                ShiftRight(&r, k);
                k = 0;
            }
            lintSetBit(&c, i);
            lintAddIPR(&r, mod, n - i);
        } else {
            k++;
        }
    }
    t = *base;
    ShiftLeft(&t, n);
    MODIP(&t, mod);
    LargeInt_SetInt(&r, 1);
    k = 0;
    bit = 1;
    ShiftLeft(&r, n);
    MODIP(&r, mod);
    for (i = 0; i < ne; i++) {
        if (i) {
            MONT(t, t)
            bit <<= 1;
            if (!bit) {
                bit = 1;
                k++;
            }
        }
        if (bit & exp->w[k]) {
            MONT(r, t)
        }
    }
    tmp = r;
    TrimIP(&r, n);
    LargeInt_Mul(&r, &r, &c);
    TrimIP(&r, n);
    LargeInt_Mul(&r, &r, mod);
    LargeInt_Add(&r, &tmp);
    ShiftRight(&r, n);
    if (IsNotSmaller(&r, mod)) LargeInt_Sub(&r, mod);
    *out = r;
}
