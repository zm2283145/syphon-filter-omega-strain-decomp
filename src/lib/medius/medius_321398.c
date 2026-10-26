/*
 * lib/medius: 2 files, 00321398-003214C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00321398 */
typedef struct { long magic; char pad08[0x10]; unsigned char state; char pad19[3]; char inner[0x14]; void *buf30; void *buf34; } H321;
extern unsigned short D_004E1D4C;
extern void *(*D_004E1D34)(int n, int size);
extern int func_00322E60(int);
extern int func_00323248(void);
extern int NellyInitDecodeSase3200(void *p);
extern int nciFreeDecodeSase3200(H321 **pp);
extern int printf(const char *fmt, ...);
int nciInitDecodeSase3200(H321 **pp)
{
    H321 *h;
    int r;
    if (pp == 0) return 0x181A;
    *pp = 0;
    r = func_00322E60(0);
    if (r == 1) {
        printf("\nEvaluation period has expired.\nExiting...\n\n");
        return 0x1965;
    }
    if (r == -1) {
        printf("\nClock incorrectly set.  Please adjust to correct date and time.\nExiting...\n\n");
        return 0x1965;
    }
    h = D_004E1D34(1, 0x38);
    if (h == 0) return 0x1770;
*pp = h; h->state = 11; h->magic = 0xFACE;
    if (func_00323248() == 3) {
        h->buf30 = D_004E1D34(0x1000, 1);
        if (h->buf30 == 0) return 0x1770;
        h->buf34 = D_004E1D34(0x1000, 1);
        if (h->buf34 == 0) return 0x1770;
    }
    r = NellyInitDecodeSase3200(h->inner);
    if (r) {
        nciFreeDecodeSase3200(pp);
        return 0x1770;
    }
    D_004E1D4C++;
    return r;
}
/* merge_units: end func_00321398 */

/* merge_units: begin func_003214C0 */
extern void (*D_004E1D38)(void *p);
extern void NellyFreeDecodeSase3200(void *p);
int nciFreeDecodeSase3200(H321 **pp)
{
    H321 *h;
    if (pp == 0) return 0x181A;
    if (*pp == 0 || (*pp)->magic != 0xFACE) return 0x17D4;
    if ((*pp)->state != 11) return 0x17E3;
    D_004E1D4C--;
    h = *pp;
    h->magic = 0;
    NellyFreeDecodeSase3200(h->inner);
    if (h->buf30) { D_004E1D38(h->buf30); h->buf30 = 0; }
    if (h->buf34) { D_004E1D38(h->buf34); h->buf34 = 0; }
    D_004E1D38(h);
    return 0;
}
/* merge_units: end func_003214C0 */
