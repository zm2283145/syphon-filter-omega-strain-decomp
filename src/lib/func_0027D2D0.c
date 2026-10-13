extern void iSignalSema(void);
void func_0027D2D0(void)
{
    iSignalSema();
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
}