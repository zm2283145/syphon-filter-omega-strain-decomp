extern int func_001161A0(void);
extern void func_001161F8(void);
void func_0010CA78(int x)
{
    int s = func_001161A0();
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000;
    *(volatile unsigned int *)0x1000B400 = x;
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 & ~0x10000;
    if (s) func_001161F8();
}