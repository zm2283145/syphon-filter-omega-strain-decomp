/*
 * lib/medius: 2 files, 0046B1E0-0046B280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046B1E0 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598748;
unsigned int D_00497DA8[1] = { 0x0 };
extern int iTerminateString_void_2(char *, int);
extern int NetSendMessage(int, int, int, int, int, int, void *);
int MediusGetLocations(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DA8) = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_00598748, 0x26, a) ? -5 : 0;
}
/* merge_units: end func_0046B1E0 */

/* merge_units: begin func_0046B280 */
extern int D_00598750;
int D_00497DAC = 0;
int MediusPickLocation(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497DAC = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_00598750, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046B280 */
