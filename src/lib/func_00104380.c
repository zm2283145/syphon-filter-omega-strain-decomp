extern int func_001161A0(void);
extern void func_001161F8(void);
unsigned int func_00104380(volatile unsigned int *p)
{
    int s = func_001161A0();
    unsigned int en = *(volatile unsigned int *)0x1000F520;
    unsigned int r;
    if (!(en & 0x10000)) *(volatile unsigned int *)0x1000F590 = en | 0x10000;
    *(volatile unsigned int *)0x1000E000;
    r = *p;
    *p = r & ~0x100;
    *(volatile unsigned int *)0x1000F590 = en;
    if (s) func_001161F8();
    return r;
}