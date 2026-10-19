/* gcc29 cc1 + ee-gcc2.96 gas. Passing m->0x870 as void* (not int) lets the scheduler put the buf[0]=4 store after the arg loads (it lands in the jal delay slot). */
#define F(p, o, T) (*(T *)((char *)(p) + (o)))
#define REG(a) (*(volatile unsigned int *)(a))
#define REGI(a) (*(volatile int *)(a))

typedef struct {
    volatile int cnt;
    int done;
    int rem;
    unsigned int addr;
    int total;
} DmaState;

extern int func_001098B0(int, DmaState *);
extern int AddDmacHandler2(int, int (*)(int, DmaState *), int, DmaState *);
extern int RemoveDmacHandler(int, int);
extern int EnableDmac(int);
extern int DisableDmac(int);
extern int DIntr(void);
extern void EIntr(void);
extern void func_0010B488(void*, int *);
extern void func_0010BD90(void *, const char *);

void func_001099F8(void *m, unsigned int addr, int n)
{
    int buf[8];
    DmaState s;
    int id;
    int old;
    int qwc = 0xFFC0;

    s.total = n / 1023 + 1;
    s.rem = n;
    s.addr = (addr + 0xFFC00) & 0x0FFFFFFF;
    s.done = 0;
    s.cnt = 0;
    while (REGI(0x10002010) < 0)
        ;
    id = AddDmacHandler2(3, func_001098B0, 0, &s);
    REG(0x1000E010) = 8;
    EnableDmac(3);
    old = DIntr();
    REG(0x1000B010) = addr & 0x0FFFFFFF;
    REG(0x1000B020) = qwc;
    REG(0x1000B000) = 0x100;
    if (old)
        EIntr();
    REG(0x10002000) = 0x700003FF;
    buf[0] = 4;
    func_0010B488(F(m, 0x870, void*), buf);
    while (s.cnt < s.total)
        ;
    if (s.done)
        func_0010BD90(m, "CSC handler error\n");
    while (REGI(0x10002010) < 0)
        ;
    DisableDmac(3);
    RemoveDmacHandler(3, id);
}