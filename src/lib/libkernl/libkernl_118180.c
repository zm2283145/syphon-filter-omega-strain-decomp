/*
 * lib/libkernl: 2 files, 00118180-00118200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00118180 */
typedef struct { void *fn; void *arg; int gp; int pad; } HEnt;
extern HEnt *D_00487868;
extern int D_0048786C;
extern HEnt D_004E9AC8[];
extern int func_001161A0(void);
extern void func_001161F8(void);
extern void *memset(void *, int, unsigned int);
HEnt *func_00118180(HEnt *buf, int n)
{
    int s = func_001161A0();
    HEnt *old = D_00487868;
    D_00487868 = buf;
    D_0048786C = n;
    memset(buf, 0, n * 16);
    if (s) func_001161F8();
    return old;
}
/* merge_units: end func_00118180 */

/* merge_units: begin func_00118200 */
int func_00118200(unsigned int idx, void *fn, void *arg)
{
    HEnt *tbl;
    unsigned int max;
    int s, gp;
    if ((int)idx < 0) {
        idx &= 0x7FFFFFFF;
        tbl = D_004E9AC8;
        max = 32;
    } else {
        tbl = D_00487868;
        max = D_0048786C;
    }
    if (idx >= max) return 0x80000069;
    s = func_001161A0();
    tbl[idx].fn = fn;
    tbl[idx].arg = arg;
    __asm__ volatile ("move %0, $gp" : "=r" (gp));
    tbl[idx].gp = gp;
    if (s) func_001161F8();
    return 0;
}
/* merge_units: end func_00118200 */
