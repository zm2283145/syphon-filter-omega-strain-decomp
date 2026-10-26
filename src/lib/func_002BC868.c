typedef struct { int state; int x4; int x8; int pad[5]; int x20; int x24; } CtxC868;
extern CtxC868 D_0051ECC0;
extern char D_0051ED00[];
extern int sceMc2SearchSocket(int, int);
extern int sceMc2CreateSocket(CtxC868 *, void *);
int create_mc2_socket(int a)
{
    int r, k;
    r = sceMc2SearchSocket(a, 0);
    if (r >= 0) {
        D_0051ECC0.x20 = r;
    } else if (D_0051ECC0.x4 == -1) {
        D_0051ECC0.state = 2;
        D_0051ECC0.x4 = a;
        D_0051ECC0.x8 = 0;
        k = sceMc2CreateSocket(&D_0051ECC0, D_0051ED00); if (k < 0) return -1; D_0051ECC0.x20 = k;
    }
    D_0051ECC0.x24++;
    return 0;
}