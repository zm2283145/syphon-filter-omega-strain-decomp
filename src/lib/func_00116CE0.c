extern int func_001161A0(void);
extern void func_001161F8(void);
extern void func_00116A80(unsigned int);
extern int func_001172E0(void);
extern void func_00116DF0(int);

int func_00116CE0(void)
{
    int s = func_001161A0();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (v & 0x80) {
        if (s) func_001161F8();
        return 1;
    }
    func_00116A80((v & ~0xC00) | 0x80);
    func_00116DF0(func_001172E0());
    if (s) func_001161F8();
    return 0;
}