typedef struct {
    char pad0[4];
    char *base;
    char pad8[4];
    void *pC;
    void *p10;
    char pad14[0x14];
    float f28;
    char pad2C[0x18];
    short s44;
    char pad46[6];
    char buf4C[8];
} Obj_f3d8;

typedef struct {
    float f0;
    float f4;
    float q[2];
    float f10;
    float f14[15];
} Out_f3d8;

typedef struct {
    int a;
    short b;
    unsigned short *c;
    unsigned char *d;
    int pad[4];
} Bs_f3d8;

extern int D_004B5DB8[];
extern void *(*D_004E1D40)(void *dst, void *src, int n);
extern void func_00323270(void);
extern void func_0031F300(Bs_f3d8 *bs, unsigned char *out, int v);
extern void func_0031FAB8(Obj_f3d8 *o, int *p, char *arg, Out_f3d8 *out);
extern void func_0031EE08(float a, float *c, char *base, int d, int e, float b);
extern void func_003218F8(Obj_f3d8 *o, Out_f3d8 *out, int a, int *z);

void func_0031F3D8(Obj_f3d8 *o, int a1, short *a2, int a3, unsigned short a4,
                   unsigned short *a5, unsigned char *a6, int a7, int a8, float *a9)
{
    Out_f3d8 out;
    int vals[20];
    Bs_f3d8 bs;
    unsigned char c;
    int z;
    int sv1;
    int sv2;
    char *base;
    int i;

    z = 0;
    func_00323270();
    base = o->base;
    bs.b = a4;
    bs.c = a5;
    bs.d = a6;
    sv1 = *a5;
    sv2 = *a6;
    bs.a = a3;
    for (i = 0; i < 17; i++) {
        func_0031F300(&bs, &c, D_004B5DB8[i]);
        vals[i] = c;
    }
    func_0031FAB8(o, vals, base, &out);
    if (o->s44 == 1) {
        func_0031EE08(out.f10, out.f14, o->base, a7, a8, o->f28);
    }
    func_003218F8(o, &out, a1, &z);
    *a2 = 0x50;
    *a9 = out.f10;
    if (o->s44 == 0) {
        o->s44 = 1;
        D_004E1D40(o->buf4C, out.q, 8);
    } else {
        o->s44 = 0;
        *a5 = sv1;
        *a6 = sv2;
    }
    {
        char *p2 = base + 0x90C;
        D_004E1D40(o->pC, base + 0x808, 0x104);
        D_004E1D40(o->p10, p2, 0x104);
    }
}


