/*
 * lib/libkernl: 2 files, 00116278-001162B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00116278 */
int kCopy_void_2(volatile unsigned int* d, volatile unsigned int* s, unsigned int n)
{
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++) *d++ = *s++;
    return 0;
}
/* merge_units: end func_00116278 */

/* merge_units: begin func_001162B0 */
int *kFindAddress(int *p, int *end, int val)
{
    while (*p != val && p < end) p++;
    return p < end ? p : 0;
}
/* merge_units: end func_001162B0 */
