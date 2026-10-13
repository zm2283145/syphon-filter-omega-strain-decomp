/*
 * lib/RSA: 2 files, 002F4258-002F4638
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F4258 */
typedef struct { int w[32]; } LI2F4258;
typedef struct { char b[64]; } Key2F4258;
extern void __assert(const char *, int, const char *);
extern void func_002EFC00(LI2F4258 *, int);
extern int func_002EFCD0(LI2F4258 *);
extern int func_002EFD08(LI2F4258 *);
extern void func_002EFE18(LI2F4258 *, int);
extern void func_002F0060(LI2F4258 *, LI2F4258 *, LI2F4258 *);
extern void func_002F0670(LI2F4258 *, LI2F4258 *, LI2F4258 *, LI2F4258 *);
extern void func_002F12A8(LI2F4258 *, int);
extern int func_002F1CB8(LI2F4258 *, LI2F4258 *);
extern int func_002F1D2C(LI2F4258 *, LI2F4258 *);
extern void func_002F2124(LI2F4258 *, LI2F4258 *);
extern void func_002F2244(LI2F4258 *, LI2F4258 *);
extern void func_002F2790(LI2F4258 *, LI2F4258 *, LI2F4258 *);
extern void func_002F2958(LI2F4258 *, LI2F4258 *, LI2F4258 *, LI2F4258 *);
extern char D_004AEFD0[];
extern char D_004AEFF8[];

void func_002F4258(Key2F4258 *pub, Key2F4258 *priv)
{
    LI2F4258 p, q, d, e, r, phi;
    func_002EFC00(&d, 0);
    func_002F12A8(&p, 0x100);
    do {
        q = p;
        func_002F12A8(&p, 0x100);
        func_002F2790(&phi, &p, &q);
        *pub = *(Key2F4258 *)&phi;
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
    if (!func_002EFD08(&p)) __assert(D_004AEFD0, 0xA4, D_004AEFF8);
    *priv = *(Key2F4258 *)&d;
}
/* merge_units: end func_002F4258 */

/* merge_units: begin func_002F4638 */
typedef struct { int w[32]; } LI2F4638;
typedef struct { char b[64]; } Key2F4638;
#if 0 /* merge_units */
extern void func_002EFC00(LI2F4638 *, int);
#endif /* merge_units */
#define func_002EFC00(a0, a1) (func_002EFC00((LI2F4258 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_002EFCD0(LI2F4638 *);
#endif /* merge_units */
#define func_002EFCD0(a0) (func_002EFCD0((LI2F4258 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_002EFD08(LI2F4638 *);
#endif /* merge_units */
#define func_002EFD08(a0) (func_002EFD08((LI2F4258 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_002EFE18(LI2F4638 *, int);
#endif /* merge_units */
#define func_002EFE18(a0, a1) (func_002EFE18((LI2F4258 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_002F0060(LI2F4638 *, LI2F4638 *, LI2F4638 *);
#endif /* merge_units */
#define func_002F0060(a0, a1, a2) (func_002F0060((LI2F4258 *)(a0), (LI2F4258 *)(a1), (LI2F4258 *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void func_002F0670(LI2F4638 *, LI2F4638 *, LI2F4638 *, LI2F4638 *);
#endif /* merge_units */
#define func_002F0670(a0, a1, a2, a3) (func_002F0670((LI2F4258 *)(a0), (LI2F4258 *)(a1), (LI2F4258 *)(a2), (LI2F4258 *)(a3))) /* merge_units */

extern LI2F4638 func_002F34A0(void);
#if 0 /* merge_units */
extern int func_002F1CB8(LI2F4638 *, LI2F4638 *);
#endif /* merge_units */
#define func_002F1CB8(a0, a1) (func_002F1CB8((LI2F4258 *)(a0), (LI2F4258 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_002F1D2C(LI2F4638 *, LI2F4638 *);
#endif /* merge_units */
#define func_002F1D2C(a0, a1) (func_002F1D2C((LI2F4258 *)(a0), (LI2F4258 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_002F2124(LI2F4638 *, LI2F4638 *);
#endif /* merge_units */
#define func_002F2124(a0, a1) (func_002F2124((LI2F4258 *)(a0), (LI2F4258 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_002F2244(LI2F4638 *, LI2F4638 *);
#endif /* merge_units */
#define func_002F2244(a0, a1) (func_002F2244((LI2F4258 *)(a0), (LI2F4258 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_002F2790(LI2F4638 *, LI2F4638 *, LI2F4638 *);
#endif /* merge_units */
#define func_002F2790(a0, a1, a2) (func_002F2790((LI2F4258 *)(a0), (LI2F4258 *)(a1), (LI2F4258 *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void func_002F2958(LI2F4638 *, LI2F4638 *, LI2F4638 *, LI2F4638 *);
#endif /* merge_units */
#define func_002F2958(a0, a1, a2, a3) (func_002F2958((LI2F4258 *)(a0), (LI2F4258 *)(a1), (LI2F4258 *)(a2), (LI2F4258 *)(a3))) /* merge_units */


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
#undef func_002EFC00 /* merge_units */
#undef func_002EFCD0 /* merge_units */
#undef func_002EFD08 /* merge_units */
#undef func_002EFE18 /* merge_units */
#undef func_002F0060 /* merge_units */
#undef func_002F0670 /* merge_units */
#undef func_002F1CB8 /* merge_units */
#undef func_002F1D2C /* merge_units */
#undef func_002F2124 /* merge_units */
#undef func_002F2244 /* merge_units */
#undef func_002F2790 /* merge_units */
#undef func_002F2958 /* merge_units */
/* merge_units: end func_002F4638 */
