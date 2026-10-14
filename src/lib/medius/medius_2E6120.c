/*
 * lib/medius: 9 files, 002E6120-002E6640
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E6120 */
extern void func_002DFAE8(unsigned int port, int slot, unsigned char flag, unsigned short n, int arg);
void func_002E6120(int port, unsigned short n, int x)
{
    if (x == 0 && port != -2) {
        func_002DFAE8(0, port, 1, n, 0);
        return;
    }
    func_002DFAE8(0, 0x100, 0, 0, 1);
}
/* merge_units: end func_002E6120 */

/* merge_units: begin func_002E6178 */
typedef enum { TyEnum_0 } TyEnum;
typedef struct { TyEnum a, b, c, d, e; } Msg;
typedef struct { char pad[0x438]; int f438; } T;
extern void (*D_0048C470)(Msg *);
extern int D_0048C474;
extern int func_002E51B8(unsigned int, T **);
extern int func_002E4CA8(int);
extern void *memset(void *, int, unsigned int);
void func_002E6178(int code)
{
    Msg m;
    unsigned int p[1];
    p[0] = 0;
    if (func_002E51B8(0, (T **)p)) return;
    if (p[0] == 0) return;
    func_002E4CA8(0);
    if (D_0048C470 == 0) return;
    memset(&m, 0, sizeof(m));
    m.b = ((T *)p[0])->f438;
    m.a = 0;
    m.c = 1;
    if (code == 0xB) m.d = 0xE; else m.d = 0x25;
    m.e = D_0048C474;
    D_0048C470(&m);
}
/* merge_units: end func_002E6178 */

/* merge_units: begin func_002E6230 */
typedef struct { int type; int a; int b; } E6230;
extern void (*D_0048C480)(E6230 *);
extern int D_0048C484;
void func_002E6230(int a)
{
    void (**pf)(E6230 *) = &D_0048C480;
    E6230 e;
    if (*pf == 0) return;
    memset(&e, 0, 0xC);
    e.a = a;
    e.b = D_0048C484;
    e.type = 0;
    (*pf)(&e);
}
/* merge_units: end func_002E6230 */

/* merge_units: begin func_002E6298 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct {
    int f0;
    char name[0x10];
    int port;
    char pad[0x18];
} Info;
typedef struct {
    int f0;
    int f4;
    Info d;
} G;
typedef struct {
    char name[0x10];
    unsigned short port;
} Q;
extern Info D_00588070;
extern G D_00520300;
extern void (*D_00520338)(G *);
extern char *strncpy(char *, const char *, unsigned int);
#if 0 /* merge_units */
extern int func_002E51B8(unsigned int, void **);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((a0), (T * *)(a1))) /* merge_units */

extern int func_002E52D8(unsigned int, unsigned int, Q **);

void func_002E6298(const char *name, unsigned short port, int err)
{
    void *p = 0;
    Q *q = 0;

    if (err == 0) {
        D_00588070.port = port;
        strncpy(D_00588070.name, name, 0x10);
        if (func_002E51B8(0, &p) == 0 && p && func_002E52D8(0, F(p, unsigned int, 0x400), &q) == 0 && q) {
            strncpy(q->name, name, 0x10);
            q->port = port;
        }
    }
    D_00520300.f0 = 1;
    D_00520300.f4 = err ? 0x25 : 0;
    D_00520300.d = D_00588070;
    D_00520338(&D_00520300);
}
#undef func_002E51B8 /* merge_units */
/* merge_units: end func_002E6298 */

/* merge_units: begin func_002E63F0 */
extern unsigned int D_0048C4B0;
extern char D_005880A0[];
extern unsigned short D_0058D178;
extern int func_003029B8(unsigned int, int, int *);
extern int func_00302A38(unsigned int, int, int, char *, unsigned short *);
#if 0 /* merge_units */
extern int func_002E51B8(unsigned int, char **);
#endif /* merge_units */
#define func_002E51B8(a0, a1) (func_002E51B8((a0), (T * *)(a1))) /* merge_units */

extern int func_002DD5B8(int, int, char *, unsigned int);
extern int func_002DEF70(int, int);
void func_002E63F0(int a, unsigned int b)
{
    int x;
    char *p;
    int r;
    switch (b) {
    case 0:
        x = -1;
        p = 0;
        r = func_003029B8(D_0048C4B0, a, &x);
        if (r) return;
        r = func_00302A38(D_0048C4B0, a, x, D_005880A0, &D_0058D178);
        if (r) return;
        if (func_002E51B8(0, &p) == 0 && p) (*(int *)(p + 0x440))++;
        func_002DD5B8(0, a, D_005880A0, D_0058D178);
        break;    case 1:
    case 2:
        func_002DEF70(0, a);
        break;
    }
}
#undef func_002E51B8 /* merge_units */
/* merge_units: end func_002E63F0 */

/* merge_units: begin func_002E64E0 */
#if 0 /* merge_units */
extern int D_0048C4B0;
#endif /* merge_units */
#define D_0048C4B0 (*(int*)&D_0048C4B0) /* merge_units */

#if 0 /* merge_units */
extern int func_003029B8(int, int, int *);
#endif /* merge_units */
#define func_003029B8(a0, a1, a2) (func_003029B8((unsigned int)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int func_00302A38(int, int, int, char *, unsigned short *);
#endif /* merge_units */
#define func_00302A38(a0, a1, a2, a3, a4) (func_00302A38((unsigned int)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

extern int func_002DD280(void);
extern void Net_DispatchRecv(int, int, int, int, unsigned short);
void func_002E64E0(int a, int b, unsigned short c)
{
    int st = -1;
    if (func_003029B8(D_0048C4B0, a, &st)) return;
    if (func_00302A38(D_0048C4B0, a, st, D_005880A0, &D_0058D178)) return;
    Net_DispatchRecv(func_002DD280(), 0, (unsigned short)a, b, c);
}
#undef D_0048C4B0 /* merge_units */
#undef func_003029B8 /* merge_units */
#undef func_00302A38 /* merge_units */
/* merge_units: end func_002E64E0 */

/* merge_units: begin func_002E6590 */
void func_002E6590(const char *name, unsigned short port, int c, unsigned short d)
{
    strncpy(D_005880A0, name, 0x10);
    D_0058D178 = port;
    Net_DispatchRecv(func_002DD280(), 0xFFFF, 0x100, c, d);
}
/* merge_units: end func_002E6590 */

/* merge_units: begin func_002E6600 */
extern unsigned char D_0048C454;
extern void func_002DB550(int a, int b);
void func_002E6600(int a, unsigned char flag)
{
    if (flag && D_0048C454)
        func_002DB550(0, a);
}
/* merge_units: end func_002E6600 */

/* merge_units: begin func_002E6640 */
typedef struct { int h; unsigned char b; int c; int d; unsigned char e; unsigned short f; int g; int x; } M2E6640;
extern void (*D_0048C490)(M2E6640 *);
extern int D_0048C494;
extern int func_002DCD20(unsigned short);
void func_002E6640(unsigned short a, unsigned char b, int c, int d, unsigned char e, unsigned short f, int g)
{
    M2E6640 m;
    void (*cb)(M2E6640 *) = D_0048C490;
    if (cb) {
        m.h = func_002DCD20(a);
        m.c = c;
        m.b = b;
        m.d = d;
        m.e = e;
        m.f = f;
        m.g = g;
        m.x = D_0048C494;
        cb(&m);
    }
}
/* merge_units: end func_002E6640 */
