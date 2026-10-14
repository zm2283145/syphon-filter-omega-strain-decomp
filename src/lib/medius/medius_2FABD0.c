/*
 * lib/medius: 2 files, 002FABD0-002FAC20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FABD0 */
extern int func_002FAF18(char *);
int func_002FABD0(char *o, int *out)
{
    if (func_002FAF18(o) == 0) return 2;
    *out = *(int *)(o + 0x14);
    return 0;
}
/* merge_units: end func_002FABD0 */

/* merge_units: begin func_002FAC20 */
extern int func_002FAF00(int);
int func_002FAC20(char *o, int *out)
{
    int v;
    if (func_002FAF18(o) == 0) return 2;
    *out = *(int *)(o + 0x14);
    while ((v = func_002FAF00(*out)) != 0) *out = func_002FAF00(*out);
    return 0;
}
/* merge_units: end func_002FAC20 */
