/*
 * lib/medius: 2 files, 004697A0-00469818
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004697A0 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598548;
unsigned int D_00497D20[1] = { 0x0 };
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_004697A0(char *a, int b)
{

    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D20) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598548, 0x46, a) ? -5 : 0;
}
/* merge_units: end func_004697A0 */

/* merge_units: begin func_00469818 */
extern int D_00598550;
int D_00497D24 = 0;
int func_00469818(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    func_004700F8(a + 0x26, 0x20);
    func_004700F8(a + 0x46, 0x100);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D24 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598550, 0x146, a) ? -5 : 0;
}
/* merge_units: end func_00469818 */
