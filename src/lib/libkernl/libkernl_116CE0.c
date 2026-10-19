/*
 * lib/libkernl: 2 files, 00116CE0-00116D70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00116CE0 */
extern int DIntr(void);
extern void EIntr(void);
extern void func_00116A80(unsigned int);
extern int func_001172E0(void);
extern void func_00116DF0(int);

int func_00116CE0(void)
{
    int s = DIntr();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (v & 0x80) {
        if (s) EIntr();
        return 1;
    }
    func_00116A80((v & ~0xC00) | 0x80);
    func_00116DF0(func_001172E0());
    if (s) EIntr();
    return 0;
}
/* merge_units: end func_00116CE0 */

/* merge_units: begin func_00116D70 */
int func_00116D70(void)
{
    int s = DIntr();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (!(v & 0x80)) {
        if (s) EIntr();
        return 0;
    }
    func_00116A80(v & ~0xC80);
    if (s) EIntr();
    return 1;
}
/* merge_units: end func_00116D70 */
