typedef struct { int w[32]; } B_002F0670;
extern unsigned int func_002F1C38(B_002F0670 *);
extern void LargeInt_SetInt(B_002F0670 *, int);
extern void ShiftLeft(B_002F0670 *, unsigned int);
extern void ShiftRight(B_002F0670 *, unsigned int);
extern int IsNotSmaller(B_002F0670 *, B_002F0670 *);
extern void LargeInt_Sub(B_002F0670 *, B_002F0670 *);
extern void lintSetBit(B_002F0670 *, unsigned int);
void LargeInt_DivMod(B_002F0670 *x, B_002F0670 *y, B_002F0670 *q, B_002F0670 *r)
{
    B_002F0670 b;
    unsigned int na;
    unsigned int nb;
    unsigned int ny;
    b = *y;
    *r = *x;
    na = func_002F1C38(r);
    nb = func_002F1C38(&b);
    LargeInt_SetInt(q, 0);
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
        if (IsNotSmaller(r, &b)) {
            LargeInt_Sub(r, &b);
            na = func_002F1C38(r);
            lintSetBit(q, nb - ny);
        } else if (ny < nb) {
            nb--;
            ShiftRight(&b, 1);
        } else {
            break;
        }
    }
}
