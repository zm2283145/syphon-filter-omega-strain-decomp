/*
 * lib/medius: 2 files, 0046ABD8-0046AC78
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046ABD8 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598640;
extern int D_00497D88;
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int MediusGetAllAnnouncements(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D88 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598640, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046ABD8 */

/* merge_units: begin func_0046AC78 */
extern int D_00598648;
int D_00497D8C = 0;
int MediusSetGameListFilter(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D8C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598648, 0x34, a) ? -5 : 0;
}
/* merge_units: end func_0046AC78 */
