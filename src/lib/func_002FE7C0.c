extern void **D_004908F4;
extern unsigned short D_004908F0;
/* Weak stub of the same-file callee (section discarded at link): reproduces beqz vs beql. */
int __attribute__((weak, section(".dtors_drop"))) func_002FE720(void *o) { return 0; }

int func_002FE7C0(unsigned short i)
{
    int r;
    if (D_004908F4 == 0) return 0;
    if (i >= D_004908F0) return 0;
    r = func_002FE720(D_004908F4[i]);
    __asm__ __volatile__(""); /* stops the sibling-call optimisation */
    return r;
}
