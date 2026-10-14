/*
 * lib/medius: 2 files, 002E0098-002E0118
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E0098 */
extern void *memset(void *, int, unsigned int);
extern unsigned short D_0058C0B0;
extern int func_00314430(int *);
int func_002E0098(int *p)
{
    int r;
    if (p == 0) return 0x17;
    memset(p, 0, 0x128);
    p[1] = 0x100;
    p[2] = 0;
    p[0x49] = D_0058C0B0 + 1;
    p[0x29] = 0;
    p[0x2B] = 0;
    p[0x2D] = 0;
    p[0x2F] = 0;
    p[0x31] = 0;
    p[0x32] = 0;
    r = func_00314430(p + 0x33);
    if (r) return r;
    p[0] = 1;
    return 0;
}
/* merge_units: end func_002E0098 */

/* merge_units: begin func_002E0118 */
extern int func_002E6010(void);
extern int func_002E0210(int *, int *, int *);
extern int func_002E0760(int *, int *, int *);
int func_002E0118(int *req, int *res)
{
    int r, t; int *k;
    if (res == 0) return 0x17;
    res[1] = 3;
    res[0] = 1;
    r = func_002E6010();
    if (r) return r;
    if (req == 0) {
        res[1] = 0x17;
        return 0x17;
    }
    if (*req != 1) {
        res[1] = 0x26;
        return 0x26;
    }
    k = req + 2; t = *k;
    if (t == 1 || t == 3 || t == 4) res[1] = func_002E0210(req, k, res);
    else if (t == 2) res[1] = func_002E0760(req, k, res);
    else res[1] = 0x17;
    return res[1];
}
/* merge_units: end func_002E0118 */
