/*
 * lib/medius: 2 files, 002E1500-002E1578
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E1500 */
extern void *memset(void *, int, unsigned int);
typedef struct { int a0; int a4; char a8; char pad[11]; int a14, a18, a1C, a20, a24, a28, a2C, a30, a34; } S2E1500;
int func_002E1500(S2E1500 *p)
{
    if (p == 0) return 0x17;
    memset(p, 0, 0x38);
    p->a4 = -1;
    p->a1C = 2;
    p->a8 = 0;
    p->a14 = 0;
    p->a18 = 0;
    p->a20 = 0;
    p->a24 = 0;
    p->a28 = 0;
    p->a2C = 0;
    p->a30 = 0;
    p->a34 = 0;
    p->a0 = 1;
    return 0;
}
/* merge_units: end func_002E1500 */

/* merge_units: begin func_002E1578 */
extern int func_002E15E0(int *);
int func_002E1578(int *a, int *st)
{
    int r;
    if (st == 0) return 0x17;
    st[1] = 0x1E;
    st[0] = 1;
    if (a == 0) {
        st[1] = 0x17;
        return 0x17;
    }
    if (*a != 1) return 0x26;
    r = func_002E15E0(a);
    st[1] = r;
    return r;
}
/* merge_units: end func_002E1578 */
