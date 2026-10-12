extern int func_00271780(void *cd, int mode);
int func_0034B7E8(void *cd)
{
    int r, i;
    for (;;) {
        r = func_00271780(cd, 0);
        if (r < 0) return -0x21C;
        if (r == 1) break;
        /* busy-wait delay: the nop is the loop body, C has no way to emit it */
        { int lim = -1; i = 0xffff; do { i -= 4; __asm__ volatile("nop"); } while (i != lim); }
    }
    return 0;
}
