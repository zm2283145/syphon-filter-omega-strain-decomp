typedef struct { char pad[0x28]; unsigned short f28; short p; unsigned short f2C; short p2; int f30; } A;
typedef struct { int a, b, c, d; } M;
extern int func_002BB970(int, M *);
int func_002B7308(int x, A *a)
{
    M m;
    m.a = a->f28;
    m.b = a->f2C;
    m.c = (a->f30 << 10) / a->f28;
    m.d = 1;
    return func_002BB970(x, &m);
}
