/*
 * lib/medius: 4 files, 00469000-004691D8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00469000 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int iTerminateString_void_2(char *, int);
extern int NetSendMessage(int, int, int, int, int, int, void *);extern int D_005984F0;
unsigned int D_00497CF8[1] = { 0x0 };
int MediusSessionBegin(char *a, int b)
{
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    iTerminateString_void_2(a, 0x15);
    (*(int*)D_00497CF8) = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_005984F0, 0x1C, a) ? -5 : 0;
}
/* merge_units: end func_00469000 */

/* merge_units: begin func_004690A0 */
extern int D_005984F8;
int D_00497CFC = 0;
int MediusSessionEnd(char *a, int b)
{
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    iTerminateString_void_2(a + 0x15, 0x11);
    iTerminateString_void_2(a, 0x15);
    D_00497CFC = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_005984F8, 0x26, a) ? -5 : 0;
}
/* merge_units: end func_004690A0 */

/* merge_units: begin func_00469150 */
extern int D_00598500;
int MediusMachineSignature(char *a)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_00598500, 0xA6, a) ? -5 : 0;
}
/* merge_units: end func_00469150 */

/* merge_units: begin func_004691D8 */
extern int D_00598504;
int MediusDnasSignature(char *a)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 0x4, D_00598504, 0x50, a) ? -5 : 0;
}
/* merge_units: end func_004691D8 */
