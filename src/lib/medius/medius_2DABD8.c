/*
 * lib/medius: 6 files, 002DABD8-002DB070
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DABD8 */
extern char *func_002F2FA8(int);
extern char *func_002D9E18(char *, int);
extern void func_002EF878(char *, int);
extern int func_002D8AD8(char *);
extern void func_002F4180(int, int);
extern void func_002F3F00(int, int);
extern void func_002F2F30(char *, int);
void func_002DABD8(char *s)
{
    char *c = func_002F2FA8(*(int *)(s + 0x6C));
    char *n;
    if (c == 0) return;
    if (*(int *)(c + 0x30) > 0) {
        n = func_002D9E18(s, *(int *)(c + 0x30));
        if (n) func_002EF878(n, *(int *)(c + 0x34));
    }
    if (*(char **)(s + 0x64)) func_002EF878(*(char **)(s + 0x64), *(int *)(c + 0x34));
    if (*(int *)(c + 0x848)) {
        func_002F4180(func_002D8AD8(s), *(int *)(c + 0x848));
        *(int *)(c + 0x848) = 0;
    }
    if (*(int *)(c + 0x84C)) {
        func_002F3F00(func_002D8AD8(s), *(int *)(c + 0x84C));
        *(int *)(c + 0x84C) = 0;
    }
    func_002F2F30(s + 0x6C, *(int *)(c + 0x34));
}
/* merge_units: end func_002DABD8 */

/* merge_units: begin func_002DACB0 */
#if 0 /* merge_units */
extern void func_002D9E18(char *, int);
#endif /* merge_units */
#define func_002D9E18(a0, a1) ((void)func_002D9E18((a0), (a1))) /* merge_units */

extern int func_002DA338(char *);
int func_002DACB0(char *o)
{
    int n = *(int *)(o + 0x98);
    if (n > 0) func_002D9E18(o, n);
    if (func_002DA338(o)) *(int *)(o + 0x70) |= 8;
    else *(int *)(o + 0x70) &= ~8;
    return *(int *)(o + 0x70);
}
#undef func_002D9E18 /* merge_units */
/* merge_units: end func_002DACB0 */

/* merge_units: begin func_002DAD10 */
#include "types.h"
typedef struct {
    char pad[0x28];
    unsigned int t0, t1;
    unsigned int n0, n1;
    unsigned int t2, t3;
    unsigned int n2, n3;
} S_002DAD10;
void func_002DAD10(S_002DAD10* s, float* a, float* b, float* c, float* d)
{
    if (s->t0 != 0) *a = ((float)s->n0 * 1600.0f) / (float)s->t0;
    else *a = 0;
    if (s->t1 != 0) *b = ((float)s->n1 * 1600.0f) / (float)s->t1;
    else *b = 0;
    if (s->t2 != 0) *c = (float)s->n2 / (float)s->t2;
    else *c = 0;
    if (s->t3 != 0) *d = (float)s->n3 / (float)s->t3;
    else *d = 0;
}
/* merge_units: end func_002DAD10 */

/* merge_units: begin func_002DAF00 */
typedef enum { TyEnum_0 } TyEnum;
typedef struct { char p[0x20]; int x20; int x24; int x28; } C2DAF00;
typedef struct { char p0[0x68]; C2DAF00 *x68; char p1[0x84 - 0x6C]; int x84; int x88; int x8C; char p2[0xBC - 0x90]; TyEnum xBC; char p3[0xD4 - 0xC0]; void (*xD4)(void *, int, int); } S2DAF00;
extern void func_00307488(int, char *, int *);
extern int func_002F4DA8(char *);
void func_002DAF00(S2DAF00 *s, int flag)
{
    char buf[16];
    int v;
    if (flag == 0) {
        func_00307488(s->x8C, buf, &s->x88);
        v = func_002F4DA8(buf);
        s->x84 = v;
        s->x68->x20 = v;
        s->xBC = 2;
        s->x68->x28 = s->x88;
        if (s->xD4) s->xD4(s, s->x84, s->x88);
    } else {
        s->x88 = 0;
        s->x84 = 0;
        s->x68->x20 = 0;
        s->xBC = 2;
        s->x68->x28 = s->x88;
        if (s->xD4) s->xD4(s, s->x84, s->x88);
    }
}
/* merge_units: end func_002DAF00 */

/* merge_units: begin func_002DAFB8 */
typedef struct S2DAFB8 {
    char p0[0x8C];
    int x8C;
} S2DAFB8;
extern void func_00307928(int h, int key);
extern void func_00308380(int h, int key);
#if 0 /* merge_units */
extern void func_002DAF00(S2DAFB8 *s, int flag);
#endif /* merge_units */
#define func_002DAF00(a0, a1) (func_002DAF00((S2DAF00 *)(a0), (a1))) /* merge_units */

void func_002DAFB8(int a, int key, unsigned int kind, int flag, S2DAFB8 *s)
{
    if (s == 0) return;
    switch (kind) {
    case 0:
    case 1:
        return;
    case 2:
        func_00308380(s->x8C, key);
        return;
    case 3:
        func_00307928(s->x8C, key);
        return;
    case 4:
        func_00307928(s->x8C, key);
        return;
    case 5:
        func_002DAF00(s, flag);
        return;
    case 6:
        func_00307928(s->x8C, key);
        return;
    case 7:
        func_00307928(s->x8C, key);
        return;
    case 8:
        func_00307928(s->x8C, key);
        return;
    }
}
#undef func_002DAF00 /* merge_units */
/* merge_units: end func_002DAFB8 */

/* merge_units: begin func_002DB070 */
extern void func_002EDD08(int, char *, int, int);
extern void func_002D9A30(char *, int, char *, short *, int);
void func_002DB070(char *o, short a, int b, short c)
{
    char buf[16];
    short s[2];
    s[0] = a;
    s[1] = c;
    func_002EDD08(*(int *)(o + 0x64), buf, 0x12, 4);
    func_002D9A30(o, b, buf, s, 4);
}
/* merge_units: end func_002DB070 */
