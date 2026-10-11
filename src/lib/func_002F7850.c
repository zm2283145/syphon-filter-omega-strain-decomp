extern unsigned char D_004908A0;
extern int func_0034C8E0(int, int *);
int func_002F7850(int a, unsigned char *out)
{
    int v = 0;
    unsigned char st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    if (func_0034C8E0(a, &v)) return 1;
    if (v) *out = st;
    return 0;
}
