typedef struct { int w[32]; } B_002F0360;
extern unsigned int func_002F1C38(B_002F0360 *);
extern void LargeInt_SetInt(B_002F0360 *, int);
extern void ShiftLeft(B_002F0360 *, unsigned int);
extern void ShiftRight(B_002F0360 *, unsigned int);
extern int IsNotSmaller(B_002F0360 *, B_002F0360 *);
extern void LargeInt_Sub(B_002F0360 *, B_002F0360 *);
extern void lintSetBit(B_002F0360 *, unsigned int);
void QUO(B_002F0360 *out, B_002F0360 *x, B_002F0360 *y)
{
    B_002F0360 a;
    B_002F0360 b;
    B_002F0360 q;
    unsigned int na;
    unsigned int nb;
    unsigned int ny;
    a = *x;
    b = *y;
    na = func_002F1C38(&a);
    nb = func_002F1C38(&b);
    LargeInt_SetInt(&q, 0);
    ny = nb;
    if (nb < na) {
        ShiftLeft(&b, na - nb);
        nb = na;
    }
    while (na >= ny) {
        if (na < nb) {
            ShiftRight(&b, nb - na);
            nb = na;
        }
        if (IsNotSmaller(&a, &b)) {
            LargeInt_Sub(&a, &b);
            na = func_002F1C38(&a);
            lintSetBit(&q, nb - ny);
        } else if (ny < nb) {
            nb--;
            ShiftRight(&b, 1);
        } else {
            break;
        }
    }
    *out = q;
}