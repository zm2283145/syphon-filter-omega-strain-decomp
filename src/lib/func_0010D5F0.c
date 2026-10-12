#define R(a) (*(volatile unsigned int *)(a))
extern int func_001161A0(void);
extern void func_001161F8(void);
void func_0010D5F0(void)
{
    int s = func_001161A0();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) func_001161F8();
    while (!(R(0x1000F000) & 4))
        ;
    s = func_001161A0();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) func_001161F8();
}
