extern unsigned short D_00513DC0[];
extern int func_002BB2D0(int, unsigned short *, unsigned int, int);
extern unsigned int func_002B6D20(int, unsigned int, int *);
int func_002B8AE8(int dev, unsigned int cl, int n, int *err)
{
    int cnt = 0;
    *err = 0;
    for (;;) {
        int i;
        unsigned short *p;
        if (func_002BB2D0(dev, D_00513DC0, cl, 1) == 0) {
            *err = 0x8101006F;
            return -1;
        }
        for (i = 0, p = D_00513DC0; i < 2; i++) {
            if (!(*p & 0x8000)) cnt++;
            p += 0x100;
            if (--n == 0) { int r = cnt + 1; if (i) r = cnt; return r; }
        }
        cl = func_002B6D20(dev, cl, err);
        if (*err) return -1;
        if (cl == 0xFFFFFFFF) return cnt;
        cl &= 0x7FFFFFFF;
    }
}


