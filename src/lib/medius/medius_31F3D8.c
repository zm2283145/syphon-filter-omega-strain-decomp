/*
 * lib/medius: 5 files, 0031F3D8-0031FA08
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031F3D8 */
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
extern void updateVuFft(void);
extern void BitUnpackCBuffer(Bs_f3d8 *bs, unsigned char *out, int v);
extern void unquantize(Obj_f3d8 *o, int *p, char *arg, Out_f3d8 *out);
extern void NellyAskToEnv(float a, float *c, char *base, int d, int e, float b);
extern void SubFrameSynth(Obj_f3d8 *o, Out_f3d8 *out, int a, int *z);

void NellyDecodeSase3200(Obj_f3d8 *o, int a1, short *a2, int a3, unsigned short a4,
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
    updateVuFft();
    base = o->base;
    bs.b = a4;
    bs.c = a5;
    bs.d = a6;
    sv1 = *a5;
    sv2 = *a6;
    bs.a = a3;
    for (i = 0; i < 17; i++) {
        BitUnpackCBuffer(&bs, &c, D_004B5DB8[i]);
        vals[i] = c;
    }
    unquantize(o, vals, base, &out);
    if (o->s44 == 1) {
        NellyAskToEnv(out.f10, out.f14, o->base, a7, a8, o->f28);
    }
    SubFrameSynth(o, &out, a1, &z);
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
/* merge_units: end func_0031F3D8 */

/* merge_units: begin func_0031F5A0 */
extern void (*D_004E1D3C)(void *p, int c, int n);
extern void SubFrameAltSynth(Obj_f3d8 *o, Out_f3d8 *out, short *a, int *z, int b, int c);

void NellyAltDecodeSase3200(Obj_f3d8 *o, short *a1, short *a2, int a3, unsigned short a4,
                   unsigned short *a5, unsigned char *a6, int a7, int a8, int a9,
                   int a10, float *a11, int a12)
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
    updateVuFft();
    base = o->base;
    D_004E1D3C(a1, 0, 0xA0);
    bs.b = a4;
    bs.a = a3;
    bs.c = a5;
    bs.d = a6;
    sv1 = *a5;
    sv2 = *a6;
    for (i = 0; i < 17; i++) {
        BitUnpackCBuffer(&bs, &c, D_004B5DB8[i]);
        vals[i] = c;
    }
    unquantize(o, vals, base, &out);
    if (a12) {
        int j;
        for (j = 0; j < 80; j++)
            a1[j] = (int)(((float *)base)[j] + 0.5f);
    }
    if (o->s44 == 1) {
        NellyAskToEnv(out.f10, out.f14, o->base, a9, a10, o->f28);
    }
    SubFrameAltSynth(o, &out, a1, &z, a7, a8);
    *a2 = 0x50;
    *a11 = out.f10;
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
/* merge_units: end func_0031F5A0 */

/* merge_units: begin func_0031F7C8 */
extern void *(*D_004E1D34)(int, int);
extern int NellyInitHFRegen(void *pp);

typedef struct {
    void *sub;
    float *a;
    float *b;
    float *c;
    float *d;
    float *e;
    float *f;
    int pad1C;
    float g0, g1, g2, g3;
    float h;
    float i;
    int pad38;
    int j;
    int pad40;
    short k;
    int l;
    float m;
    int pad50;
} State;

int NellyInitDecodeSase3200(State **pp)
{
    State *s;

    if (!pp)
        return 1;
    *pp = 0;
    s = D_004E1D34(1, sizeof(State));
    if (!s)
        return 1;
    *pp = s;
    if (!(s->a = D_004E1D34(0x284, 4)))
        return 1;
    if (!(s->b = D_004E1D34(0x50, 4)))
        return 1;
    if (NellyInitHFRegen(s))
        return 1;
    s->k = 1;
    s->l = 1;
    s->g0 = 1.0f;
    s->g1 = 1.0f;
    s->g2 = 1.0f;
    s->g3 = 1.0f;
    s->h = 1.0f;
    s->i = 80.0f;
    s->j = 0;    if (!(s->c = D_004E1D34(0x41, 4)))
        return 1;
    if (!(s->d = D_004E1D34(0x41, 4)))
        return 1;
    if (!(s->e = D_004E1D34(0x66, 4)))
        return 1;
    if (!(s->f = D_004E1D34(0x66, 4)))
        return 1;
    s->m = 100.0f;
    return 0;
}
/* merge_units: end func_0031F7C8 */

/* merge_units: begin func_0031F938 */
typedef struct { void *p0; void *p4; void *p8; void *pC; void *p10; void *p14; void *p18; } ObjF938;
extern int (*D_004E1D38)(void *p);
extern void NellyFreeHFRegen(ObjF938 *o);
int NellyFreeDecodeSase3200(ObjF938 **pp)
{
    ObjF938 *o = *pp;
    if (o != 0) {
        if (o->p4) { D_004E1D38(o->p4); o->p4 = 0; }
        NellyFreeHFRegen(o);
        if (o->pC) { D_004E1D38(o->pC); o->pC = 0; }
        if (o->p10) { D_004E1D38(o->p10); o->p10 = 0; }
        if (o->p14) { D_004E1D38(o->p14); o->p14 = 0; }
        if (o->p18) { D_004E1D38(o->p18); o->p18 = 0; }
        if (o->p8) { D_004E1D38(o->p8); o->p8 = 0; }
        D_004E1D38(o);
    }
    return 0;
}
/* merge_units: end func_0031F938 */

/* merge_units: begin func_0031FA08 */
#include "types.h"
extern float D_004E1BE0;
float func_0031FA08(float a, float b, float c, float d)
{
    float r, m;
    if (b <= a * 1.25f && a * D_004E1BE0 <= b) {
        r = (a + b) * 0.5f;
    } else {
        if (c > d) { m = c; r = a; } else { m = d; r = b; }
        if (r < 30.0f) {
            if (m * r * 0.5f < 1.0f) {
                r = (a < b) ? b : a;
            }
        }
    }
    return r;
}
/* merge_units: end func_0031FA08 */
