extern void iSignalSema(int a);
int func_0010E288(int a, int b, int c, int d)
{
    iSignalSema(d);
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
    return 0;
}