/*
 * lib/libnet: 3 files, 0034D028-0034D128
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034D028 */
extern int func_002FB518(char *);
int func_0034D028(char *p)
{
    if (p == 0) return 2;
    if (func_002FB518(p + 0x10)) return 1;
    return func_002FB518(p + 0x18) != 0;
}
/* merge_units: end func_0034D028 */

/* merge_units: begin func_0034D080 */
extern int sceSifMCallRpc(int, int, int, void *, int, void *, int, void *, void *);
extern int func_0034A418(int, unsigned int);
int func_0034D080(int cd, int *buf)
{
    int r;
    buf[0] = 0;
    buf[8] = (int)buf;
    buf[9] = 0;
    buf[1] = 0;
    if (sceSifMCallRpc(cd, 0x64, 0, buf, 0x50, buf, 0x50, 0, 0) < 0) return 1;
    if (buf[13] == 0 || buf[13] == 3) {
        if ((unsigned int)buf[6] < (unsigned int)(buf[2] + 0x40)) return 1;
        r = func_0034A418(buf[7], buf[6]);
        if (r != 0) return r;
    }
    return 0;
}
/* merge_units: end func_0034D080 */

/* merge_units: begin func_0034D128 */
int func_0034D128(int cd, int *buf)
{
    int r;
    buf[0] = 0;
    buf[8] = (int)buf;
    buf[9] = 0;
    buf[1] = 0;
    if (sceSifMCallRpc(cd, 0x65, 0, buf, 0x50, buf, 0x50, 0, 0) < 0) return 1;
    if (buf[13] == 0 || buf[13] == 3) {
        if ((unsigned int)buf[6] < (unsigned int)(buf[2] + 0x40)) return 1;
        r = func_0034A418(buf[7], buf[6]);
        if (r != 0) return r;
    }
    return 0;
}
/* merge_units: end func_0034D128 */
