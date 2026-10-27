/*
 * lib/medius: 2 files, 002F7FB0-002F8020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F7FB0 */
extern void SHAInit(char *);
extern void SHAUpdate(char *, int, int);
extern void SHAFinal(char *, int, int);
void KM_SHA1(int a, int b, int c, int d)
{
    char ctx[0x60];
    SHAInit(ctx);
    SHAUpdate(ctx, a, b);
    SHAFinal(ctx, c, d);
}
/* merge_units: end func_002F7FB0 */

/* merge_units: begin func_002F8020 */
#if 0 /* merge_units */
extern void SHAUpdate(char *, char *, char *);
#endif /* merge_units */
#define SHAUpdate(a0, a1, a2) (SHAUpdate((a0), (int)(a1), (int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void SHAFinal(char *, char *, char *);
#endif /* merge_units */
#define SHAFinal(a0, a1, a2) (SHAFinal((a0), (int)(a1), (int)(a2))) /* merge_units */

void KM_Salted_SHA1(char *a, char *b, char *c, char *d, char *e, char *f)
{
    char ctx[0x60];
    SHAInit(ctx);
    if (a && b) SHAUpdate(ctx, a, b);
    SHAUpdate(ctx, c, d);
    SHAFinal(ctx, e, f);
}
#undef SHAUpdate /* merge_units */
#undef SHAFinal /* merge_units */
/* merge_units: end func_002F8020 */
