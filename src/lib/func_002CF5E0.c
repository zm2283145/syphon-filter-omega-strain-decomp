extern short D_0048C414;
extern int D_0048C3D8;
extern char D_004AD310[];
extern int func_002EC738(int);
extern void func_00127358(char *, int);
int func_002CF5E0(void)
{
    int r;
    if (D_0048C414 != 1) return -0xC;
    {
        int *pc = &D_0048C3D8;
        r = func_002EC738(*pc);
        *pc = -1;
    }
    if (r) {
        func_00127358(D_004AD310, r);
        return -3;
    }
    return 0;
}