/* func_00320D50: four-channel variant of func_00320858 (medius voice/codec setup): validates four
 * contexts and buffers, runs the per-channel analysis and copies the results out. */
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
extern void func_003201A8(float s0, int k0, float s1, int k1, float s2, int k2, float s3, int k3, int n, void* p, int h0, int h1, int h2, int h3);

int func_00320D50(Ctx_858* a, Ctx_858* b, Ctx_858* c, Ctx_858* d, Buf_858* e, Buf_858* f, Buf_858* g, Buf_858* h, Out_858* o0, Out_858* o1, Out_858* o2, Out_858* o3)
{
    float m0[12];
    float v0[16];
    float m1[12];
    float v1[16];
    float m2[12];
    float v2[16];
    float m3[12];
    float v3[16];
    int k3;
    float g3;
    float s3;
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
    if (d == 0 || d->magic != c->magic) return 0x17D4;
    if (d->b18 != c->b18) return 0x17E3;
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
    if (g == 0) return 0x181A;
    if (g->p8 == 0) return 0x17F2;
    if (g->p0 == 0) return 0x17ED;
    if (!(g->fE < g->fC)) return 0x1801;
    if (!(g->f12 < g->fC)) return 0x1806;
    if (!(g->f10 < 8)) return 0x17F7;
    if (!(g->f14 < 8)) return 0x17FC;
    if (h == 0) return 0x181A;
    if (h->p8 == 0) return 0x17F2;
    if (h->p0 == 0) return 0x17ED;
    if (!(h->fE < h->fC)) return 0x1801;
    if (!(h->f12 < h->fC)) return 0x1806;
    if (!(h->f10 < 8)) return 0x17F7;
    if (!(h->f14 < 8)) return 0x17FC;
    a->x28 = e;
    b->x28 = f;
    c->x28 = g;
    d->x28 = h;
    if (func_00323248() == 3) {
        func_00323550(d);
        func_00323550(c);
        func_00323550(b);
        func_00323550(a);
    }
    func_0031F5A0(d->x1C, h->p0, &h->f4, h->p8, h->fC, &h->fE, &h->f10, &s3, &k3, m3, v3, &g3, 0);
    func_0031F5A0(c->x1C, g->p0, &g->f4, g->p8, g->fC, &g->fE, &g->f10, &s2, &k2, m2, v2, &g2, 0);
    func_0031F5A0(b->x1C, f->p0, &f->f4, f->p8, f->fC, &f->fE, &f->f10, &s1, &k1, m1, v1, &g1, 0);
    func_0031F5A0(a->x1C, e->p0, &e->f4, e->p8, e->fC, &e->fE, &e->f10, &s0, &k0, m0, v0, &g0, 1);
    func_003201A8(s0, k0, s1, k1, s2, k2, s3, k3, 0xA0, e->p0, a->x1C, b->x1C, c->x1C, d->x1C);
    if (o0) {
        o0->f0 = g0;
        for (i = 0; i < 12; i++) o0->a[i] = v0[i];
        for (i = 0; i < 12; i++) o0->b[i] = m0[i];
    }
    if (o1) {
        o1->f0 = g1;
        for (i = 0; i < 12; i++) o1->a[i] = v1[i];
        for (i = 0; i < 12; i++) o1->b[i] = m1[i];
    }
    if (o2) {
        o2->f0 = g2;
        for (i = 0; i < 12; i++) o2->a[i] = v2[i];
        for (i = 0; i < 12; i++) o2->b[i] = m2[i];
    }
    if (o3) {
        o3->f0 = g3;
        for (i = 0; i < 12; i++) o3->a[i] = v3[i];
        for (i = 0; i < 12; i++) o3->b[i] = m3[i];
    }
    if (func_00323248() == 3) {
        func_003235B8(d);
        func_003235B8(c);
        func_003235B8(b);
        func_003235B8(a);
    }
    return 0;
}
