/*
 * lib/medius: 2 files, 002F7CE8-002F7D28
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F7CE8 */
int IsNullRSAKey(int *a)
{
    unsigned int i;
    if (a != 0) {
        for (i = 0; i < 0x10; i++)
            if (a[i]) return 0;
    }
    return 1;
}
/* merge_units: end func_002F7CE8 */

/* merge_units: begin func_002F7D28 */
int IsNullRCKey(unsigned char *s)
{
    unsigned int i;
    if (s != 0) {
        for (i = 0; i < 0x40; i++)
            if (s[i]) return 0;
    }
    return 1;
}
/* merge_units: end func_002F7D28 */
