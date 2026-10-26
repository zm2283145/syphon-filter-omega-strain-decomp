/*
 * lib/libgraph: 2 files, 00104648-00104660
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00104648 */
typedef int u_long128 __attribute__((mode(TI)));
typedef struct { u_long128 *p; int a, b; u_long128 *last; } QBuf;
void sceGifPkOpenGifTag(QBuf *b, u_long128 q) { b->last = b->p; *b->p++ = q; }
/* merge_units: end func_00104648 */

/* merge_units: begin func_00104660 */
typedef struct {
    unsigned long *cur;
    int pad4;
    int pad8;
    unsigned long *tag;
} Pkt4660;

void sceGifPkCloseGifTag(Pkt4660 *p)
{
    unsigned long *tag = p->tag;
    unsigned long *cur = p->cur;
    unsigned long t = *tag;
    unsigned int n = (cur - tag) - 2;
    unsigned long flg = (t >> 58) & 3;
    unsigned int *w;
    if (flg != 1) n >>= 1;
    if (flg != 2) {
        unsigned int nreg = t >> 60;
        if (nreg == 0) nreg = 16;
        n = (n + nreg - 1) / nreg;
    }
    p->tag = 0;
    *tag = t + n;
    w = (unsigned int *)cur;
    while ((unsigned int)w & 0xc) *w++ = 0;
    p->cur = (unsigned long *)w;
}
/* merge_units: end func_00104660 */
