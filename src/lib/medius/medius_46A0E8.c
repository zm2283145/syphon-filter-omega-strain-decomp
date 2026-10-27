/*
 * lib/medius: 2 files, 0046A0E8-0046A188
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046A0E8 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_005985BC;
unsigned int D_00497D50[1] = { 0x0 };
extern int iTerminateString_void_2(char *, int);
extern int NetSendMessage(int, int, int, int, int, int, void *);
int MediusGetGameInfo(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D50) = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_005985BC, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046A0E8 */

/* merge_units: begin func_0046A188 */
extern int D_005985C4;
int D_00497D54 = 0;
int MediusGetChannelInfo(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D54 = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_005985C4, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046A188 */
