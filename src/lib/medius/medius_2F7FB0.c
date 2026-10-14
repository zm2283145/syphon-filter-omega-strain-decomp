/*
 * lib/medius: 2 files, 002F7FB0-002F8020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F7FB0 */
extern void func_00313A20(char *);
extern void func_00313AE8(char *, int, int);
extern void func_00313C80(char *, int, int);
void func_002F7FB0(int a, int b, int c, int d)
{
    char ctx[0x60];
    func_00313A20(ctx);
    func_00313AE8(ctx, a, b);
    func_00313C80(ctx, c, d);
}
/* merge_units: end func_002F7FB0 */

/* merge_units: begin func_002F8020 */
#if 0 /* merge_units */
extern void func_00313AE8(char *, char *, char *);
#endif /* merge_units */
#define func_00313AE8(a0, a1, a2) (func_00313AE8((a0), (int)(a1), (int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void func_00313C80(char *, char *, char *);
#endif /* merge_units */
#define func_00313C80(a0, a1, a2) (func_00313C80((a0), (int)(a1), (int)(a2))) /* merge_units */

void func_002F8020(char *a, char *b, char *c, char *d, char *e, char *f)
{
    char ctx[0x60];
    func_00313A20(ctx);
    if (a && b) func_00313AE8(ctx, a, b);
    func_00313AE8(ctx, c, d);
    func_00313C80(ctx, e, f);
}
#undef func_00313AE8 /* merge_units */
#undef func_00313C80 /* merge_units */
/* merge_units: end func_002F8020 */
