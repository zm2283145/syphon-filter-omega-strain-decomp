typedef struct { int a, b, c, d, e; char f; char pad[0x17]; } M2B4F10;
extern int D_0048BD88;
extern int func_002BB7C8(M2B4F10 *, int);
int func_002B4F10(int *req, int x)
{
    M2B4F10 m;
    int r;
    if (D_0048BD88 == 0) return 0x81018001;
    if ((unsigned int)(req[1] - 2) >= 2) return 0x81010016;
    if (req[2]) return 0x81010016;
    m.c = req[1];
    m.e = req[3];
    m.d = 0;
    m.a = req[0] | 1;
    m.b = 2;
    m.f = 0;
    r = func_002BB7C8(&m, x);
    return r < 0 ? 0x81010017 : r;
}
