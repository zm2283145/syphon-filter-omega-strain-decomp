/*
 * lib/medius: 2 files, 0046C5F0-0046C680
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046C5F0 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598814;
extern int D_00497E10;
extern int iTerminateString_void_2(char *, int);
extern int NetSendMessage(int, int, int, int, int, int, void *);
int MediusUpdateLadderStatsWide(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497E10 = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 0x4, D_00598814, 0x1AC, a) ? -5 : 0;
}
/* merge_units: end func_0046C5F0 */

/* merge_units: begin func_0046C680 */
extern int D_0059881C;
int D_00497E14 = 0;
int MediusGetLadderStats(char *a, int b)
{
    iTerminateString_void_2(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497E14 = b;
    return NetSendMessage(0x40, D_00497CC4, 0xFFFF, 1, D_0059881C, 0x1C, a) ? -5 : 0;
}
/* merge_units: end func_0046C680 */
