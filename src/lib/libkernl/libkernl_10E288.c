extern void iSignalSema(int a);
int _DelayThreadHandler(int a, int b, int c, int d)
{
    iSignalSema(d);
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
    return 0;
}