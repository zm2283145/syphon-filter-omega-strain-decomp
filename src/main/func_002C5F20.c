#pragma push
#pragma cplusplus on

struct V4Q_5F20 {
    float x, y, z, w;
    V4Q_5F20& operator=(const V4Q_5F20& o) { __int128 q; const V4Q_5F20* s = &o; asm volatile { lq q, 0(s)
 sq q, 0(this) } return *this; }
} __attribute__((aligned(16)));

struct Fl_5F20 {
    float v;
    Fl_5F20& operator=(const Fl_5F20& o) { float f; const Fl_5F20* s = &o; Fl_5F20* t = this; asm volatile { lwc1 f, 0(s)
 swc1 f, 0(t) } return *this; }
};

struct Rec5F20 {
    float f00;
    int f04;
    int f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    float f58;
    int arr[9];
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    V4Q_5F20 qA0;
    Fl_5F20 fB0;
    int fB4;
    int fB8;
    int fBC;
    int fC0;
    int fC4;
    float fC8;
    int fCC;
    int fD0;
    int fD4;
    int fD8;
    signed char fDC;
    signed char fDD;
    signed char fDE;
    signed char fDF;
    signed char fE0;
    unsigned char fE1;
    float fE4;
};

extern "C" Rec5F20* func_002C5F20(Rec5F20* d, Rec5F20* s)
{
    int i;

    d->f00 = s->f00;
    d->f04 = s->f04;
    d->f08 = s->f08;
    d->f0C = s->f0C;
    d->f10 = s->f10;
    d->f14 = s->f14;
    d->f18 = s->f18;
    d->f1C = s->f1C;
    d->f20 = s->f20;
    d->f24 = s->f24;
    d->f28 = s->f28;
    d->f2C = s->f2C;
    d->f30 = s->f30;
    d->f34 = s->f34;
    d->f38 = s->f38;
    d->f3C = s->f3C;
    d->f40 = s->f40;
    d->f44 = s->f44;
    d->f48 = s->f48;
    d->f4C = s->f4C;
    d->f50 = s->f50;
    d->f54 = s->f54;
    d->f58 = s->f58;
    for (i = 0; i < 9; i++)
        d->arr[i] = s->arr[i];
    d->f80 = s->f80;
    d->f84 = s->f84;
    d->f88 = s->f88;
    d->f8C = s->f8C;
    d->f90 = s->f90;
    d->f94 = s->f94;
    d->qA0 = s->qA0;
    d->fB0 = s->fB0;
    d->fB4 = s->fB4;
    d->fB8 = s->fB8;
    d->fBC = s->fBC;
    d->fC0 = s->fC0;
    d->fC4 = s->fC4;
    d->fC8 = s->fC8;
    d->fCC = s->fCC;
    d->fD0 = s->fD0;
    d->fD4 = s->fD4;
    d->fD8 = s->fD8;
    d->fDC = s->fDC;
    d->fDD = s->fDD;
    d->fDE = s->fDE;
    d->fDF = s->fDF;
    d->fE0 = s->fE0;
    d->fE1 = s->fE1;
    d->fE4 = s->fE4;
    return d;
}

#pragma pop



