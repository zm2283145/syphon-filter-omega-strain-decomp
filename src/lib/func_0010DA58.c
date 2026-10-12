extern int func_001161A0(void);
extern int func_001161F8(void);
extern void func_0010D9B0(unsigned int, unsigned int);
void SyncDCache(unsigned int a, unsigned int b)
{
    int s;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) func_001161A0();
    func_0010D9B0(a & ~0x3F, b & ~0x3F);
    if (s) func_001161F8();
}
