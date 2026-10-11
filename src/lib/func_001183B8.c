extern int func_00118F00(int);
extern int func_001161A0(void);
extern void func_001161F8(void);
extern void *D_004E9D00;
extern int volatile D_004E9D04;

void *func_001183B8(void *fn)
{
    register int gp __asm__("$28");
    int s;
    void *old;
    if (func_00118F00(1)) return 0;
    s = func_001161A0();
    old = D_004E9D00;
    D_004E9D00 = fn;
    D_004E9D04 = gp;
    if (s) func_001161F8();
    return old;
}