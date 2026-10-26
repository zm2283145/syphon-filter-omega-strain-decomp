extern void iSignalSema(int a);
extern int D_00518A04;
void sceMc2SifCallback(void)
{
    iSignalSema(D_00518A04);
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
}