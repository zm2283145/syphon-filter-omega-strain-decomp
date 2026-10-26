extern int D_004878A4;
extern void (*D_004E9D08)(void *);
extern int D_004E9D0C;
extern void *D_004E9D10;
void _sceCd_Poff_Intr(void)
{
    void (*fn)(void *) = D_004E9D08;
    if (fn && D_004878A4 == 0) {
        register int sgp asm("$16");
        /* $gp cannot be named in C: save it, load the callback's gp, restore it after the call */
        __asm__ volatile ("move %0, $gp; lw $gp, %1" : "=r" (sgp) : "m" (D_004E9D0C));
        fn(D_004E9D10);
        __asm__ volatile ("move $gp, %0" : : "r" (sgp));
    }
}
