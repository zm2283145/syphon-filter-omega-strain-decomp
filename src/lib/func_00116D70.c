extern int func_001161A0(void);
extern void func_001161F8(void);
extern void func_00116A80(unsigned int);

int func_00116D70(void)
{
    int s = func_001161A0();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (!(v & 0x80)) {
        if (s) func_001161F8();
        return 0;
    }
    func_00116A80(v & ~0xC80);
    if (s) func_001161F8();
    return 1;
}