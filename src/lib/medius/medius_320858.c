typedef struct {
    long magic;
    char pad8[0x10];
    unsigned char b18;
    char pad19[3];
    int x1C;
    char pad20[8];
    void* x28;
} Ctx_858;
typedef struct {
    void* p0;
    int f4;
    void* p8;
    unsigned short fC;
    unsigned short fE;
    unsigned char f10;
    char pad11;
    unsigned short f12;
    unsigned char f14;
} Buf_858;
typedef struct {
    float f0;
    float a[12];
    float b[12];
} Out_858;

extern int func_00323248(void);
extern void func_00323550(Ctx_858* c);
extern void func_003235B8(Ctx_858* c);
extern void func_0031F5A0(int h, void* p0, int* f4, void* p8, unsigned short n, unsigned short* pos, unsigned char* bit, float* s, int* k, float* m, float* v, float* g, int last);
extern void func_0031FEA8(float s0, int k0, float s1, int k1, float s2, int k2, int n, void* p, int h0, int h1, int h2);

int func_00320858(Ctx_858* a, Ctx_858* b, Ctx_858* c, Buf_858* d, Buf_858* e, Buf_858* f, Out_858* g, Out_858* h, Out_858* o)
{
    float m0[12];
    float v0[16];
    float m1[12];
    float v1[16];
    float m2[12];
    float v2[16];
    int k2;
    float g2;
    float s2;
    int k1;
    float g1;
    float s1;
    int k0;
    float g0;
    float s0;
    int i;

    if (a == 0 || a->magic != 0xFACE) return 0x17D4;
    if (a->b18 != 11) return 0x17E3;
    if (b == 0 || b->magic != a->magic) return 0x17D4;
    if (b->b18 != a->b18) return 0x17E3;
    if (c == 0 || c->magic != b->magic) return 0x17D4;
    if (c->b18 != b->b18) return 0x17E3;
    if (d == 0) return 0x181A;
    if (d->p8 == 0) return 0x17F2;
    if (d->p0 == 0) return 0x17ED;
    if (!(d->fE < d->fC)) return 0x1801;
    if (!(d->f12 < d->fC)) return 0x1806;
    if (!(d->f10 < 8)) return 0x17F7;
    if (!(d->f14 < 8)) return 0x17FC;
    if (e == 0) return 0x181A;
    if (e->p8 == 0) return 0x17F2;
    if (e->p0 == 0) return 0x17ED;
    if (!(e->fE < e->fC)) return 0x1801;
    if (!(e->f12 < e->fC)) return 0x1806;
    if (!(e->f10 < 8)) return 0x17F7;
    if (!(e->f14 < 8)) return 0x17FC;
    if (f == 0) return 0x181A;
    if (f->p8 == 0) return 0x17F2;
    if (f->p0 == 0) return 0x17ED;
    if (!(f->fE < f->fC)) return 0x1801;
    if (!(f->f12 < f->fC)) return 0x1806;
    if (!(f->f10 < 8)) return 0x17F7;
    if (!(f->f14 < 8)) return 0x17FC;
    a->x28 = d;
    b->x28 = e;
    c->x28 = f;
    if (func_00323248() == 3) {
        func_00323550(c);
        func_00323550(b);
        func_00323550(a);
    }
    func_0031F5A0(c->x1C, f->p0, &f->f4, f->p8, f->fC, &f->fE, &f->f10, &s2, &k2, m2, v2, &g2, 0);
    func_0031F5A0(b->x1C, e->p0, &e->f4, e->p8, e->fC, &e->fE, &e->f10, &s1, &k1, m1, v1, &g1, 0);
    func_0031F5A0(a->x1C, d->p0, &d->f4, d->p8, d->fC, &d->fE, &d->f10, &s0, &k0, m0, v0, &g0, 1);
    func_0031FEA8(s0, k0, s1, k1, s2, k2, 0xA0, d->p0, a->x1C, b->x1C, c->x1C);
    if (g) {
        g->f0 = g0;
        for (i = 0; i < 12; i++) g->a[i] = v0[i];
        for (i = 0; i < 12; i++) g->b[i] = m0[i];
    }
    if (h) {
        h->f0 = g1;
        for (i = 0; i < 12; i++) h->a[i] = v1[i];
        for (i = 0; i < 12; i++) h->b[i] = m1[i];
    }
    if (o) {
        o->f0 = g2;
        for (i = 0; i < 12; i++) o->a[i] = v2[i];
        for (i = 0; i < 12; i++) o->b[i] = m2[i];
    }
    if (func_00323248() == 3) {
        func_003235B8(c);
        func_003235B8(b);
        func_003235B8(a);
    }
    return 0;
}
