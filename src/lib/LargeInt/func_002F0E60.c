typedef struct { unsigned int w[32]; } B;
extern int lintDecrement(B *, int);
extern int lintGetBit(B *, unsigned int);
extern void ShiftRight(B *, unsigned int);
extern void EMODM(B *, B *, B *, B *);
/* weak never-linked stub (section discarded at link): steers reorg's delay-slot liveness like retail */
int __attribute__((weak, section(".dtors_drop"))) LargeInt_IsOne(B *p0) { return 0; }
/* weak never-linked stub (section discarded at link): steers reorg's delay-slot liveness like retail */
int __attribute__((weak, section(".dtors_drop"))) IsEqual(B *p0, B *p1) { return 0; }
extern void LargeInt_MulMod(B *, B *, B *, B *);

int lintIsbSPRP(B *n, B *a)
{
    B m;
    B d;
    B y;
    unsigned int s;
    unsigned int j;

    m = *n;
    lintDecrement(&m, 1);
    d = m;
    s = 0;
    while (lintGetBit(&d, s) == 0) s++;
    if (s) ShiftRight(&d, s);
    EMODM(&y, a, &d, n);
    if (LargeInt_IsOne(&y) || IsEqual(&y, &m)) return 1;
    for (j = 1; j < s; j++) {
        LargeInt_MulMod(&y, &y, &y, n);
        if (IsEqual(&y, &m)) return 1;
        if (LargeInt_IsOne(&y)) return 0;
    }
    return 0;
}

