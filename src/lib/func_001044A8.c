typedef struct { unsigned int *buf; int x4; unsigned int *tag; } Pkt44A8;
extern unsigned int *func_00104450(Pkt44A8 *);

void func_001044A8(Pkt44A8 *p, unsigned int x1, unsigned int x2, unsigned int n)
{
    unsigned int *a;
    p->tag = func_00104450(p);
    a = p->buf;
    *a++ = n | 0x10000000;
    a[0] = 0;
    a[1] = x1;
    a[2] = x2;
    p->buf = a + 3;
}
