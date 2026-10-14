/*
 * lib/medius: 8 files, 002DB388-002DB820
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DB388 */
extern int D_0051F0D0;
extern char D_0048C440;
extern void func_002DB320(unsigned int, int);
void func_002DB388(unsigned int a)
{
    int i;
    if (a >= 4) return;
    if (D_0051F0D0)
        for (i = 0; i < 0x100; i++) func_002DB320(a, i);
    D_0048C440 = 0;
}
/* merge_units: end func_002DB388 */

/* merge_units: begin func_002DB3F0 */
#if 0 /* merge_units */
extern void func_002DB388(int);
#endif /* merge_units */
#define func_002DB388(a0) (func_002DB388((unsigned int)(a0))) /* merge_units */

void func_002DB3F0(void)
{
    int i;
    if (D_0051F0D0)
        for (i = 0; i < 4; i++) func_002DB388(i);
    D_0048C440 = 0;
}
#undef func_002DB388 /* merge_units */
/* merge_units: end func_002DB3F0 */

/* merge_units: begin func_002DB440 */
#if 0 /* merge_units */
extern int D_0051F0D0[];
#endif /* merge_units */
#define D_0051F0D0 ((int*)&D_0051F0D0) /* merge_units */

extern void func_002DD328(int* p);
void func_002DB440(void)
{
    if (D_0051F0D0[0] != 0)
        func_002DD328(D_0051F0D0);
}
#undef D_0051F0D0 /* merge_units */
/* merge_units: end func_002DB440 */

/* merge_units: begin func_002DB470 */
typedef struct { int x0; unsigned short x4, x6, x8, xA, xC; } N2DB470;
extern signed char D_0058C178[];
extern int func_002DD9B0(unsigned char **, unsigned int);
void func_002DB470(N2DB470 *n)
{
    int i;
    unsigned char *e;
    if (n == 0) return;
    if (n->x6 < 0x1000) {
        for (i = 0; i < n->x8; i++)
            if (D_0058C178[i + n->x6] == 0) D_0058C178[i + n->x6] = 1;
    }
    if (n->xA < 0x800) {
        for (i = 0; i < n->xC; i++) {
            func_002DD9B0(&e, i + n->xA);
            if (e) *e = 1;
        }
    }
}
/* merge_units: end func_002DB470 */

/* merge_units: begin func_002DB550 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct Ent {
    int f0;
    unsigned short f4, f6, f8, fA, fC;
    char name[1];
} Ent;
typedef struct Msg {
    unsigned char b0;
    char pad1[7];
    unsigned short s8, sA, sC, sE, s10;
    char pad12[4];
    char name[0x12];
} Msg;
extern unsigned int D_0048C450;
extern int D_00598410;
extern int func_002E51B8(unsigned int, void **);
extern int func_002E52D8(unsigned int, unsigned int, void **);
extern unsigned char func_002E6090(unsigned int);
extern void func_002DB188(Ent **, unsigned int, unsigned int);
extern char *String_Copy(char *, const char *);
extern int func_002DE880(int, unsigned int, int, int, int, Msg *);
int func_002DB550(unsigned int slot, int who)
{
    Msg m;
    void *p = 0;
    void *q = 0;
    Ent *e;
    int r;
    if ((unsigned int)(who + 1) > 0x100) return 0x17;
    if (slot >= 4) return 0x17;
    r = func_002E51B8(slot, &p);
    if (r) return r;
    if (p == 0) return 8;
    r = func_002E52D8(slot, F(p, unsigned int, 0x400), &q);
    if (r) return r;
    if (q == 0) return 8;
    func_002DB188(&e, slot, F(p, unsigned int, 0x400));
    if (e == 0) return 0x15;
    if ((unsigned int)(F(q, int, 0x14) - 4) < 2) {
    m.b0 = func_002E6090(F(p, unsigned int, 0x400));
    m.s8 = e->f4;
    m.sA = e->f6;
    m.sC = e->f8;
    m.sE = e->fA;
    m.s10 = e->fC;
    String_Copy(m.name, e->name);
    func_002DE880(0x50, D_0048C450, who, D_00598410, 0x24, &m);
    return 0;
    }
    return 0x15;
}
/* merge_units: end func_002DB550 */

/* merge_units: begin func_002DB688 */
extern int func_002E6088(int);
#if 0 /* merge_units */
extern void func_002DB188(char **, unsigned int, int);
#endif /* merge_units */
#define func_002DB188(a0, a1, a2) (func_002DB188((Ent * *)(a0), (a1), (unsigned int)(a2))) /* merge_units */

