#define R(a) (*(volatile unsigned int *)(a))
extern int func_001161A0(void);
extern void func_001161F8(void);
extern void func_0010D4D0(volatile int *, volatile long *);
long func_0010D680(void)
{
    volatile int flag;
    volatile long ret;
    int s;
    flag = 0;
    func_0010D4D0(&flag, &ret);
    s = func_001161A0();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) func_001161F8();
    while (!(R(0x1000F000) & 4) && !flag)
        ;
    s = func_001161A0();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) func_001161F8();
    return ret;
}

