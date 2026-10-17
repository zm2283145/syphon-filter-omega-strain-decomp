typedef struct { unsigned int w[32]; } B;
extern int func_002EFE68(B *, int);
extern int func_002EFDA0(B *, unsigned int);
extern void func_002F1EA0(B *, unsigned int);
extern void func_002F14E8(B *, B *, B *, B *);
/* weak never-linked stub (section discarded at link): steers reorg's delay-slot liveness like retail */
int __attribute__((weak, section(".dtors_drop"))) LargeInt_IsOne(B *p0) { return 0; }
/* weak never-linked stub (section discarded at link): steers reorg's delay-slot liveness like retail */
int __attribute__((weak, section(".dtors_drop"))) func_002EFD58(B *p0, B *p1) { return 0; }
extern void LargeInt_MulMod(B *, B *, B *, B *);

int func_002F0E60(B *n, B *a)
{
    B m;
    B d;
    B y;
    unsigned int s;
    unsigned int j;

    m = *n;
    func_002EFE68(&m, 1);
    d = m;
    s = 0;
    while (func_002EFDA0(&d, s) == 0) s++;
    if (s) func_002F1EA0(&d, s);
    func_002F14E8(&y, a, &d, n);
    if (LargeInt_IsOne(&y) || func_002EFD58(&y, &m)) return 1;
    for (j = 1; j < s; j++) {
        LargeInt_MulMod(&y, &y, &y, n);
        if (func_002EFD58(&y, &m)) return 1;
        if (LargeInt_IsOne(&y)) return 0;
    }
    return 0;
}

