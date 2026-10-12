extern unsigned char D_004912E8;
extern int D_004912F0;
extern int D_004912F4;
extern int *D_004912F8;
extern unsigned int D_0052980C;
extern unsigned int D_00529808;
int func_00305D58(unsigned int idx, int *out, unsigned int n)
{
    unsigned int i;
    if (D_004912E8 != 1) return 3;
    if (D_004912F0 == 0) return 3;
    if (D_004912F4 == 0) return 3;
    if (D_004912F8 == 0) return 3;
    if (idx >= D_0052980C) return 2;
    if (out == 0) return 2;
    if (n < D_00529808) return 2;
    for (i = 0; i < D_00529808; i++)
        *out++ = D_004912F8[idx * D_00529808 + i];
    return 0;
}
