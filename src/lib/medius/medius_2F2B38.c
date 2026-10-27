/*
 * lib/medius: 2 files, 002F2B38-002F2B98
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F2B38 */
extern void md5Init(char *);
extern void md5Update(char *, int, int);
extern void md5Final(int, char *);
void KM_MD5(int a, int b, int c)
{
    char ctx[0x60];
    md5Init(ctx);
    md5Update(ctx, a, b);
    md5Final(c, ctx);
}
/* merge_units: end func_002F2B38 */

/* merge_units: begin func_002F2B98 */
#if 0 /* merge_units */
extern void md5Update(char *, char *, char *);
#endif /* merge_units */
#define md5Update(a0, a1, a2) (md5Update((a0), (int)(a1), (int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void md5Final(char *, char *);
#endif /* merge_units */
#define md5Final(a0, a1) (md5Final((int)(a0), (a1))) /* merge_units */

void KM_Salted_MD5(char *a, char *b, char *c, char *d, char *e)
{
    char ctx[0x60];
    md5Init(ctx);
    if (a && b) md5Update(ctx, a, b);
    md5Update(ctx, c, d);
    md5Final(e, ctx);
}
#undef md5Update /* merge_units */
#undef md5Final /* merge_units */
/* merge_units: end func_002F2B98 */
