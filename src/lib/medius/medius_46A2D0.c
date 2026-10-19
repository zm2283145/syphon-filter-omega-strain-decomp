/*
 * lib/medius: 2 files, 0046A2D0-0046A378
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046A2D0 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_005985CC;
unsigned int D_00497D58[1] = { 0x0 };
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046A2D0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x26, 0x40);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D58) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005985CC, 0x6C, a) ? -5 : 0;
}
/* merge_units: end func_0046A2D0 */

/* merge_units: begin func_0046A378 */
extern int D_005985DC;
int func_0046A378(char *a)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x30, 0x40);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005985DC, 0x70, a) ? -5 : 0;
}
/* merge_units: end func_0046A378 */
