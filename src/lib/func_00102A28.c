/* sceGsResetPath (libgraph). VIF1/VU1/GIF reset. cfc2/ctc2/sync/sync.p and lq/sq have no C spelling.
 * The final GIF_CTRL store goes through a materialized address and an empty volatile asm (emits no code)
 * so gcc fills the jr delay slot with it, as in retail (gcc never moves a volatile store into a delay slot). */
typedef unsigned int u_long128 __attribute__((mode(TI)));

static unsigned int D_00485EB0[8] __attribute__((aligned(16))) = {
    0x01000404, 0x20000000, 0x00000000, 0x05000000,
    0x06000000, 0x03000000, 0x02000000, 0x04000000
};

void sceGsResetPath(void)
{
    register int r asm("$4");

    *(volatile unsigned int *)0x10003C10 = 1;
    *(volatile unsigned int *)0x10003C20 = 2;
    r = 0;
    __asm__ volatile("sync");
    __asm__ volatile(".set noreorder\n\tcfc2.ni %0, $vi28\n\t.set reorder" : "+r"(r));
    r |= 0x200;
    __asm__ volatile("ctc2.ni %0, $vi28" : : "r"(r));
    __asm__ volatile("sync.p");
    *(volatile u_long128 *)0x10005000 = ((u_long128 *)D_00485EB0)[0];
    *(volatile u_long128 *)0x10005000 = ((u_long128 *)D_00485EB0)[1];
    { register unsigned int *p_ asm("$3") = (unsigned int *)0x10003000; __asm__ volatile("" : "=r"(p_) : "0"(p_)); *p_ = 1; }
}





