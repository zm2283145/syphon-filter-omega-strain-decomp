extern short D_00497CC0;
extern int D_00497CC4;
extern unsigned int D_00497CC8;
extern int D_00497CCC;
extern signed char D_00497CD0;
extern int func_002EBC48(int *);
extern int func_00468308(void);
int func_00468EF0(void)
{
    int t = 0;
    int r;
    func_002EBC48(&t);
    if (D_00497CC0 != 1) return -15;
    r = func_00468308();
    if (r != 0) return r;
    if ((unsigned int)(t - D_00497CCC) > D_00497CC8 && D_00497CD0 != 0 && D_00497CC4 >= 0)
        D_00497CCC = t;
    return 0;
}
