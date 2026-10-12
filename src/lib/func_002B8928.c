typedef struct { char d[0x200]; } MC2Ent;
extern MC2Ent D_00513DC0[];
extern int func_002BB2D0(int, void *, int, int);
extern int func_002BB2E8(int, void *, int, int);
extern int func_002B6D20(int, int, int *);
int func_002B8928(int idx, MC2Ent *ent, int cl, int n)
{
    int err = 0;
    for (;;) {
        if (n < 2) {
            if (!func_002BB2D0(idx, D_00513DC0, cl, 1)) return 0x8101006F;
            D_00513DC0[n] = *ent;
            return func_002BB2E8(idx, D_00513DC0, cl, 1) ? 0 : 0x8101006F;
        }
        cl = func_002B6D20(idx, cl, &err);
        if (err) return err;
        if (cl == -1) return 0x8101006F;
        cl &= 0x7FFFFFFF;
        n -= 2;
    }
}
