/*
 * lib/medius: 2 files, 002F7FB0-002F8020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F7FB0 */
extern void func_00313A20(char *);
extern void Sha1_Update(char *, int, int);
extern void Sha1_Final(char *, int, int);
void Sha1_Digest(int a, int b, int c, int d)
{
    char ctx[0x60];
    func_00313A20(ctx);
    Sha1_Update(ctx, a, b);
    Sha1_Final(ctx, c, d);
}
/* merge_units: end func_002F7FB0 */

/* merge_units: begin func_002F8020 */
#if 0 /* merge_units */
extern void Sha1_Update(char *, char *, char *);
#endif /* merge_units */
#define Sha1_Update(a0, a1, a2) (Sha1_Update((a0), (int)(a1), (int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void Sha1_Final(char *, char *, char *);
#endif /* merge_units */
#define Sha1_Final(a0, a1, a2) (Sha1_Final((a0), (int)(a1), (int)(a2))) /* merge_units */

void Sha1_Digest2(char *a, char *b, char *c, char *d, char *e, char *f)
{
    char ctx[0x60];
    func_00313A20(ctx);
    if (a && b) Sha1_Update(ctx, a, b);
    Sha1_Update(ctx, c, d);
    Sha1_Final(ctx, e, f);
}
#undef Sha1_Update /* merge_units */
#undef Sha1_Final /* merge_units */
/* merge_units: end func_002F8020 */
