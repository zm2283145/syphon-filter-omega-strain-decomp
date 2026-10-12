extern int func_0010F388(const char *fmt, ...);
extern int func_002715D0(void *cd, unsigned int num, int mode, unsigned int bufsize, unsigned int stacksize, int prio);
extern char D_004BA6A0[];
typedef struct { char pad[0x24]; void *serve; } NetCd34B710;
int sceLibnetInitialize(NetCd34B710 *cd, unsigned int bufsize, unsigned int stacksize, int prio)
{
    int i;
    if (bufsize < 0x80)
        return -0x21F;
    if (bufsize != ((bufsize + 0x3F) & ~0x3F)) {
        func_0010F388(D_004BA6A0);
        return -0x21F;
    }
    for (;;) {
        if (func_002715D0(cd, 0x80001201, 0, bufsize, stacksize, prio) < 0)
            return -0x21C;
        if (cd->serve != 0)
            break;
        /* busy-wait delay: the nop is the loop body, C has no way to emit it */
        { int lim = -1; i = 0xffff; do { i -= 4; __asm__ volatile("nop"); } while (i != lim); }
    }
    return 0;
}