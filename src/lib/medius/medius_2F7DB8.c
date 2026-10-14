/*
 * lib/medius: 2 files, 002F7DB8-002F7E20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F7DB8 */
typedef struct N2F7DB8 { int a; int b; int c; int d; int e; int f; int g; } N2F7DB8;
extern void func_002FB2D8(void *, int);
/* Allocates and clears a 0x1C-byte node. */
N2F7DB8 *func_002F7DB8(void)
{
    N2F7DB8 *p = 0;
    func_002FB2D8(&p, 0x1C);
    if (p) {
        p->a = 0;
        p->b = 0;
        p->d = 0;
        p->e = 0;
        p->f = 0;
        p->g = 0;
        p->c = 0;
    }
    return p;
}
/* merge_units: end func_002F7DB8 */

/* merge_units: begin func_002F7E20 */
extern void func_002FB3C0(void *);
void func_002F7E20(char *s)
{
    if (s == 0) return;
    if (*(int *)(s + 0xC)) func_002FB3C0(s + 0xC);
    if (*(int *)(s + 0x18)) func_002FB3C0(s + 0x18);
    if (*(int *)(s + 0x10)) func_002FB3C0(s + 0x10);
    if (*(int *)(s + 0x14)) func_002FB3C0(s + 0x14);
    func_002FB3C0(&s);
}
/* merge_units: end func_002F7E20 */
