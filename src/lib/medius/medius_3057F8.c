/*
 * lib/medius: 2 files, 003057F8-00305908
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003057F8 */
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
/* merge_units: end func_003057F8 */

/* merge_units: begin func_00305908 */
extern int D_004912F4, D_004912F0, D_004912EC, D_004912F8;
extern int func_002FB3C0(int *pp);
int func_00305908(void)
{
    if (D_004912F4) func_002FB3C0(&D_004912F4);
    if (D_004912F0) func_002FB3C0(&D_004912F0);
    if (D_004912EC) func_002FB3C0(&D_004912EC);
    if (D_004912F8) func_002FB3C0(&D_004912F8);
    D_004912E8 = 0;
    return 0;
}
/* merge_units: end func_00305908 */
