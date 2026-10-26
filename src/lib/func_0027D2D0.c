extern void iSignalSema(void);
void sce_cbfunc(void)
{
    iSignalSema();
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
}