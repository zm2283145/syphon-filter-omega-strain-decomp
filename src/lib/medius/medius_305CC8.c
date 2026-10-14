/*
 * lib/medius: 2 files, 00305CC8-00305D58
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00305CC8 */
extern int D_004912F4, D_004912F0;
extern int *D_004912F8;
extern unsigned char D_004912E8;
extern unsigned int D_0052980C;
extern unsigned int D_00529808;
/* memset declared with an int destination: the address is formed as integer base + offset like retail */
extern void *memset(int d, int c, unsigned int n);
int func_00305CC8(unsigned int idx)
{
    int ret = 3;
    int *p;
    if (D_004912E8 != 1) return ret;
    if (D_004912F0 == 0) return ret;
    if (D_004912F4 == 0) return ret;
    p = D_004912F8;
    if (p == 0) return ret;
    if (idx >= D_0052980C) return 2;
    memset((int)p + (int)(idx * D_00529808 * 4), 0, D_00529808 * 4);
    return 0;
}
/* merge_units: end func_00305CC8 */

/* merge_units: begin func_00305D58 */
extern int D_004912F0;
extern int D_004912F4;
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
/* merge_units: end func_00305D58 */
