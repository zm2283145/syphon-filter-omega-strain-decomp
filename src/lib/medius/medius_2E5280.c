/*
 * lib/medius: 2 files, 002E5280-002E52D8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E5280 */
extern int D_0051FED8[];
extern void DmeFree(int *);

int NetDestroyConnInfo(unsigned int i)
{
    int *p;

    if (i >= 4) {
        return 0x17;
    }
    p = &D_0051FED8[i];
    if (*p != 0) {
        DmeFree(p);
    }
    *p = 0;
    return 0;
}
/* merge_units: end func_002E5280 */

/* merge_units: begin func_002E52D8 */
typedef struct { int v[256]; } T2E52D8;
extern int NetGetConnInfo(unsigned int, T2E52D8 **);
int NetGetClientInfo(unsigned int a, unsigned int b, int *out)
{
    T2E52D8 *p = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (a >= 4) return 0x17;
    if (b >= 0x100) return 0x17;
    r = NetGetConnInfo(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    *out = p->v[b];
    return r;
}
/* merge_units: end func_002E52D8 */
