/*
 * lib/medius: 22 files, 002E9350-002EA448
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E9350 */
extern int sprintf(char* buf, const char* fmt, ...);
extern char* func_00129C80(const char* s, const char* sub);
extern int atoi(const char* s);

int func_002E9350(char* out)
{
    char months[] = "JanFebMarAprMayJunJulAugSepOctNovDec\0";
    char buf[16];
    const char* date;
    const char* time;
    int m;

    if (out == 0)
        return 0x17;
    date = "Mar  8 2004";
    time = "12:08:45";
    sprintf(buf, "%.3s", date);
    m = (func_00129C80(months, buf) - months) / 3 + 1;
    sprintf(out, "Time of build: %.2d.%.2d.%.4s.%.2s.%.2s.%.2s", m, atoi(date + 4), date + 7, time, time + 3, time + 6);
    return 0;
}
/* merge_units: end func_002E9350 */

/* merge_units: begin func_002E9480 */
extern void *memset(void *, int, unsigned int);
extern int func_00476998(void);
int func_002E9480(int *p)
{
    int v;
    if (p == 0) return 0x17;
    memset(p, 0, 0x1C);
    v = func_00476998();
    p[0] = 1;
    p[3] = 0xE4A;
    p[6] = 0;
    p[2] = 0;
    p[5] = 0;
    p[1] = v;
    return 0;
}
/* merge_units: end func_002E9480 */

/* merge_units: begin func_002E94E0 */
typedef struct { int f0; int f4; } Res;
extern unsigned char D_0048C4D7, D_0048C4DC;
extern unsigned int D_0048C4D8;
extern char D_005253F0[];
extern int func_003021D0(char *);
extern int func_00302218(char *);
extern int RecursiveLock_Acquire(char *, int);
extern int RecursiveLock_Release(char *, int);
extern int NetMsg_Init(int *, Res *);

int func_002E94E0(int *o, Res *res)
{
    int r;
    int v;

    if (res == 0) return 0x17;
    res->f4 = 0x12;
    res->f0 = 1;
    if (o == 0) {
        res->f4 = 0x17;
        return 0x17;
    }
    v = *o;
    if (v != 1) {
        res->f4 = 0x26;
        return 0x17;
    }
    if (D_0048C4D8 != 0) {
        D_0048C4D8++;
        res->f4 = 0;
        return 0;
    }
    if (D_0048C4DC == v || func_003021D0(D_005253F0) != 0) {
        res->f4 = 0x2B;
        return 0x2B;
    }
    D_0048C4DC = v;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = NetMsg_Init(o, res);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    if (r) {
        func_00302218(D_005253F0);
        D_0048C4DC = 0;
        D_0048C4D7 = 0;
        return r;
    }
    D_0048C4D8 = v;
    D_0048C4D7 = v;
    return 0;
}
/* merge_units: end func_002E94E0 */

/* merge_units: begin func_002E9648 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002E4EA8(void);
#if 0 /* merge_units */
extern int func_00302218(void *);
#endif /* merge_units */
#define func_00302218(a0) (func_00302218((char *)(a0))) /* merge_units */

int func_002E9648(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4D8 == 0) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (D_0048C4D8 >= 2) {
        D_0048C4D8--;
        return 0;
    }
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E4EA8();
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    if (r == 0) {
        if (func_00302218(D_005253F0)) return 0x2B;
        D_0048C4DC = 0;
        D_0048C4D7 = 0;
        D_0048C4D8 = 0;
    }
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
#undef func_00302218 /* merge_units */
/* merge_units: end func_002E9648 */

/* merge_units: begin func_002E9740 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002DCD48(void *, void *);
int func_002E9740(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DCD48(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9740 */

/* merge_units: begin func_002E97E8 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002DCF40(void *, void *, void *, void *, void *);
int func_002E97E8(void *a, void *b, void *c, void *d, void *e)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DCF40(a, b, c, d, e);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E97E8 */

/* merge_units: begin func_002E98C0 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002DD030(void *, void *, void *);
int func_002E98C0(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD030(a, b, c);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E98C0 */

/* merge_units: begin func_002E9978 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002DD0F0(void *);
int func_002E9978(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD0F0(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9978 */

/* merge_units: begin func_002E9A10 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002ECFF0(void);
int func_002E9A10(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002ECFF0();
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9A10 */

/* merge_units: begin func_002E9A98 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002ECFF8(void *, void *, void *, void *);
int func_002E9A98(void *a, void *b, void *c, void *d)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002ECFF8(a, b, c, d);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9A98 */

/* merge_units: begin func_002E9B60 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002ED000(void);
int func_002E9B60(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002ED000();
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9B60 */

/* merge_units: begin func_002E9BE8 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002ED028(void *, void *, void *, void *, void *, void *);
int func_002E9BE8(void *a, void *b, void *c, void *d, void *e, void *f)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002ED028(a, b, c, d, e, f);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9BE8 */

/* merge_units: begin func_002E9CD0 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002ED280(void *, void *, void *);
int func_002E9CD0(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002ED280(a, b, c);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9CD0 */

/* merge_units: begin func_002E9D88 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002ED570(void *, void *, void *, void *);
int func_002E9D88(void *a, void *b, void *c, void *d)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002ED570(a, b, c, d);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9D88 */

/* merge_units: begin func_002E9E50 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int NetMsg_RegisterTypeInner(void *, void *, void *);
int NetMsg_RegisterType(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = NetMsg_RegisterTypeInner(a, b, c);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9E50 */

/* merge_units: begin func_002E9F08 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002ED550(void *, void *);
int func_002E9F08(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002ED550(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9F08 */

/* merge_units: begin func_002E9FB0 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002DDFF8(signed char, void *, void *, void *, void *, void *);
int func_002E9FB0(signed char a, void *b, void *c, void *d, void *e, void *f)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DDFF8(a, b, c, d, e, f);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002E9FB0 */

/* merge_units: begin func_002EA0A0 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int Net_SendTyped(signed char, void *, void *, void *, void *, void *, void *);
int Net_SendLocked(signed char a, void *b, void *c, void *d, void *e, void *f, void *g)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = Net_SendTyped(a, b, c, d, e, f, g);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002EA0A0 */

/* merge_units: begin func_002EA198 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002DE770(signed char, void *, void *, void *, void *, void *, void *);
int func_002EA198(signed char a, void *b, void *c, void *d, void *e, void *f, void *g)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DE770(a, b, c, d, e, f, g);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002EA198 */

/* merge_units: begin func_002EA290 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002DE828(signed char, void *, void *, void *, void *, void *);
int func_002EA290(signed char a, void *b, void *c, void *d, void *e, void *f)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DE828(a, b, c, d, e, f);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002EA290 */

/* merge_units: begin func_002EA380 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002ED448(void *, void *, void *, void *);
int func_002EA380(void *a, void *b, void *c, void *d)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002ED448(a, b, c, d);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002EA380 */

/* merge_units: begin func_002EA448 */
#if 0 /* merge_units */
extern int RecursiveLock_Acquire(void *, int);
#endif /* merge_units */
#define RecursiveLock_Acquire(a0, a1) (RecursiveLock_Acquire((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int RecursiveLock_Release(void *, int);
#endif /* merge_units */
#define RecursiveLock_Release(a0, a1) (RecursiveLock_Release((char *)(a0), (a1))) /* merge_units */

extern int func_002ED4D0(void *, void *);
int func_002EA448(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002ED4D0(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef RecursiveLock_Acquire /* merge_units */
#undef RecursiveLock_Release /* merge_units */
/* merge_units: end func_002EA448 */
