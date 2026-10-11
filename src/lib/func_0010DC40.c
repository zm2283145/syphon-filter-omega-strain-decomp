extern int func_001161A0(void);
extern int func_001161F8(void);
extern int func_0010CEB0(int);
int Alloc_Lock(int a)
{
    int s, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) func_001161A0();
    r = func_0010CEB0(a);
    __asm__ volatile("sync");
    if (s) func_001161F8();
    return r;
}