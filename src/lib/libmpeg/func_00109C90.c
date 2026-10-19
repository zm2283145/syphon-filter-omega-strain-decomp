#define F(p, o, T) (*(T *)((char *)(p) + (o)))
#define REG(a) (*(volatile unsigned int *)(a))
#define REGI(a) (*(volatile int *)(a))

typedef struct {
    unsigned int cnt;
    unsigned int addr;
} DmaChunk;

typedef struct {
    unsigned int addr;
    int x4;
    int x8;
    int w;
    int h;
} PicC90;

extern int DIntr(void);
extern void EIntr(void);
extern void func_00107718(void *, unsigned int);
extern void func_0010B488(int, int *);
extern void func_00109788(void *, unsigned int, int);
extern void func_001099F8(void *, unsigned int, int);
extern int func_00109BB8(int, DmaChunk *);
extern int AddDmacHandler2(int, int (*)(int, DmaChunk *), int, DmaChunk *);
extern void RemoveDmacHandler(int, int);
extern void DisableDmac(int);
extern void EnableDmac(int);

/* IPU input DMA (toIPU, ch4) of a picture buffer; large transfers are chained by the func_00109BB8 handler. */

void func_00109C90(void *m, PicC90 *p)
{
    int buf[8];
    DmaChunk s;
    int n;
    int id;
    int old;

    n = p->w * p->h;
    buf[0] = 2;
    func_0010B488(F(m, 0x870, int), buf);
    {
        register unsigned int c asm("$2") = REG(0x10002010);
        if (c & 0x4000)
            REG(0x10002010) = 0x40000000;
    }
    while (REGI(0x10002010) < 0)
        ;
    func_00107718(m, 0);
    while (REGI(0x10002010) < 0)
        ;
    s.addr = p->addr & 0x0FFFFFFF;
    s.cnt = n * 0x18;
    if (s.cnt > 0xFFFF) {
        id = AddDmacHandler2(4, func_00109BB8, 0, &s);
        {
            unsigned int base = 0x10000000, v = 0x10; int ch = 4;
            /* Materialize the DMAC base, value and channel before the store. */
            __asm__ volatile("" : "+r"(base), "+r"(v), "+r"(ch));
            *(unsigned int *)(base | 0xE010) = v;
            EnableDmac(ch);
        }
        old = DIntr();
        REG(0x1000B410) = s.addr;
        REG(0x1000B420) = 0xFFFF;
        REG(0x1000B400) = 0x101;
        if (old)
            EIntr();
        s.addr = (s.addr + 0xFFFF0) & 0x0FFFFFFF;
        s.cnt -= 0xFFFF;
        if (n < 0x400)
            func_00109788(m, F(m, 0xF0, unsigned int), n);
        else
            func_001099F8(m, F(m, 0xF0, unsigned int), n);
        DisableDmac(4);
        RemoveDmacHandler(4, id);
    } else {
        old = DIntr();
        {
            register unsigned int *q asm("$6") = (unsigned int *)0x1000B420;
            register unsigned int a asm("$5") = p->addr & 0x0FFFFFFF;

            REG(0x1000B410) = a;
            /* Materialize the transfer-count address alongside the address store. */
            __asm__ volatile("" : "+r"(q));
            {
                register unsigned int *r asm("$4") = (unsigned int *)0x1000B400;
                register unsigned int v asm("$5");

                /* Materialize the control address, then the control value. */
                __asm__ volatile("" : "+r"(r));
                v = 0x101;
                __asm__ volatile("" : "+r"(v));
                *q = s.cnt;
                *r = v;
            }
        }
        if (old)
            EIntr();
        s.cnt = 0;
        if (n < 0x400)
            func_00109788(m, F(m, 0xF0, unsigned int), n);
        else
            func_001099F8(m, F(m, 0xF0, unsigned int), n);
    }
    buf[0] = 3;
    func_0010B488(F(m, 0x870, int), buf);
}
