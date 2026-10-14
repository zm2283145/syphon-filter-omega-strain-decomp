/*
 * lib/medius: 2 files, 0046B000-0046B0A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046B000 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598738;
unsigned int D_00497DA0[1] = { 0x0 };
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046B000(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DA0) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598738, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_0046B000 */

/* merge_units: begin func_0046B0A0 */
extern int D_00598740;
int D_00497DA4 = 0;
int func_0046B0A0(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497DA4 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598740, 0x38, a) ? -5 : 0;
}
/* merge_units: end func_0046B0A0 */
