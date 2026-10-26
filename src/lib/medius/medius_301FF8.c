/*
 * lib/medius: 2 files, 00301FF8-00302088
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00301FF8 */
static unsigned char D_004AF5E8[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
extern unsigned int randomMT(void);
void randomMTSetCharArray(char *buf, unsigned int n)
{
    unsigned int i = 0;
    if (n == 0) return;
    for (; i < n - 1; i++)
        buf[i] = D_004AF5E8[randomMT() & 0x3F];
    buf[n - 1] = 0;
}
/* merge_units: end func_00301FF8 */

/* merge_units: begin func_00302088 */
extern int setNewSeed_platform(unsigned long x);
int setNewSeed(unsigned int x)
{
    return setNewSeed_platform(x);
}
/* merge_units: end func_00302088 */
