/*
 * lib/medius: 2 files, 002FCE88-002FCFE8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FCE88 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned char D_004908EC;
extern int D_004908F8;
extern int func_002FE810(int, void **);
extern int func_002F5818(void *, int *);
extern int func_00301220(int);
extern int func_002F5618(int, void *, int);
extern void func_00300AE8(void *, int, int, int);
extern void func_00301038(void *, int);
extern void func_002FED28(void *);
extern void func_002F5DB0(int);
extern void func_002FE5A8(int);
int func_002FCE88(unsigned short id)
{
    void *c = 0;
    int x = 0;
    unsigned char st = D_004908EC;
    int r;
    unsigned int i;
    void *q, *e;
    if (st != 1) return 5;
    r = func_002FE810(id, &c);
    if (r != 0) return r;
    if (c != 0) {
    if (F(c, int, 8) != st) {
        if (F(c, int, 8) == 8) {
            q = F(c, void *, 0x80);
            if (q != 0 && func_002F5818((char *)q + 0x68, &x) == 0) {
                if (x != 0) {
                    func_00301220(x);
                    if (func_002F5618(D_004908F8, (char *)q + 0x68, x) == 0)
                        func_00300AE8(q, D_004908F8, x, 10000);
                }
                func_00301038(c, 9);
                func_002FED28(q);
            }
        }
        func_00301038(c, 10);
        for (i = 0; i < 2; i++) {
            q = ((struct { char pad[0x70]; void *arr[2]; } *)((char *)c + 8))->arr[i];
            if (q) func_002F5DB0(F(q, int, 0x1C));
        }
        func_00301038(c, 1);
    }
    func_002FE5A8(id);
    }
    return 0;
}
/* merge_units: end func_002FCE88 */

/* merge_units: begin func_002FCFE8 */
extern unsigned short D_004908F0;
extern int func_002FE7C0(unsigned short);
extern int func_002FCE88(unsigned short);
int func_002FCFE8(void)
{
    unsigned int i = 0;
    int r;
    if (D_004908EC != 1) return 5;
    for (; i < D_004908F0; i++) {
        if (func_002FE7C0(i) == 1) {
            r = func_002FCE88(i);
            if (r) return r;
        }
    }
    return 0;
}
/* merge_units: end func_002FCFE8 */
