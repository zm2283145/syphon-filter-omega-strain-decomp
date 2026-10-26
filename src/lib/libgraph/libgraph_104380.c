extern int DIntr(void);
extern void EIntr(void);
unsigned int sceDmaPause(volatile unsigned int *p)
{
    int s = DIntr();
    unsigned int en = *(volatile unsigned int *)0x1000F520;
    unsigned int r;
    if (!(en & 0x10000)) *(volatile unsigned int *)0x1000F590 = en | 0x10000;
    *(volatile unsigned int *)0x1000E000;
    r = *p;
    *p = r & ~0x100;
    *(volatile unsigned int *)0x1000F590 = en;
    if (s) EIntr();
    return r;
}