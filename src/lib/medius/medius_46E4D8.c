/*
 * lib/medius: 2 files, 0046E4D8-0046E530
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046E4D8 */
extern int D_00497CE8;
extern void (*D_00497DE4)(void);
int MediusUniqueCallbackUniverseNewsHandler(int a0, int a1, int a2, signed char* p)
{
    if (p[0x11C] == 1)
        D_00497CE8 |= 2;
    if (D_00497DE4)
        D_00497DE4();
    return 0x120;
}
/* merge_units: end func_0046E4D8 */

/* merge_units: begin func_0046E530 */
extern void (*D_00497DE8)(void);
int MediusUniqueCallbackUniverseStatusListHandler(int a0, int a1, int a2, signed char* p)
{
    if (p[0x22C] == 1)
        D_00497CE8 |= 1;
    if (D_00497DE8)
        D_00497DE8();
    return 0x230;
}
/* merge_units: end func_0046E530 */
