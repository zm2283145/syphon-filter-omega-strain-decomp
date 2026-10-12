#define F(p, o, T) (*(T *)((char *)(p) + (o)))
#define REG(a) (*(volatile unsigned int *)(a))
extern int D_00485F48[];
extern int func_001161A0(void);
extern void func_001161F8(void);
extern void func_0010B500(int);

int func_00107A38(void *m, int type)
{
    int count2 = 0;
    int count = 0;
    int value;
    long cmd;
    unsigned int bp;
    long top;
    int oldintr;

    while ((REG(0x10002010) & 0x80004000) == 0x80000000 && !F(m, 0x10A0, int)) {
        if (count++ > 5000) {
            func_0010B500(F(m, 0x870, int));
            count = 0;
        }
    }
    value = (type << 26) | 0x30000000;
    REG(0x10002000) = value;
    F(m, 0x830, int) = D_00485F48[value >> 28];
    while ((cmd = *(volatile long *)0x10002000) < 0) {
        if (F(m, 0x10A0, int)) {
            oldintr = func_001161A0();
            REG(0x1000F590) = REG(0x1000F520) | 0x10000;
            REG(0x1000B400) = 0;
            REG(0x1000B000) = 0;
            *(unsigned int *)0x1000F590 = REG(0x1000F520) & ~0x10000;
            if (oldintr)
                func_001161F8();
            REG(0x1000B020) = 0;
            REG(0x1000B420) = 0;
            REG(0x10002010) = 0x40000000;
            return 0;
        }
        if (count2++ > 5000) {
            func_0010B500(F(m, 0x870, int));
            count2 = 0;
        }
    }
    bp = REG(0x10002020);
    top = *(long *)0x10002030;
    F(m, 0x850, int) = (int)top;
    if (top < 0)
        F(m, 0x854, int) = (32 - (bp & 0x1F)) & 0x1F;
    else
        F(m, 0x854, int) = 32;
    F(m, 0x134, int) = (int)cmd == 0;
    return (short)cmd;
}

