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
extern void lintSetSmallValue(LargeInt *a, int v);
extern int LargeInt_IsZero(LargeInt *a);
extern int IsOne(LargeInt *a);
extern void lintIncrement(LargeInt *a, int v);                              /* a += v */
extern void lintSub(LargeInt *out, LargeInt *a, LargeInt *b);           /* out = a - b */
extern void QRMOD(LargeInt *x, LargeInt *y, LargeInt *q, LargeInt *r); /* q = x / y, r = x % y */
extern void lintPrime(LargeInt *p, int bits); /* makes a prime of `bits` bits (sieved with a small-prime table) */
extern int IsGreater(LargeInt *a, LargeInt *b);                         /* a > b */
extern int IsSmaller(LargeInt *a, LargeInt *b);                            /* a < b */
extern void lintAddIP(LargeInt *a, LargeInt *b);                            /* a += b */
extern void lintSubIP(LargeInt *a, LargeInt *b);                            /* a -= b */
extern void MULT(LargeInt *out, LargeInt *a, LargeInt *b);             /* out = a * b */
extern void XMOD(LargeInt *out, LargeInt *a, LargeInt *b, LargeInt *m); /* out = a * b % m */
extern char D_004AEFD0[]; /* "/usr/local/rel-1.50/rt_crypt/src/RSA.c" */
extern char D_004AEFF8[]; /* "0" */

/* merge_units: begin func_002F4258 */
void RSAGenerateKeyPair(RSAKey *pub, RSAKey *priv)
{
    LargeInt p, q, d, e, r, phi;
    lintSetSmallValue(&d, 0);
    lintPrime(&p, 0x100);
    do {
        q = p;
        lintPrime(&p, 0x100);
        MULT(&phi, &p, &q);
        *pub = *(RSAKey *)&phi;                 /* n = p * q */
        lintIncrement(&phi, 1);
        lintSubIP(&phi, &p);
        lintSubIP(&phi, &q);                 /* phi = n + 1 - p - q */
        /* q, d and e, r are reused as the Euclid coefficients / remainders */
        lintSetSmallValue(&q, 1);
        lintSetSmallValue(&e, RSA_PUBLIC_EXPONENT);
        QRMOD(&phi, &e, &d, &r);
        lintAddIP(&d, &q);
        lintSub(&r, &e, &r);
        for (;;) {
            if (IsGreater(&e, &r)) {
                if (IsSmaller(&q, &d)) lintAddIP(&q, &phi);
                lintSubIP(&q, &d);
                lintSubIP(&e, &r);
                if (IsOne(&e)) {
                    d = q;
                    break;
                }
            } else if (IsSmaller(&e, &r)) {
                if (IsSmaller(&d, &q)) lintAddIP(&d, &phi);
                lintSubIP(&d, &q);
                lintSubIP(&r, &e);
                if (IsOne(&r)) break;
            } else {
                lintSetSmallValue(&d, 0);         /* gcd(17, phi) != 1: no inverse */
                break;
            }
        }
    } while (LargeInt_IsZero(&d));
    lintSetSmallValue(&p, RSA_PUBLIC_EXPONENT);
    XMOD(&p, &d, &p, &phi);
    if (!IsOne(&p)) __assert(D_004AEFD0, 0xA4, D_004AEFF8); /* 17 * d == 1 (mod phi) */
    *priv = *(RSAKey *)&d;
}
/* merge_units: end func_002F4258 */

/* merge_units: begin func_002F4638 */
extern LargeInt lintPoolPrime(void); /* returns a prime by value (the other prime source) */

/* Same as RSAGenerateKeyPair, with the primes from lintPoolPrime. */
void RSAGenerateKeyPairEZ(RSAKey *pub, RSAKey *priv)
{
    LargeInt p, q, d, e, r, phi;
    lintSetSmallValue(&d, 0);
    p = lintPoolPrime();
    do {
        q = p;
        p = lintPoolPrime();
        MULT(&phi, &p, &q);
        *pub = *(RSAKey *)&phi;
        lintIncrement(&phi, 1);
        lintSubIP(&phi, &p);
        lintSubIP(&phi, &q);
        lintSetSmallValue(&q, 1);
        lintSetSmallValue(&e, RSA_PUBLIC_EXPONENT);
        QRMOD(&phi, &e, &d, &r);
        lintAddIP(&d, &q);
        lintSub(&r, &e, &r);
        for (;;) {
            if (IsGreater(&e, &r)) {
                if (IsSmaller(&q, &d)) lintAddIP(&q, &phi);
                lintSubIP(&q, &d);
                lintSubIP(&e, &r);
                if (IsOne(&e)) {
                    d = q;
                    break;
                }
            } else if (IsSmaller(&e, &r)) {
                if (IsSmaller(&d, &q)) lintAddIP(&d, &phi);
                lintSubIP(&d, &q);
                lintSubIP(&r, &e);
                if (IsOne(&r)) break;
            } else {
                lintSetSmallValue(&d, 0);
                break;
            }
        }
    } while (LargeInt_IsZero(&d));
    lintSetSmallValue(&p, RSA_PUBLIC_EXPONENT);
    XMOD(&p, &d, &p, &phi);
    if (!IsOne(&p)) __assert(D_004AEFD0, 0x125, D_004AEFF8);
    *priv = *(RSAKey *)&d;
}
/* merge_units: end func_002F4638 */
