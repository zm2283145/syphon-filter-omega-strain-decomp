/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct { int sec; int usec; } ScfTime;
extern unsigned char D_00491300;
extern ScfTime D_00529828;
int __attribute__((weak, section(".dtors_drop"))) func_00306258(void) { return 0; }
extern int func_003064E0(ScfTime *in, ScfTime *out);
int func_00306488(ScfTime *out)
{
    int ret = 2;
    if (out == 0) return ret;
    if (D_00491300 != 0) goto doit;
    ret = func_00306258();
    if (ret != 0) return ret;
doit:
    ret = func_003064E0(&D_00529828, out);
    __asm__ __volatile__("");
    return ret;
}