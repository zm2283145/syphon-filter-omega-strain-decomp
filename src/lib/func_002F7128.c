extern unsigned char D_004908A0;
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034C7A8(char *, int);
extern int func_0034C590(char *, char *, int, int, unsigned short, int *, char *, unsigned short, int);
int func_002F7128(int a, int name, unsigned short x, int y, unsigned short z, short *out)
{
    char buf[16];
    int w = 0;
    int r;
    if (D_004908A0 != 1) return 5;
    if (a < 0) return 2;
    if (name == 0) return 2;
    if (x == 0) return 2;
    if (y == 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (func_0034C7A8(buf, name) < 0) return 1;
    r = func_0034C590(D_00525600, D_00525640, a, y, z, &w, buf, x, 0);
    if (r < 0) return 1;
    *out = r;
    return 0;
}
