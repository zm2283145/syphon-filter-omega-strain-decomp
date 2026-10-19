/*
 * lib/libgraph: 6 files, 00104070-00104290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00104070 */
typedef struct { volatile int chcr; int p0[3]; volatile unsigned int madr; int p1[3]; volatile unsigned int qwc; int p2[3]; volatile unsigned int tadr; } DmaChan;
extern void sceDmaSync(DmaChan *);
extern unsigned int func_00103CE0(void *);
void sceDmaSend(DmaChan *d, void *tag)
{
    unsigned int a = func_00103CE0(tag);
    int c;
    sceDmaSync(d);
    if (d->tadr != 0xFFFFFFFF) d->tadr = a;
    c = d->chcr;
    d->qwc = 0;
    d->chcr = (c & ~0xC) | 0x105;
}
/* merge_units: end func_00104070 */

/* merge_units: begin func_001040D8 */
void sceDmaSendN(DmaChan *d, void *addr, int qwc)
{
    unsigned int a = func_00103CE0(addr);
    int c;
    sceDmaSync(d);
    if (d->madr != 0xFFFFFFFF) d->madr = a;
    c = d->chcr;
    d->qwc = qwc;
    d->chcr = (c & ~0xC) | 0x101;
}
/* merge_units: end func_001040D8 */

/* merge_units: begin func_00104150 */
void sceDmaSendI(DmaChan *d, void *addr, int qwc)
{
    unsigned int a = func_00103CE0(addr);
    int c;
    sceDmaSync(d);
    if (d->madr != 0xFFFFFFFF) d->madr = a;
    c = d->chcr;
    d->qwc = qwc;
    d->chcr = (c & ~0xC) | 0x109;
}
/* merge_units: end func_00104150 */

/* merge_units: begin func_001041C8 */
typedef struct { volatile int chcr; int p0[3]; volatile unsigned int madr; int p1[3]; volatile unsigned int qwc; } DmaChan41C8;
#if 0 /* merge_units */
extern void sceDmaSync(DmaChan41C8 *);
#endif /* merge_units */
#define sceDmaSync(a0) (sceDmaSync((DmaChan *)(a0))) /* merge_units */


void sceDmaRecv(DmaChan41C8 *d)
{
    int c;
    sceDmaSync(d);
    c = d->chcr;
    d->qwc = 0;
    d->chcr = (((c & ~0xC) | 4) & ~1) | 0x100;
}
#undef sceDmaSync /* merge_units */
/* merge_units: end func_001041C8 */

/* merge_units: begin func_00104210 */
void sceDmaRecvN(DmaChan *d, void *addr, int qwc)
{
    unsigned int a = func_00103CE0(addr);
    int c;
    sceDmaSync(d);
    if (d->madr != 0xFFFFFFFF) d->madr = a;
    c = d->chcr;
    d->qwc = qwc;
    c &= ~0xC;
    c &= ~1;
    c |= 0x100;
    d->chcr = c;
}
/* merge_units: end func_00104210 */

/* merge_units: begin func_00104290 */
void sceDmaRecvI(DmaChan *d, void *addr, int qwc)
{
    unsigned int a = func_00103CE0(addr);
    int c;
    sceDmaSync(d);
    if (d->madr != 0xFFFFFFFF) d->madr = a;
    c = d->chcr;
    d->qwc = qwc;
    d->chcr = (((c & ~0xC) | 8) & ~1) | 0x100;
}
/* merge_units: end func_00104290 */
