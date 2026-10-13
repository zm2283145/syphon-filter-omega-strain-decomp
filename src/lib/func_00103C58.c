typedef struct { volatile int chcr; int p0[3]; volatile unsigned int madr; } DmaChan3C58;
extern char D_00498308[];
extern int scePrintf(const char *, ...);
extern unsigned int func_00104380(DmaChan3C58 *);

void func_00103C58(DmaChan3C58 *d, unsigned int a, int n)
{
    int cnt = n ? n : 0x1000000;
    while (d->madr < a) {
        if (--cnt < 0) {
            scePrintf(D_00498308);
            func_00104380(d);
        }
    }
}