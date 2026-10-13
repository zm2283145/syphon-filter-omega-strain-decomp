#pragma opt_propagation off
typedef unsigned long long u64_t;
typedef struct { u64_t lo, hi; } GsQ;
typedef struct {
    char pad0[0x1C];
    int w;
    int h;
    char pad24[0xD0 - 0x24];
    unsigned char ready;
    char padD1[0x120 - 0xD1];
    unsigned int f120;
    unsigned int f124;
    unsigned int f128;
    char pad12C[0x160 - 0x12C];
    int f160;
    int f164;
    int f168;
    char pad16C[0x1060 - 0x16C];
    int f1060;
    char pad1064[0x10E8 - 0x1064];
    u64_t f10E8;
} RB810;
extern char D_00537F80[];
extern u64_t D_004BC1B0[];
extern GsQ *func_00375C30(void *q, int a, int b, int c, int d, int e);
extern void func_00379780(void *q, int a);
extern u64_t *func_00379790(void *p, int i);
extern u64_t *func_003797B0(void *p, int i);
extern void *func_003797D0(RB810 *o);
extern u64_t func_003797E0(RB810 *o);
extern u64_t func_00379840(RB810 *o);
extern void func_003798A0(RB810 *o);

void func_0037B810(RB810 *o, int *rgba, int fbp, unsigned int fbw, int tv, int psm, int ai)
{
    unsigned int x1;
    int y1;
    unsigned int tu;
    int tv16;
    int x0;
    int y0;
    int n;
    GsQ *q;

    tv16 = tv * 16;
    tu = fbw * 16;
    x0 = (0x800 - (o->w >> 1)) * 16;
    y0 = (0x800 - (o->h >> 1)) * 16;
    x1 = x0 + o->w * 16;
    y1 = y0 + o->h * 16;
    if (o->ready) {
        func_003798A0(o);
        o->ready = 0;
    }
    n = 9;
    if (o->f1060 != -1) {
        n += 2;
    }
    q = func_00375C30(D_00537F80, 1, 1, n + 2, 0, 1);
    q->lo = 0x11000000;
    q->hi = 0x300002EULL | ((u64_t)0x20001E9 << 32);
    q++;
    q->lo = ((u64_t)(unsigned int)((n + 1) | 0x50000000) << 32) | 0x1000404;
    q->hi = (long long)n | 0x8000ULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    q->hi = o->f120; q++; q->lo = 0x1A;
    q->hi = func_00379840(o); q++; q->lo = 0x1B;
    q->hi = func_003797E0(o); q++; q->lo = 0x47;
    q->hi = o->f124; q++; q->lo = 0x46;
    if (o->f10E8 == D_004BC1B0[0]) {
        q->hi = (long long)o->f160 | ((long long)o->f164 << 8) | ((long long)o->f168 << 16); q++;
    } else {
        q->hi = 0; q++;
    }
    q->lo = 0x3D;
    q->hi = o->f128 | ((u64_t)o->f128 << 2); q++; q->lo = 8;
    q->hi = o->f128 | ((u64_t)o->f128 << 2); q++; q->lo = 9;
    q->hi = 0; q++; q->lo = 0x3F;
    q->hi = o->f10E8; q++; q->lo = 0x42;
    if (o->f1060 != -1) {
        q->hi = *func_003797B0(func_003797D0(o), o->f1060); q++; q->lo = 6;
        q->hi = *func_00379790(func_003797D0(o), o->f1060); q++; q->lo = 0x14;
        o->f1060 = -1;
    }
    func_00379780(D_00537F80, 1);
    q = func_00375C30(D_00537F80, 1, 1, 0xE, 0, 1);
    q->lo = 0x11000000ULL | ((u64_t)0x5000000E << 32);
    q->hi = 0x800DULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    q->hi = 1; q++; q->lo = 0x1A;
    q->hi = 0x31001; q++; q->lo = 0x47;
    q->hi = D_004BC1B0[ai]; q++; q->lo = 0x42;
    q->hi = 0; q++; q->lo = 0x3F;
    q->hi = 0x60; q++; q->lo = 0x14;
    q->hi = (u64_t)(unsigned int)(fbp << 5) | ((u64_t)(fbw >> 6) << 14) | ((u64_t)(unsigned int)psm << 20) | 0xAA8000000ULL; q++; q->lo = 6;
    q->hi = 5; q++; q->lo = 8;
    q->hi = 0x156; q++; q->lo = 0;
    q->hi = (long long)rgba[0] | ((long long)rgba[1] << 8) | ((long long)rgba[2] << 16) | ((long long)rgba[3] << 24) | ((u64_t)0x3F800000 << 32); q++; q->lo = 1;
    q->hi = 0; q++; q->lo = 3;
    q->hi = (u64_t)(unsigned int)x0 | ((u64_t)(unsigned int)y0 << 16); q++; q->lo = 5;
    { u64_t t = tu; q->hi = t | ((u64_t)(unsigned int)tv16 << 16); } q++; q->lo = 3;
    { u64_t t = x1; q->hi = t | ((u64_t)(unsigned int)y1 << 16); } q++; q->lo = 5;
}





