#define R(a) (*(volatile unsigned int*)(a))
extern int DIntr(void);
extern void EIntr(void);
void func_0010C6E8(unsigned int v)
{
    int s = DIntr();
    R(0x1000F590) = R(0x1000F520) | 0x10000;
    R(0x1000B000) = v;
    R(0x1000F590) = R(0x1000F520) & ~0x10000;
    if (s) EIntr();
}