/*
 * lib/RSA: 2 files, 002F4258-002F4638
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 *
 * rt_crypt RSA key generation ("/usr/local/rel-1.50/rt_crypt/src/RSA.c").
 * Both functions pick two 256-bit primes p and q, store n = p * q as the public
 * key, and compute the private exponent d = 17^-1 mod (p-1)(q-1) with a
 * subtractive extended Euclid; they retry with new primes until d exists.
 */

typedef struct LargeInt { int w[32]; } LargeInt; /* little-endian words */
typedef struct RSAKey { char b[64]; } RSAKey;    /* low 512 bits of a LargeInt */

#define RSA_PUBLIC_EXPONENT 17

extern void __assert(const char *file, int line, const char *expr);
extern void LargeInt_SetInt(LargeInt *a, int v);
extern int LargeInt_IsZero(LargeInt *a);
extern int LargeInt_IsOne(LargeInt *a);
extern void LargeInt_AddInt(LargeInt *a, int v);                              /* a += v */
extern void LargeInt_Sub3(LargeInt *out, LargeInt *a, LargeInt *b);           /* out = a - b */
extern void LargeInt_DivMod(LargeInt *x, LargeInt *y, LargeInt *q, LargeInt *r); /* q = x / y, r = x % y */
extern void func_002F12A8(LargeInt *p, int bits); /* makes a prime of `bits` bits (sieved with a small-prime table) */
extern int LargeInt_Greater(LargeInt *a, LargeInt *b);                         /* a > b */
extern int LargeInt_Less(LargeInt *a, LargeInt *b);                            /* a < b */
extern void LargeInt_Add(LargeInt *a, LargeInt *b);                            /* a += b */
extern void LargeInt_Sub(LargeInt *a, LargeInt *b);                            /* a -= b */
extern void LargeInt_Mul(LargeInt *out, LargeInt *a, LargeInt *b);             /* out = a * b */
extern void LargeInt_MulMod(LargeInt *out, LargeInt *a, LargeInt *b, LargeInt *m); /* out = a * b % m */
extern char D_004AEFD0[]; /* "/usr/local/rel-1.50/rt_crypt/src/RSA.c" */
extern char D_004AEFF8[]; /* "0" */

/* merge_units: begin func_002F4258 */
void RSA_GenerateKeyPair(RSAKey *pub, RSAKey *priv)
{
    LargeInt p, q, d, e, r, phi;
    LargeInt_SetInt(&d, 0);
    func_002F12A8(&p, 0x100);
    do {
        q = p;
        func_002F12A8(&p, 0x100);
        LargeInt_Mul(&phi, &p, &q);
        *pub = *(RSAKey *)&phi;                 /* n = p * q */
        LargeInt_AddInt(&phi, 1);
        LargeInt_Sub(&phi, &p);
        LargeInt_Sub(&phi, &q);                 /* phi = n + 1 - p - q */
        /* q, d and e, r are reused as the Euclid coefficients / remainders */
        LargeInt_SetInt(&q, 1);
        LargeInt_SetInt(&e, RSA_PUBLIC_EXPONENT);
        LargeInt_DivMod(&phi, &e, &d, &r);
        LargeInt_Add(&d, &q);
        LargeInt_Sub3(&r, &e, &r);
        for (;;) {
            if (LargeInt_Greater(&e, &r)) {
                if (LargeInt_Less(&q, &d)) LargeInt_Add(&q, &phi);
                LargeInt_Sub(&q, &d);
                LargeInt_Sub(&e, &r);
                if (LargeInt_IsOne(&e)) {
                    d = q;
                    break;
                }
            } else if (LargeInt_Less(&e, &r)) {
                if (LargeInt_Less(&d, &q)) LargeInt_Add(&d, &phi);
                LargeInt_Sub(&d, &q);
                LargeInt_Sub(&r, &e);
                if (LargeInt_IsOne(&r)) break;
            } else {
                LargeInt_SetInt(&d, 0);         /* gcd(17, phi) != 1: no inverse */
                break;
            }
        }
    } while (LargeInt_IsZero(&d));
    LargeInt_SetInt(&p, RSA_PUBLIC_EXPONENT);
    LargeInt_MulMod(&p, &d, &p, &phi);
    if (!LargeInt_IsOne(&p)) __assert(D_004AEFD0, 0xA4, D_004AEFF8); /* 17 * d == 1 (mod phi) */
    *priv = *(RSAKey *)&d;
}
/* merge_units: end func_002F4258 */

/* merge_units: begin func_002F4638 */
extern LargeInt func_002F34A0(void); /* returns a prime by value (the other prime source) */

/* Same as RSA_GenerateKeyPair, with the primes from func_002F34A0. */
void RSA_GenerateKeyPair2(RSAKey *pub, RSAKey *priv)
{
    LargeInt p, q, d, e, r, phi;
    LargeInt_SetInt(&d, 0);
    p = func_002F34A0();
    do {
        q = p;
        p = func_002F34A0();
        LargeInt_Mul(&phi, &p, &q);
        *pub = *(RSAKey *)&phi;
        LargeInt_AddInt(&phi, 1);
        LargeInt_Sub(&phi, &p);
        LargeInt_Sub(&phi, &q);
        LargeInt_SetInt(&q, 1);
        LargeInt_SetInt(&e, RSA_PUBLIC_EXPONENT);
        LargeInt_DivMod(&phi, &e, &d, &r);
        LargeInt_Add(&d, &q);
        LargeInt_Sub3(&r, &e, &r);
        for (;;) {
            if (LargeInt_Greater(&e, &r)) {
                if (LargeInt_Less(&q, &d)) LargeInt_Add(&q, &phi);
                LargeInt_Sub(&q, &d);
                LargeInt_Sub(&e, &r);
                if (LargeInt_IsOne(&e)) {
                    d = q;
                    break;
                }
            } else if (LargeInt_Less(&e, &r)) {
                if (LargeInt_Less(&d, &q)) LargeInt_Add(&d, &phi);
                LargeInt_Sub(&d, &q);
                LargeInt_Sub(&r, &e);
                if (LargeInt_IsOne(&r)) break;
            } else {
                LargeInt_SetInt(&d, 0);
                break;
            }
        }
    } while (LargeInt_IsZero(&d));
    LargeInt_SetInt(&p, RSA_PUBLIC_EXPONENT);
    LargeInt_MulMod(&p, &d, &p, &phi);
    if (!LargeInt_IsOne(&p)) __assert(D_004AEFD0, 0x125, D_004AEFF8);
    *priv = *(RSAKey *)&d;
}
/* merge_units: end func_002F4638 */
