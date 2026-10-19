/*
 * lib/medius: 2 files, 0046C710-0046C7A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046C710 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598820;
unsigned int D_00497E18[1] = { 0x0 };
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046C710(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497E18) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 0x4, D_00598820, 0x20, a) ? -5 : 0;
}
/* merge_units: end func_0046C710 */

/* merge_units: begin func_0046C7A0 */
extern int D_00598864;
int D_00497E1C = 0;
int func_0046C7A0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497E1C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 0x4, D_00598864, 0x15, a) ? -5 : 0;
}
/* merge_units: end func_0046C7A0 */
