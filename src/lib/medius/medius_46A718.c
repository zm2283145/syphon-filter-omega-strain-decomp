/*
 * lib/medius: 8 files, 0046A718-0046AB38
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046A718 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00598618;
unsigned int D_00497D78[1] = { 0x0 };
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_0046A718(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D78) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598618, 0x26, a) ? -5 : 0;
}
/* merge_units: end func_0046A718 */

/* merge_units: begin func_0046A7B8 */
extern int D_00598620;
int D_00497D7C = 0;
int func_0046A7B8(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D7C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598620, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046A7B8 */

/* merge_units: begin func_0046A858 */
extern int D_00598628;
unsigned int D_00497D80[1] = { 0x0 };
int func_0046A858(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D80) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598628, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046A858 */

/* merge_units: begin func_0046A8F8 */
extern int D_00598630;
int D_00497D84 = 0;
int func_0046A8F8(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D84 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598630, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046A8F8 */

/* merge_units: begin func_0046A998 */
extern int D_005984E4;
int func_0046A998(char *a)
{
    func_004700F8(a, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005984E4, 0x118, a) ? -5 : 0;
}
/* merge_units: end func_0046A998 */

/* merge_units: begin func_0046AA18 */
extern int D_005984E0;
int func_0046AA18(char *a)
{
    func_004700F8(a, 0x11);
    func_004700F8(a + 0x1C, 0x40);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005984E0, 0x180, a) ? -5 : 0;
}
/* merge_units: end func_0046AA18 */

/* merge_units: begin func_0046AAA0 */
extern int D_005984E8;
int func_0046AAA0(char *a)
{
    func_004700F8(a, 0x11);
    func_004700F8(a + 0x18, 0x40);
    func_004700F8(a + 0x58, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005984E8, 0x7C, a) ? -5 : 0;
}
/* merge_units: end func_0046AAA0 */

/* merge_units: begin func_0046AB38 */
extern int D_0059863C;
unsigned int D_00497D88[1] = { 0x0 };
int func_0046AB38(char *a, int b)
{
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497D88) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059863C, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_0046AB38 */
