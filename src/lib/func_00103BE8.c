typedef struct { volatile int chcr; } DmaChan3BE8;
extern char D_00498308[];
extern int func_0010F388(const char *, ...);
extern unsigned int func_00104380(DmaChan3BE8 *);

void func_00103BE8(DmaChan3BE8 *d)
{
    int cnt = 0x1000000;
    while (d->chcr & 0x100) {
        if (--cnt < 0) {
            func_0010F388(D_00498308);
            func_00104380(d);
        }
    }
}
