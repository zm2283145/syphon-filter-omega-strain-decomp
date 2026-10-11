#define R(a) (*(volatile unsigned int*)(a))
extern int func_001161A0(void);
extern void func_001161F8(void);
void func_0010C6E8(unsigned int v)
{
    int s = func_001161A0();
    R(0x1000F590) = R(0x1000F520) | 0x10000;
    R(0x1000B000) = v;
    R(0x1000F590) = R(0x1000F520) & ~0x10000;
    if (s) func_001161F8();
}