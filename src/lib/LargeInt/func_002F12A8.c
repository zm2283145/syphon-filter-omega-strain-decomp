typedef struct { int w[32]; } B2F12A8;
extern void __assert(const char *, int, const char *);
extern void func_002EFC00(B2F12A8 *, int);
extern int func_002EFD08(B2F12A8 *);
extern void func_002EFDC8(B2F12A8 *, int);
extern void func_002EFE18(B2F12A8 *, int);
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
        func_002EFC00(&t, 0xD2);
        func_002F01E0(&t, p, &t);
        func_002EFE18(p, 0xD2 - t.w[0]);
        for (i = 0; n & 0x7F; ) {
            i++;
            func_002EFE18(p, D_0048C5F0[i - 1]);
            ok = 0;
            func_002F08D8(&t, p, &D_0048C4F0);
            if (func_002EFD08(&t)) {
                func_002F08D8(&t, p, &D_0048C570);
                ok = func_002EFD08(&t) != 0;
            }
            if (ok) {
                func_002EFC00(&t, 2);
                ok = func_002F0E60(p, &t);
                if (ok) {
                    func_002EFC00(&t, 3);
                    ok = func_002F1058(p, &t);
                    if (ok) return;
                }
            }
            if (D_0048C5F0[i] & 1) {
                func_002EFE18(p, D_0048C5F0[i]);
                i = 0;
            }
            n++;
        }
    } while (!ok);
}






