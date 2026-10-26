#define F(p, o, T) (*(T *)((char *)(p) + (o)))
#define REG(a) (*(volatile unsigned int *)(a))
typedef struct { int type; int pad; long a; long b; } CbData;
extern void _waitIpuIdle(void *);
extern int _dispatchMpegCallback(void *, CbData *);
extern int DIntr(void);
extern void EIntr(void);
extern void func_0010BD90(void *, const char *);

int _waitBdecOut(void *m)
{
    CbData cb;
    CbData cb2;
    int ret = 1;
    unsigned int bp;
    long top;
    int oldintr;
    int n;

    _waitIpuIdle(m);
    while (REG(0x1000B020) && !(REG(0x10002010) & 0x4000)) {
        if (REG(0x1000B420) == 0 && !(REG(0x1000B400) & 0x100)) {
            cb.type = 1;
            _dispatchMpegCallback(F(m, 0x870, void *), &cb);
        }
        if (F(m, 0x10A0, int)) {
            oldintr = DIntr();
            REG(0x1000F590) = REG(0x1000F520) | 0x10000;
            REG(0x1000B400) = 0;
            REG(0x1000B000) = 0;
            *(unsigned int *)0x1000F590 = REG(0x1000F520) & ~0x10000;
            if (oldintr)
                EIntr();
            REG(0x1000B020) = 0;
            REG(0x1000B420) = 0;
            REG(0x10002010) = 0x40000000;
            return 0;
        }
    }
    bp = REG(0x10002020);
    top = *(long *)0x10002030;
    F(m, 0x850, int) = (int)top;
    if (top < 0) {
        if (bp & 0x1F)
            n = 32 - (bp & 0x1F);
        else
            n = 0;
    } else {
        n = 32;
    }
    F(m, 0x854, int) = n;
    if (REG(0x10002010) & 0x4000) {
        func_0010BD90(m, "Error code detected(BDEC)");
        cb2.type = 2;
        _dispatchMpegCallback(F(m, 0x870, void *), &cb2);
        *(unsigned int *)0x10002010 = 0x40000000;
        cb2.type = 3;
        _dispatchMpegCallback(F(m, 0x870, void *), &cb2);
        oldintr = DIntr();
        REG(0x1000F590) = REG(0x1000F520) | 0x10000;
        REG(0x1000B000) = 0;
        REG(0x1000F590) = REG(0x1000F520) & ~0x10000;
        if (oldintr)
            EIntr();
        ret = 0;
        REG(0x1000B020) = 0;
    }
    return ret;
}




