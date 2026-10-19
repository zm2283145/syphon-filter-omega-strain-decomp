extern int DIntr(void);
extern void EIntr(void);

void func_00109700(unsigned int addr, int size)
{
    int s = DIntr();
    *(volatile unsigned int *)0x1000B010 = (addr & 0x0FFFFFFF) | 0x80000000;
    *(volatile int *)0x1000B020 = size >> 4;
    *(volatile int *)0x1000B000 = 0x100;
    if (s) EIntr();
}