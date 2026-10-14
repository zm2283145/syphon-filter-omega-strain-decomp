/*
 * lib/medius: 2 files, 002F2B38-002F2B98
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F2B38 */
extern void func_002F2C28(char *);
extern void func_002F2C68(char *, int, int);
extern void func_002F2DC8(int, char *);
void func_002F2B38(int a, int b, int c)
{
    char ctx[0x60];
    func_002F2C28(ctx);
    func_002F2C68(ctx, a, b);
    func_002F2DC8(c, ctx);
}
/* merge_units: end func_002F2B38 */

/* merge_units: begin func_002F2B98 */
#if 0 /* merge_units */
extern void func_002F2C68(char *, char *, char *);
#endif /* merge_units */
#define func_002F2C68(a0, a1, a2) (func_002F2C68((a0), (int)(a1), (int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void func_002F2DC8(char *, char *);
#endif /* merge_units */
#define func_002F2DC8(a0, a1) (func_002F2DC8((int)(a0), (a1))) /* merge_units */

void func_002F2B98(char *a, char *b, char *c, char *d, char *e)
{
    char ctx[0x60];
    func_002F2C28(ctx);
    if (a && b) func_002F2C68(ctx, a, b);
    func_002F2C68(ctx, c, d);
    func_002F2DC8(e, ctx);
}
#undef func_002F2C68 /* merge_units */
#undef func_002F2DC8 /* merge_units */
/* merge_units: end func_002F2B98 */
