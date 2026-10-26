typedef struct { int w[32]; } B_002F08D8;
extern void MODIP(B_002F08D8 *, B_002F08D8 *);
extern int LargeInt_IsZero(B_002F08D8 *);
void GCD(B_002F08D8 *out, B_002F08D8 *x, B_002F08D8 *y)
{
    B_002F08D8 a;
    B_002F08D8 b;
    a = *x;
    b = *y;
    for (;;) {
        MODIP(&a, &b);
        if (LargeInt_IsZero(&a)) {
            *out = b;
            return;
        }
        MODIP(&b, &a);
        if (LargeInt_IsZero(&b)) {
            *out = a;
            return;
        }
    }
}
