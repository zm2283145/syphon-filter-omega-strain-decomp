/*
 * lib/medius: 2 files, 002FB580-002FB5C8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FB580 */
int func_002FB580(unsigned int *out, unsigned int v, unsigned short align)
{
    if (out == 0 || v == 0) return 1;
    *out = v;
    if (align >= 2) {
        unsigned int r = v % align;
        if (r) *out = v + (align - r);
    }
    return 0;
}
/* merge_units: end func_002FB580 */

/* merge_units: begin func_002FB5C8 */
static const unsigned int dat_00490908[2] = { 0x0, 0x0 };
extern int func_002F8908(int, int);
int func_002FB5C8(void)
{
    if ((*(int*)dat_00490908) == 0) {
        if (func_002F8908(0, 0) == 0) (*(int*)dat_00490908) = 1;
        else (*(int*)dat_00490908) = 2;
    }
    return (*(int*)dat_00490908);
}
/* merge_units: end func_002FB5C8 */
