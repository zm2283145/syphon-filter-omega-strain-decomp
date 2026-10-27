/*
 * lib/medius: 2 files, 0046A5F0-0046A690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046A5F0 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_0059860C;
int D_00497D74 = 0;
extern int iTerminateString_void_2(char *, int);
extern int NetSendMessage(int, int, int, int, int, int, void *);
int MediusBuddyGetPermission(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D74 = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 0x4, D_0059860C, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_0046A5F0 */

/* merge_units: begin func_0046A690 */
extern int D_005985FC;
int MediusBuddyAddConfirmation(char *a)
{
    iTerminateString_void_2(a, 0x15);
    iTerminateString_void_2(a + 0x1C, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 0x4, D_005985FC, 0x38, a) ? -5 : 0;
}
/* merge_units: end func_0046A690 */
