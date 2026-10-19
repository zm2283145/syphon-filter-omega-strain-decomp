/*
 * lib/medius: 2 files, 002F2B38-002F2B98
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F2B38 */
extern void Md5_Init(char *);
extern void Md5_Update(char *, int, int);
extern void Md5_Final(int, char *);
void Md5_Digest(int a, int b, int c)
{
    char ctx[0x60];
    Md5_Init(ctx);
    Md5_Update(ctx, a, b);
    Md5_Final(c, ctx);
}
/* merge_units: end func_002F2B38 */

/* merge_units: begin func_002F2B98 */
#if 0 /* merge_units */
extern void Md5_Update(char *, char *, char *);
#endif /* merge_units */
#define Md5_Update(a0, a1, a2) (Md5_Update((a0), (int)(a1), (int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void Md5_Final(char *, char *);
#endif /* merge_units */
#define Md5_Final(a0, a1) (Md5_Final((int)(a0), (a1))) /* merge_units */

void Md5_Digest2(char *a, char *b, char *c, char *d, char *e)
{
    char ctx[0x60];
    Md5_Init(ctx);
    if (a && b) Md5_Update(ctx, a, b);
    Md5_Update(ctx, c, d);
    Md5_Final(e, ctx);
}
#undef Md5_Update /* merge_units */
#undef Md5_Final /* merge_units */
/* merge_units: end func_002F2B98 */
