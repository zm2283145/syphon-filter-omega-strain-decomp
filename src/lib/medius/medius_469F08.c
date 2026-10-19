/*
 * lib/medius: 2 files, 00469F08-00469FA8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00469F08 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_005985A4;
unsigned int D_00497D28[1] = { 0x0 };
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_00469F08(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D28) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005985A4, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_00469F08 */

/* merge_units: begin func_00469FA8 */
extern int D_005985AC;
int D_00497D2C = 0;
int func_00469FA8(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D2C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005985AC, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_00469FA8 */
