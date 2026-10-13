typedef struct { unsigned int w[32]; } B;
extern void __assert(const char *, int, const char *);
extern unsigned int func_002F1C38(B *);
extern int LargeInt_IsZero(B *);
/* weak never-linked stub (section discarded at link): steers reorg's delay-slot liveness like retail */
int __attribute__((weak, section(".dtors_drop"))) func_002EFCC0(B *p0) { return 0; }
/* weak never-linked stub (section discarded at link): steers reorg's delay-slot liveness like retail */
void __attribute__((weak, section(".dtors_drop"))) LargeInt_SetInt(B *p0, int p1) { }
/* weak never-linked stub (section discarded at link): steers reorg's delay-slot liveness like retail */
int __attribute__((weak, section(".dtors_drop"))) func_002EFDA0(B *p0, unsigned int p1) { return 0; }
extern void func_002EFDC8(B *, unsigned int);
extern void LargeInt_AddInt(B *, int);
extern void func_002F0BE0(B *, B *, B *, B *);
extern void func_002F1480(B *, unsigned int);
extern int func_002F1E20(B *, B *);
extern void func_002F1EA0(B *, unsigned int);
extern void func_002F1FD8(B *, unsigned int);
extern void LargeInt_Add(B *, B *);
extern void func_002F21A8(B *, B *, unsigned int);
extern void LargeInt_Sub(B *, B *);
extern void func_002F22C8(B *, B *, unsigned int);
extern void func_002F2364(B *, B *);
extern void LargeInt_Mul(B *, B *, B *);
extern char D_004AE090[];
extern char D_004AE0C0[];

#define MONT(x, y) \
    LargeInt_Mul(&tmp, &x, &y); \
    x = tmp; \
    func_002F1480(&x, n); \
    LargeInt_Mul(&x, &x, &c); \
    func_002F1480(&x, n); \
    LargeInt_Mul(&x, &x, mod); \
    if (func_002EFDA0(&x, n - 1) || func_002EFDA0(&tmp, n - 1)) { \
        func_002F1EA0(&x, n); \
        func_002F1EA0(&tmp, n); \
        func_002F21A8(&x, &tmp, n); \
        LargeInt_AddInt(&x, 1); \
    } else { \
        func_002F1EA0(&x, n); \
        func_002F1EA0(&tmp, n); \
        func_002F21A8(&x, &tmp, n); \
    } \
    if (func_002F1E20(&x, mod)) func_002F22C8(&x, mod, n);

void func_002F14E8(B *out, B *base, B *exp, B *mod)
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
    if (func_002EFCC0(mod)) {
        __assert(D_004AE090, 0x3D9, D_004AE0C0);
        func_002F0BE0(out, base, exp, mod);
        return;
    }
    k = 0;
    LargeInt_SetInt(&c, 0);
    i = 0;
    LargeInt_SetInt(&r, 1);
    while (i + k < n) {
        if (func_002EFDA0(&r, k)) {
            if (k) {
                i += k;
                func_002F1EA0(&r, k);
                k = 0;
            }
            func_002EFDC8(&c, i);
            func_002F21A8(&r, mod, n - i);
        } else {
            k++;
        }
    }
    t = *base;
    func_002F1FD8(&t, n);
    func_002F2364(&t, mod);
    LargeInt_SetInt(&r, 1);
    k = 0;
    bit = 1;
    func_002F1FD8(&r, n);
    func_002F2364(&r, mod);
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
    func_002F1480(&r, n);
    LargeInt_Mul(&r, &r, &c);
    func_002F1480(&r, n);
    LargeInt_Mul(&r, &r, mod);
    LargeInt_Add(&r, &tmp);
    func_002F1EA0(&r, n);
    if (func_002F1E20(&r, mod)) LargeInt_Sub(&r, mod);
    *out = r;
}
