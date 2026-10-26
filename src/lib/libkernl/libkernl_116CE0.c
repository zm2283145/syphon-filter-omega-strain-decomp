/*
 * lib/libkernl: 2 files, 00116CE0-00116D70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00116CE0 */
extern int DIntr(void);
extern void EIntr(void);
extern void SetT2_MODE(unsigned int);
extern int iGetTimerSystemTime(void);
extern void SetNextComp(int);

int StartTimerSystemTime(void)
{
    int s = DIntr();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (v & 0x80) {
        if (s) EIntr();
        return 1;
    }
    SetT2_MODE((v & ~0xC00) | 0x80);
    SetNextComp(iGetTimerSystemTime());
    if (s) EIntr();
    return 0;
}
/* merge_units: end func_00116CE0 */

/* merge_units: begin func_00116D70 */
int StopTimerSystemTime(void)
{
    int s = DIntr();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (!(v & 0x80)) {
        if (s) EIntr();
        return 0;
    }
    SetT2_MODE(v & ~0xC80);
    if (s) EIntr();
    return 1;
}
/* merge_units: end func_00116D70 */
