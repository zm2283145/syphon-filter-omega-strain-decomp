extern int D_004878C0;
extern void *D_004E9D08;
extern int D_004E9D0C;
extern void *D_004E9D10;
extern void func_00118948(void);
extern int func_001161A0(void);
extern void func_001161F8(void);
void *func_00118870(void *fn, void *arg)
{
    int s;
    void *old;
    if (D_004878C0 < 0) func_00118948();
    s = func_001161A0();
    old = D_004E9D08;
    D_004E9D10 = arg;
    D_004E9D08 = fn;
    /* $gp cannot be named in C: store it with one instruction, as retail does */
    __asm__ volatile ("sw $gp, %0" : "=m" (D_004E9D0C));
    if (s) func_001161F8();
    return old;
}
