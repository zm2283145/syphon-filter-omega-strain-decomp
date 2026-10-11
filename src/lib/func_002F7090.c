extern unsigned char D_004908A0;
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034C440(char *, char *, int, int, unsigned short, int *, int);
int func_002F7090(int a, int b, unsigned short c, short *out)
{
    int x = 0;
    int r;
    if (D_004908A0 != 1) return 5;
    if (a < 0) return 2;
    if (b == 0) return 2;
    if (out == 0) return 2;
    r = func_0034C440(D_00525600, D_00525640, a, b, c, &x, 0);
    if (r < 0) return 1;
    *out = r;
    return 0;
}
