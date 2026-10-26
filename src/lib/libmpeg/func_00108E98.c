#define F(p, o, T) (*(T *)((char *)(p) + (o)))
#define REG(a) (*(volatile unsigned int *)(a))
extern int DIntr(void);
extern void EIntr(void);

void _cpr8(void *m, int *pic)
{
    int nf, k, i;
    unsigned int y = pic[0] & 0x0FFFFFFF;
    unsigned int c = F(m, 0xF0, unsigned int) & 0x0FFFFFFF;
    unsigned int cp;
    int ystride, ylen, cstride;
    int old;

    if (F(m, 0x18C, int) == 3 || F(m, 0xF8, int) == 0) {
        ystride = pic[4] * 0x180;
        ylen = ystride >> 4;
        if (F(m, 0xF8, int))
            cstride = (F(m, 0xF8, int) >> 4) * 0x180;
        else
            cstride = ystride;
        nf = 1;
    } else {
        cstride = (F(m, 0xF8, int) >> 4) * 0xC0;
        ystride = (pic[4] >> 1) * 0x180;
        ylen = ystride >> 4;
        nf = 2;
    }
    for (k = 0; k < nf; k++) {
        cp = c;
        for (i = 0; i < pic[3]; i++) {
            old = DIntr();
            REG(0x1000D480) = 0;
            REG(0x1000D410) = y;
            REG(0x1000D420) = ylen;
            REG(0x1000D400) = 0x101;
            if (old)
                EIntr();
            while (REG(0x1000D400) & 0x100)
                ;
            old = DIntr();
            REG(0x1000D080) = 0;
            REG(0x1000D010) = cp;
            REG(0x1000D020) = ylen;
            REG(0x1000D000) = 0x100;
            if (old)
                EIntr();
            while (REG(0x1000D000) & 0x100)
                ;
            while (REG(0x1000D020))
                ;
            cp += cstride;
            y += ystride;
        }
        c += F(m, 0xFC, int) * 0xC0;
    }
}


