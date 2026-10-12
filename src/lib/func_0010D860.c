extern unsigned int D_00486194;
extern unsigned int func_0010D140(void);
extern int *func_00123320(void);
unsigned int func_0010D860(int incr)
{
    int s, v;
    unsigned int n, old;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) {
        do {
            __asm__ volatile("di");
            __asm__ volatile("sync.p");
            __asm__ volatile("mfc0 %0, $12" : "=r"(v));
        } while (v & 0x10000);
    }
    n = D_00486194 + incr;
    if (func_0010D140() < n) {
        *func_00123320() = 12;
        if (s) __asm__ volatile("ei");
        return -1;
    }
    old = D_00486194;
    D_00486194 = n;
    if (s) __asm__ volatile("ei");
    return old;
}
