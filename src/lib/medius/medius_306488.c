/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct { int sec; int usec; } ScfTime;
extern unsigned char D_00491300;
extern ScfTime D_00529828;
int __attribute__((weak, section(".dtors_drop"))) rt_time_initialize(void) { return 0; }
extern int rt_time_elapsed_timestamp(ScfTime *in, ScfTime *out);
int rt_time_get_base_diff(ScfTime *out)
{
    int ret = 2;
    if (out == 0) return ret;
    if (D_00491300 != 0) goto doit;
    ret = rt_time_initialize();
    if (ret != 0) return ret;
doit:
    ret = rt_time_elapsed_timestamp(&D_00529828, out);
    __asm__ __volatile__("");
    return ret;
}