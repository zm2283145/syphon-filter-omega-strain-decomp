typedef struct { unsigned int *buf; int x4; unsigned int *tag; } Pkt4520;
extern unsigned int *func_00104450(Pkt4520 *);

void func_00104520(Pkt4520 *p, unsigned int addr, unsigned int id, unsigned int x2, unsigned int x3, unsigned int n)
{
    unsigned int *a;
    func_00104450(p);
    a = p->buf;
    { unsigned int t = id | 0x30000000; *a++ = n | t; }
    a[0] = addr & 0x9FFFFFFF;
    a[1] = x2;
    a[2] = x3;
    p->buf = a + 3;
}
