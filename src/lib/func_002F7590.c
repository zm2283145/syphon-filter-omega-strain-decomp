extern unsigned char D_004908A0;
extern int func_0034C6C0(int, int *);
int func_002F7590(int a, short *out)
{
    int fl = 0;
    unsigned char st = D_004908A0;
    int r;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    r = func_0034C6C0(a, &fl);
    if (r < 0) {
        if (r == -0x1FE || r == -0x1FD || r == -0x1FC) return 0xD;
        return 1;
    }
    if (fl & 4) return 0xD;
    *out = r;
    return 0;
}
