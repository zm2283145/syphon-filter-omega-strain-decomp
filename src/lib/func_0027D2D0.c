extern void func_0010D190(void);
void func_0027D2D0(void)
{
    func_0010D190();
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
}