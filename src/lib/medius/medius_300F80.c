/*
 * lib/medius: 3 files, 00300F80-00301060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00300F80 */
int func_00300F80(int x)
{
    if (x == 2 || x == 0xB || x == 5 || x == 0xE || x == 0xF || x == 0x10 || x == 0 || x == 0x15 || x == 0x16 || x == 0x17 || x == 0xD || x == 0x12 || x == 0x1B || x == 3 || x == 0x1D) return 1;
    return 0;
}
/* merge_units: end func_00300F80 */

/* merge_units: begin func_00301038 */
typedef struct { int f0; int f4; unsigned int f8; } ScfObj_038;
int func_00301038(ScfObj_038 *o, unsigned int v)
{
    int ret = 2;
    if (o == 0) return ret;
    if (v >= 12) return 0x17;
    o->f8 = v;
    return 0;
}
/* merge_units: end func_00301038 */

/* merge_units: begin func_00301060 */
int func_00301060(int x)
{
    if (x == 2 || x == 4 || x == 3 || x == 5 || x == 6 || x == 7 || x == 9 || x == 10) return 1;
    return 0;
}
/* merge_units: end func_00301060 */
