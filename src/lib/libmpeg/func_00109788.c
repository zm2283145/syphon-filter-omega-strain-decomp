#define F(p, o, T) (*(T *)((char *)(p) + (o)))
#define REG(a) (*(volatile unsigned int *)(a))
#define REGI(a) (*(volatile int *)(a))
extern int DIntr(void);
extern void EIntr(void);
extern void func_00107718(void *, unsigned int);
extern void func_0010B488(int, int *);

void func_00109788(void *m, unsigned int addr, int n)
{
    int buf[8];
    int old;

    while (REGI(0x10002010) < 0)
        ;
    old = DIntr();
    REG(0x1000B010) = addr & 0x0FFFFFFF;
    REG(0x1000B020) = n << 6;
    REG(0x1000B000) = 0x100;
    if (old)
        EIntr();
    func_00107718(m, n | 0x70000000);
    buf[0] = 4;
    func_0010B488(F(m, 0x870, int), buf);
    while ((REG(0x1000B000) >> 8) & 1)
        ;
    while (REGI(0x10002010) < 0)
        ;
}
