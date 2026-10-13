typedef union { struct { int a; int b; int c; int d; int e; int f; } s; int w[6]; } Msg;
typedef struct { int f0; int f4; int f8; int fC; int f10; int f14; int (*f18)(Msg *); } T;
typedef struct { char pad[0x20]; T *t[0x40]; int off[0x40]; } Sub;
typedef struct { int f0; int f4; Sub s; } E;
typedef struct { unsigned char b0; char pad[0x1B]; int f1C; int f20; } A;
extern E D_0058DF98[];
extern int func_002E3830(T *, int, int);

unsigned char func_002E3DE0(A *a, int k, unsigned char n)
{
    Msg m; Msg *mp = &m;
    E *e;
    Sub *s;
    T *t;
    int p, q, i;

    if (a == 0) return 0;
    e = &D_0058DF98[a->b0];
    s = &e->s;
    if (e == 0) return 0;
    t = s->t[n];
    if (t == 0) return 0;
    p = a->f1C + s->off[n];
    if (p == 0) return 0;
    q = a->f20 + s->off[n];
    if (q == 0) return 0;
    if (t->f14 == 5) {
        mp->s.a = k;
        mp->s.b = n;
        mp->s.e = p;
        mp->s.c = t->f4;
        mp->s.f = q;
        mp->s.d = t->f8;
        if (t->f18 != 0) return t->f18(mp);
        return 0;
    }
    for (i = 0; i < t->f8; i++) {
        if (func_002E3830(t, p, q)) return 1;
        p += t->f4;
        q += t->f4;
    }
    return 0;
}



