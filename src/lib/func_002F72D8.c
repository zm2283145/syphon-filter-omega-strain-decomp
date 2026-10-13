extern unsigned char D_004908A0;
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034C200(char *, char *, int, void *, unsigned short, int *, int);
int func_002F72D8(int a, void *buf, unsigned short len, short *out)
{
    int flags;
    unsigned char st;
    int r;
    flags = 0;
    st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (buf == 0) return 2;
    if (out == 0) return 2;
    r = func_0034C200(D_00525600, D_00525640, a, buf, len > 0x1000 ? 0x1000 : len, &flags, 2);
    if (r < 0) {
        if (flags & 4) return 13;
        return 1;
    }
    if (flags & 4) return 13;
    *out = r;
    return 0;
}
