extern int D_005880B0[];
int func_002DD968(int *out, unsigned int idx)
{
    if (out == 0) return 0x17;
    if (idx < 0x1000) {
        *out = D_005880B0[idx];
        return 0;
    }
    *out = 0;
    return 8;
}