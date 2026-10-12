const unsigned int D_004865A0[16] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
extern char D_00116080[];
extern int func_0010CE10(int, void *);
extern int func_0010CE20(int, void *);

unsigned int func_00115958(int n, int h)
{
    int old;
    if ((unsigned int)(n - 1) >= 13) return 0xFFFFFFFF;
    old = ((int*)D_004865A0)[n];
    ((int*)D_004865A0)[n] = h;
    if ((unsigned int)(n - 1) < 3) {
        func_0010CE10(n, D_00116080);
    } else {
        func_0010CE20(n, D_00116080);
    }
    return old;
}