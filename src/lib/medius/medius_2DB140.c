/*
 * lib/medius: 5 files, 002DB140-002DB320
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DB140 */
extern void *memset(void *, int, unsigned int);
extern char *func_002DD2E8(int);
extern char *D_0051F0D0;
unsigned int D_0048C440[2] = { 0x0, 0x0 };
void func_002DB140(void)
{
    char **pp = &D_0051F0D0;
    *pp = func_002DD2E8(0x400);
    (*(char*)D_0048C440) = 0;
    memset(*pp, 0, 0x400);
}
/* merge_units: end func_002DB140 */

/* merge_units: begin func_002DB188 */
extern int D_0048C450;
#if 0 /* merge_units */
extern int *D_0051F0D0;
#endif /* merge_units */
#define D_0051F0D0 (*(int **)&D_0051F0D0) /* merge_units */

int func_002DB188(int *out, unsigned int a, unsigned int i)
{
    if (out == 0) return 0x17;
    *out = 0;
    if (i >= 0x100) return 0x17;
    if (a >= 4) return 0x17;
    if (a != D_0048C450) return 0;
    if (D_0051F0D0 != 0) {
        *out = D_0051F0D0[i];
        return 0;
    }
    return 0x15;
}
#undef D_0051F0D0 /* merge_units */
/* merge_units: end func_002DB188 */

/* merge_units: begin func_002DB1F0 */
extern int func_002E52D8(unsigned int, unsigned int, int *);
int func_002DB1F0(int *out, unsigned int a, unsigned int i)
{
    int t;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (i < 0x100 && a < 4) {
        t = 0;
        r = func_002E52D8(a, i, &t);
        if (t != 0 && r == 0) *out = ((int *)t)[5];
        return 0;
    }
    return 8;
}
/* merge_units: end func_002DB1F0 */

/* merge_units: begin func_002DB270 */
typedef struct Ent {
    int f0;
    short f4, f6, f8, fA, fC;
    char fE;
} Ent;
#if 0 /* merge_units */
extern Ent **D_0051F0D0;
#endif /* merge_units */
#define D_0051F0D0 (*(Ent * **)&D_0051F0D0) /* merge_units */

extern int func_002E6088(unsigned int);
#if 0 /* merge_units */
extern Ent *func_002DD2E8(int);
#endif /* merge_units */
#define func_002DD2E8(a0) ((Ent *)func_002DD2E8((a0))) /* merge_units */

Ent *func_002DB270(unsigned int a, unsigned int i)
{
    Ent *p = 0;
    if (func_002E6088(i) != 1) return 0;
    if (a < 4) {
        if (i < 0x100) {
            p = func_002DD2E8(0x1C);
            D_0051F0D0[i] = p;
            p->f0 = 0;
            p->f4 = 0;
            p->f6 = 0;
            p->f8 = 0;
            p->fA = 0;
            p->fC = 0;
            p->fE = 0;
        }
        return p;
    }
    return 0;
}
#undef D_0051F0D0 /* merge_units */
#undef func_002DD2E8 /* merge_units */
/* merge_units: end func_002DB270 */

/* merge_units: begin func_002DB320 */
#if 0 /* merge_units */
extern int *D_0051F0D0;
#endif /* merge_units */
#define D_0051F0D0 (*(int **)&D_0051F0D0) /* merge_units */

extern void func_002DD328(int *);
void func_002DB320(unsigned int a, unsigned int i)
{
    if (func_002E6088(i) == 1 && a < 4 && i < 0x100) {
        func_002DD328(&D_0051F0D0[i]);
        /* barrier: retail keeps jal + epilogue, no tail call */
        __asm__ __volatile__("");
    }
}
#undef D_0051F0D0 /* merge_units */
/* merge_units: end func_002DB320 */
