typedef struct { int a; int b; } Pair6338;
extern void * const D_004868C0[];
extern unsigned int D_004868B8;
extern void setup_void_2(int, int);
extern unsigned int FindAddress(unsigned int, unsigned int, void *);
extern void kFindAddress(void);
extern void kCopy_void_2(void);

void InitSystemCallTableAddress(void)
{
    unsigned int a, b, pa, pb;
    setup_void_2(((Pair6338*)D_004868C0)[0].a, ((Pair6338*)D_004868C0)[0].b);
    setup_void_2(((Pair6338*)D_004868C0)[1].a, ((Pair6338*)D_004868C0)[1].b);
    a = FindAddress(0x80000000, 0x80080000, kFindAddress);
    b = FindAddress(0x80000000, 0x80080000, kCopy_void_2);
    pa = a - 0x20C;
    pb = b - 0x168;
    while (pa != pb) {
        if (pa < pb) {
            a = FindAddress(a + 4, 0x80080000, kFindAddress);
            pa = a - 0x20C;
        } else {
            b = FindAddress(b + 4, 0x80080000, kCopy_void_2);
            pb = b - 0x168;
        }
    }
    D_004868B8 = pa;
}
void * const D_004868C0[4] = { (void*)0x83, (void*)kFindAddress, (void*)0x5A, (void*)kCopy_void_2 };
