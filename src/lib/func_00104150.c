typedef struct { volatile int chcr; int p0[3]; volatile unsigned int madr; int p1[3]; volatile unsigned int qwc; int p2[3]; volatile unsigned int tadr; } DmaChan;
extern void func_00103BE8(DmaChan *);
extern unsigned int func_00103CE0(void *);
void func_00104150(DmaChan *d, void *addr, int qwc)
{
    unsigned int a = func_00103CE0(addr);
    int c;
    func_00103BE8(d);
    if (d->madr != 0xFFFFFFFF) d->madr = a;
    c = d->chcr;
    d->qwc = qwc;
    d->chcr = (c & ~0xC) | 0x109;
}
