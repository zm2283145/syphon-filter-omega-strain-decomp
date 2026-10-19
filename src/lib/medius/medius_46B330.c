/*
 * lib/medius: 4 files, 0046B330-0046B510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046B330 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598760;
unsigned int D_00497DB0[1] = { 0x0 };
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046B330(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DB0) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598760, 0x38, a) ? -5 : 0;
}
/* merge_units: end func_0046B330 */

/* merge_units: begin func_0046B3D0 */
extern int D_00598768;
int D_00497DB4 = 0;
int func_0046B3D0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497DB4 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598768, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_0046B3D0 */

/* merge_units: begin func_0046B470 */
extern int D_00598770;
unsigned int D_00497DB8[1] = { 0x0 };
int func_0046B470(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DB8) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598770, 0x3C, a) ? -5 : 0;
}
/* merge_units: end func_0046B470 */

/* merge_units: begin func_0046B510 */
extern int D_00598778;
int D_00497DBC = 0;
int func_0046B510(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497DBC = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598778, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046B510 */
