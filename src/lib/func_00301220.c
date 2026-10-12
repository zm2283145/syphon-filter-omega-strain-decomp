extern unsigned int D_004908FC;
extern int D_004908F8;
extern void func_002FB3C0(int *);
extern int Net_AllocZeroed(int *, unsigned long);

int func_00301220(unsigned int n)
{
    if (n == 0) return 2;
    if (D_004908FC < n) {
        if (D_004908F8 != 0) func_002FB3C0(&D_004908F8);
        if (Net_AllocZeroed(&D_004908F8, n)) return 8;
        D_004908FC = n;
    }
    return 0;
}
