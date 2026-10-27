typedef struct { int w[32]; } B2F1058;
extern void lintDecrement(B2F1058 *, int);
extern int IsEven(B2F1058 *);
extern void ShiftRight(B2F1058 *, int);
extern void EMODM(B2F1058 *, int, B2F1058 *, B2F1058 *);
extern int IsOne(B2F1058 *);
extern void XMOD(B2F1058 *, B2F1058 *, B2F1058 *, B2F1058 *);
int LucasTest(B2F1058 *in, int arg)
{
    B2F1058 out;
    B2F1058 tmp;
    tmp = *in;
    lintDecrement(&tmp, 1);
    if (IsEven(&tmp)) {
        ShiftRight(&tmp, 1);
        EMODM(&out, arg, &tmp, in);
        if (IsOne(&out)) return 0;
        XMOD(&out, &out, &out, in);
        if (IsOne(&out)) return 1;
    }
    return 0;
}