extern int func_001161A0(void);
extern void func_001161F8(void);

void func_00109700(unsigned int addr, int size)
{
    int s = func_001161A0();
    *(volatile unsigned int *)0x1000B010 = (addr & 0x0FFFFFFF) | 0x80000000;
    *(volatile int *)0x1000B020 = size >> 4;
    *(volatile int *)0x1000B000 = 0x100;
    if (s) func_001161F8();
}