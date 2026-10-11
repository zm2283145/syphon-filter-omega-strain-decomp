typedef struct { volatile int chcr; int p0[3]; volatile unsigned int madr; int p1[3]; volatile unsigned int qwc; } DmaChan41C8;
extern void func_00103BE8(DmaChan41C8 *);

void func_001041C8(DmaChan41C8 *d)
{
    int c;
    func_00103BE8(d);
    c = d->chcr;
    d->qwc = 0;
    d->chcr = (((c & ~0xC) | 4) & ~1) | 0x100;
}