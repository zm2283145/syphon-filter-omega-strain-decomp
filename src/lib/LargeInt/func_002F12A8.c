typedef struct { int w[32]; } B2F12A8;
extern void __assert(const char *, int, const char *);
extern void LargeInt_SetInt(B2F12A8 *, int);
extern int LargeInt_IsOne(B2F12A8 *);
extern void func_002EFDC8(B2F12A8 *, int);
extern void LargeInt_AddInt(B2F12A8 *, int);
extern void func_002F01E0(B2F12A8 *, B2F12A8 *, B2F12A8 *);
extern void func_002F08D8(B2F12A8 *, B2F12A8 *, B2F12A8 *);
extern int func_002F0E60(B2F12A8 *, B2F12A8 *);
extern int func_002F1058(B2F12A8 *, B2F12A8 *);
extern void func_002F11A8(B2F12A8 *, int);
extern int func_002F1C38(B2F12A8 *);
extern B2F12A8 D_0048C4F0;
extern B2F12A8 D_0048C570;
extern int D_0048C5F0[];
extern char D_004AE090[];
extern char D_004AE0C8[];
void func_002F12A8(B2F12A8 *p, int bits)
{
    B2F12A8 t;
    int ok = 1;
    int n = 0;
    int i;
    int k = bits - 2;
    do {
        func_002F11A8(p, bits);
        p->w[0] |= 1;
        if (bits != func_002F1C38(p)) __assert(D_004AE090, 0x360, D_004AE0C8);
        n++;
        func_002EFDC8(p, k);
        LargeInt_SetInt(&t, 0xD2);
        func_002F01E0(&t, p, &t);
        LargeInt_AddInt(p, 0xD2 - t.w[0]);
        for (i = 0; n & 0x7F; ) {
            i++;
            LargeInt_AddInt(p, D_0048C5F0[i - 1]);
            ok = 0;
            func_002F08D8(&t, p, &D_0048C4F0);
            if (LargeInt_IsOne(&t)) {
                func_002F08D8(&t, p, &D_0048C570);
                ok = LargeInt_IsOne(&t) != 0;
            }
            if (ok) {
                LargeInt_SetInt(&t, 2);
                ok = func_002F0E60(p, &t);
                if (ok) {
                    LargeInt_SetInt(&t, 3);
                    ok = func_002F1058(p, &t);
                    if (ok) return;
                }
            }
            if (D_0048C5F0[i] & 1) {
                LargeInt_AddInt(p, D_0048C5F0[i]);
                i = 0;
            }
            n++;
        }
    } while (!ok);
}






