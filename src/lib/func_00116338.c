typedef struct { int a; int b; } Pair6338;
extern Pair6338 D_004868C0[];
extern unsigned int D_004868B8;
extern void func_00116438(int, int);
extern unsigned int func_001162F0(unsigned int, unsigned int, void *);
extern void func_001162B0(void);
extern void func_00116278(void);

void func_00116338(void)
{
    unsigned int a, b, pa, pb;
    func_00116438(D_004868C0[0].a, D_004868C0[0].b);
    func_00116438(D_004868C0[1].a, D_004868C0[1].b);
    a = func_001162F0(0x80000000, 0x80080000, func_001162B0);
    b = func_001162F0(0x80000000, 0x80080000, func_00116278);
    pa = a - 0x20C;
    pb = b - 0x168;
    while (pa != pb) {
        if (pa < pb) {
            a = func_001162F0(a + 4, 0x80080000, func_001162B0);
            pa = a - 0x20C;
        } else {
            b = func_001162F0(b + 4, 0x80080000, func_00116278);
            pb = b - 0x168;
        }
    }
    D_004868B8 = pa;
}