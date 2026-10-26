#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct {
    int a;
    int b;
} Arg;
extern int D_0048C450;
extern unsigned char D_0048C440;
extern int D_0048C478;
extern void (*D_0058DF88)(Arg *);
int __attribute__((weak, section(".dtors_drop"))) NetGetConnInfo(unsigned int a, void **b) { return 0; }
extern int NetGetClientInfo(unsigned int, unsigned int, void **);

int NetCompleteJoin(void)
{
    Arg m;
    void *p = 0;
    void *q = 0;
    int i = 0;
    int r;

    if (D_0048C450 < 0) return 8;
    if (D_0048C450 >= 4 || D_0048C440) return 0;
    r = NetGetConnInfo(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return 0;
    if (F(p, unsigned int, 0x400) >= 0x100) return 8;
    r = NetGetClientInfo(D_0048C450, F(p, unsigned int, 0x400), &q);
    if (r) return r;
    if (q == 0) return 0;
    if ((unsigned int)(F(q, int, 0x14) - 4) >= 2) return 0;
    for (; i < 0x100; i++) {
        if (i == F(p, unsigned int, 0x400)) continue;
        r = NetGetClientInfo(D_0048C450, i, &q);
        if (r) return r;
        if (q && F(q, unsigned char, 0x28) == 1 && F(q, int, 0x14) == 0) return 0;
    }
    D_0048C440 = 1;
    if (D_0058DF88) {
        m.a = 0;
        m.b = D_0048C478;
        D_0058DF88(&m);
        D_0058DF88 = 0;
        D_0048C478 = 0;
    }
    return 0;
}


