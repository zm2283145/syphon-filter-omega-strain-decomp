extern int D_004878C0;
extern void *D_004E9D08;
extern int D_004E9D0C;
extern void *D_004E9D10;
extern void PowerOffCB(void);
extern int DIntr(void);
extern void EIntr(void);
void *sceCdPOffCallback(void *fn, void *arg)
{
    int s;
    void *old;
    if (D_004878C0 < 0) PowerOffCB();
    s = DIntr();
    old = D_004E9D08;
    D_004E9D10 = arg;
    D_004E9D08 = fn;
    /* $gp cannot be named in C: store it with one instruction, as retail does */
    __asm__ volatile ("sw $gp, %0" : "=m" (D_004E9D0C));
    if (s) EIntr();
    return old;
}
