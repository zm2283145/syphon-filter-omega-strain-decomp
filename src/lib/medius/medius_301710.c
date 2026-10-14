/*
 * lib/medius: 4 files, 00301710-003017F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00301710 */
extern int func_002F9780(int id, int mask, int a, int b);
int func_00301710(unsigned short id, int *out)
{
    int ret = 2;
    if (out == 0) return ret;
    *out = func_002F9780(id, 0xFFFF, 0, 0);
    return 0;
}
/* merge_units: end func_00301710 */

/* merge_units: begin func_00301758 */
extern int func_00301710(unsigned short id, int *out);
int func_00301758(unsigned short id, unsigned char *out)
{
    int l = 0;
    int ret = 2;
    if (out == 0) return ret;
    *out = 0;
    ret = func_00301710(id, &l);
    if (ret != 0) return ret;
    if (l != 0) *out = 1;
    return ret;
}
/* merge_units: end func_00301758 */

/* merge_units: begin func_003017B0 */
int func_003017B0(unsigned int idx, unsigned char en, unsigned char lvl, int unused, unsigned char *out)
{
    int ret = 2;
    if (out == 0) return ret;
    *out = 0;
    if (idx >= 2) return ret;
    if (en != 0 && lvl >= 7) *out = 1;
    return 0;
}
/* merge_units: end func_003017B0 */

/* merge_units: begin func_003017F8 */
int func_003017F8(unsigned int idx, unsigned char *a, unsigned char *b, unsigned char *c)
{
    int ret = 2;
    if (idx >= 2) return ret;
    if (a == 0) return ret;
    if (b == 0) return ret;
    if (c == 0) return ret;
    *a = 1;
    *b = 8;
    *c = 0x84;
    return 0;
}
/* merge_units: end func_003017F8 */
