/*
 * lib/medius: 2 files, 002DD968-002DD9B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DD968 */
extern int D_005880B0[];
int NetIGetObject(int *out, unsigned int idx)
{
    if (out == 0) return 0x17;
    if (idx < 0x1000) {
        *out = D_005880B0[idx];
        return 0;
    }
    *out = 0;
    return 8;
}
/* merge_units: end func_002DD968 */

/* merge_units: begin func_002DD9B0 */
extern int NetGetStreamChannel(int, int *);
int NetIGetDataStream(int *out, int a)
{
    int t = 0;
    int r = NetGetStreamChannel(a, &t);
    if (r) return r;
    if (t) *out = t;
    return 0;
}
/* merge_units: end func_002DD9B0 */
