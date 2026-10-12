extern unsigned char D_004912E8;
extern int D_004912EC, D_004912F0, D_004912F4, D_004912F8;
extern unsigned int D_00529808, D_0052980C;
extern unsigned int D_00529810;
extern int Net_AllocZeroed(void *pp, unsigned long n);

int NetMsg_AllocTables(unsigned int n, unsigned int a, unsigned int b)
{
    unsigned int sz;
    unsigned char *init = &D_004912E8;
    if (*init != 0) return 1;
    if (a > 0x100) return 2;
    if (b > 0x100) return 2;
    D_00529808 = a;
    D_0052980C = b;
    D_00529810 = n;
    if (Net_AllocZeroed(&D_004912F4, b * 4) != 0) return 6;
    sz = b * a * 4;
    if (Net_AllocZeroed(&D_004912F0, sz) != 0) return 6;
    if (Net_AllocZeroed(&D_004912EC, n) != 0) return 6;
    if (Net_AllocZeroed(&D_004912F8, sz) != 0) return 6;
    *init = 1;
    return 0;
}
