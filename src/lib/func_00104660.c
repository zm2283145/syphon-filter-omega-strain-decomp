typedef struct {
    unsigned long *cur;
    int pad4;
    int pad8;
    unsigned long *tag;
} Pkt4660;

void func_00104660(Pkt4660 *p)
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
