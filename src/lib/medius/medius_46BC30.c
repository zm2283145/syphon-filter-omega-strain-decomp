/*
 * lib/medius: 6 files, 0046BC30-0046BF50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046BC30 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_0059878C;
unsigned int D_00497DC8[1] = { 0x0 };
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046BC30(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DC8) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059878C, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046BC30 */

/* merge_units: begin func_0046BCD0 */
extern int D_00598794;
int D_00497DCC = 0;
int func_0046BCD0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497DCC = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598794, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046BCD0 */

/* merge_units: begin func_0046BD70 */
extern int D_0059879C;
unsigned int D_00497DD0[1] = { 0x0 };
int func_0046BD70(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DD0) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059879C, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046BD70 */

/* merge_units: begin func_0046BE10 */
extern int D_005987A4;
int D_00497DD4 = 0;
int func_0046BE10(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497DD4 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987A4, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046BE10 */

/* merge_units: begin func_0046BEB0 */
extern int D_005987AC;
unsigned int D_00497DD8[1] = { 0x0 };
int func_0046BEB0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DD8) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987AC, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_0046BEB0 */

/* merge_units: begin func_0046BF50 */
extern int D_005987B4;
int D_00497DDC = 0;
int func_0046BF50(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497DDC = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987B4, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_0046BF50 */
