extern int D_0048C458;
extern int D_0058DF74;
extern int D_00590218[];
int func_002ED4D0(int *out, int v)
{
    int idx;
    if (D_0048C458 == 0) return 0x11;
    if (out == 0) return 0x17;
    idx = D_0058DF74;
    *out = idx;
    D_00590218[idx] = v;
    D_0058DF74++;
    return 0;
}
