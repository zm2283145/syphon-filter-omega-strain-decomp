#define F(p, o, T) (*(T *)((char *)(p) + (o)))
#define REG(a) (*(volatile unsigned int *)(a))
extern int func_001161A0(void);
extern void func_001161F8(void);
extern void func_0010B500(int);

long func_001078B0(void *m)
{
    long cmd;
    int count = 0;
    int oldintr;

    while ((cmd = *(volatile long *)0x10002000) < 0 && !(REG(0x10002010) & 0x4000)) {
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
            break;
        }
        if (count++ > 5000) {
            func_0010B500(F(m, 0x870, int));
            count = 0;
        }
    }
    return cmd;
}

