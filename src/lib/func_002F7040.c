extern unsigned char D_004908A0;
extern char D_00525600[];
extern int D_00525640[];
extern int func_0034C168(void *cd, int *buf, int p, int x);
int func_002F7040(int x)
{
    if (D_004908A0 != 1) return 5;
    if (x < 0) return 2;
    return func_0034C168(D_00525600, D_00525640, x, 500) != 0;
}
