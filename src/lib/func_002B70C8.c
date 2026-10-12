typedef struct { char d[0x200]; } MC2Ent;
extern MC2Ent D_00513DC0[];
extern int func_002BB2D0(int, void *, int, int);
int __attribute__((weak, section(".dtors_drop"))) func_002B6D20(int idx, int n, int *err) { return 0; } /* stub: defined in same original TU */
int func_002B70C8(int idx, MC2Ent *out, int cl, int n)
{
    int err = 0;
    for (;;) {
        if (n < 2) {
            if (!func_002BB2D0(idx, D_00513DC0, cl, 1)) return 0x8101006F;
            *out = D_00513DC0[n];
            out->d[0x5F] = 0;
            return 0;
        }
        cl = func_002B6D20(idx, cl, &err);
        if (err) return err;
        if (cl == -1) return 0x81010002;
        cl &= 0x7FFFFFFF;
        n -= 2;
    }
}
