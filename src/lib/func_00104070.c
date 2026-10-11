typedef struct { volatile int chcr; int p0[3]; volatile unsigned int madr; int p1[3]; volatile unsigned int qwc; int p2[3]; volatile unsigned int tadr; } DmaChan;
extern void func_00103BE8(DmaChan *);
extern unsigned int func_00103CE0(void *);
void func_00104070(DmaChan *d, void *tag)
{
    unsigned int a = func_00103CE0(tag);
    int c;
    func_00103BE8(d);
    if (d->tadr != 0xFFFFFFFF) d->tadr = a;
    c = d->chcr;
    d->qwc = 0;
    d->chcr = (c & ~0xC) | 0x105;
}
