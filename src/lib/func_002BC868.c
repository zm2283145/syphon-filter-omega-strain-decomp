typedef struct { int state; int x4; int x8; int pad[5]; int x20; int x24; } CtxC868;
extern CtxC868 D_0051ECC0;
extern char D_0051ED00[];
extern int func_002B5000(int, int);
extern int func_002B4F10(CtxC868 *, void *);
int func_002BC868(int a)
{
    int r, k;
    r = func_002B5000(a, 0);
    if (r >= 0) {
        D_0051ECC0.x20 = r;
    } else if (D_0051ECC0.x4 == -1) {
        D_0051ECC0.state = 2;
        D_0051ECC0.x4 = a;
        D_0051ECC0.x8 = 0;
        k = func_002B4F10(&D_0051ECC0, D_0051ED00); if (k < 0) return -1; D_0051ECC0.x20 = k;
    }
    D_0051ECC0.x24++;
    return 0;
}