extern char *func_002DB270(unsigned int, int);
#if 0 /* merge_units */
extern void func_002DB550(unsigned int, int);
#endif /* merge_units */
#define func_002DB550(a0, a1) ((void)func_002DB550((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_002DB470(char *);
#endif /* merge_units */
#define func_002DB470(a0) (func_002DB470((N2DB470 *)(a0))) /* merge_units */

void func_002DB688(unsigned int a, int b)
{
    char *p;
    if (func_002E6088(b) != 1) return;
    if (a >= 4) return;
    func_002DB188(&p, a, b);
    if (p == 0) {
        p = func_002DB270(a, b);
        if (p == 0) return;
    }
    *(unsigned short *)(p + 4) = 0x1000;
    func_002DB550(a, -1);
    func_002DB470(p);
}
#undef func_002DB188 /* merge_units */
#undef func_002DB550 /* merge_units */
#undef func_002DB470 /* merge_units */
/* merge_units: end func_002DB688 */

/* merge_units: begin func_002DB720 */
extern int D_0058806C;
extern void (*D_0058DF8C)(int *);
int D_0048C47C = 0;
#if 0 /* merge_units */
extern void func_002DB188(char **, unsigned int, int);
#endif /* merge_units */
#define func_002DB188(a0, a1, a2) (func_002DB188((Ent * *)(a0), (a1), (unsigned int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern int func_002E52D8(unsigned int, int, char **);
#endif /* merge_units */
#define func_002E52D8(a0, a1, a2) (func_002E52D8((a0), (unsigned int)(a1), (void * *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void func_002DB470(char *);
#endif /* merge_units */
#define func_002DB470(a0) (func_002DB470((N2DB470 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_002DB550(unsigned int, int);
#endif /* merge_units */
#define func_002DB550(a0, a1) ((void)func_002DB550((a0), (a1))) /* merge_units */

void func_002DB720(unsigned int a, int b)
{
    char *q = 0;
    char *e = 0;
    int t[4];
    int st = func_002E6088(b);
    if (st != 1) return;
    if (a >= 4) return;
    func_002DB188(&e, a, b);
    if (e == 0) e = func_002DB270(a, b);
    if (func_002E52D8(a, b, &q)) return;
    if (q == 0) return;
    *(int *)e = D_0058806C;
    q[0x29] = st;
    func_002DB470(e);
    if (D_0058DF8C) {
        t[0] = 0;
        t[1] = a;
        t[2] = b;
        t[3] = D_0048C47C;
        D_0058DF8C(t);
    }
    func_002DB550(a, b);
}
#undef func_002DB188 /* merge_units */
#undef func_002E52D8 /* merge_units */
#undef func_002DB470 /* merge_units */
#undef func_002DB550 /* merge_units */
/* merge_units: end func_002DB720 */

/* merge_units: begin func_002DB820 */
#if 0 /* merge_units */
extern int func_002E51B8(unsigned int, char **);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((a0), (void * *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_002DB188(char **, unsigned int, int);
#endif /* merge_units */
#define func_002DB188(a0, a1, a2) (func_002DB188((Ent * *)(a0), (a1), (unsigned int)(a2))) /* merge_units */

extern int func_002DD968(char **, unsigned int);
#if 0 /* merge_units */
extern void func_002DB550(unsigned int, int);
#endif /* merge_units */
#define func_002DB550(a0, a1) ((void)func_002DB550((a0), (a1))) /* merge_units */

int func_002DB820(unsigned int id)
{
    char *p = 0;
    char *q;
    char *e;
    int r;
    if (D_0048C450 >= 4) return 8;
    if (id >= 0x1000) return 0x17;
    r = func_002E51B8(D_0048C450, &p);
    if (r) return r;
    func_002DB188(&q, D_0048C450, *(int *)(p + 0x400));
    if (q == 0) return 0x15;
    func_002DD968(&e, id);
    if (e == 0) return 0x1E;
    if (*(int *)(e + 4) != *(int *)(p + 0x400)) return 8;
    ((struct { int a; unsigned short id; } *)q)->id = id;
    func_002DB550(D_0048C450, -1);
    return 0;
}
#undef func_002E51B8 /* merge_units */
#undef func_002DB188 /* merge_units */
#undef func_002DB550 /* merge_units */
/* merge_units: end func_002DB820 */
