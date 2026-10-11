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
