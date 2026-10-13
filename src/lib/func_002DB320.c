extern int *D_0051F0D0;
extern int func_002E6088(unsigned int);
extern void func_002DD328(int *);
void func_002DB320(unsigned int a, unsigned int i)
{
    if (func_002E6088(i) == 1 && a < 4 && i < 0x100) {
        func_002DD328(&D_0051F0D0[i]);
        /* barrier: retail keeps jal + epilogue, no tail call */
        __asm__ __volatile__("");
    }
}

