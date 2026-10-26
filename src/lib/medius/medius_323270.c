/*
 * lib/medius: 3 files, 00323270-00323330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00323270 */
extern int D_004E1D50;
extern void nvuInitVuFft4CFG(void);
int updateVuFft(void)
{
    int ret = 0;
    switch (D_004E1D50) {
    case 0:
        break;
    case 1:
        nvuInitVuFft4CFG();
        break;
    case 2:
        break;
    case 3:
        nvuInitVuFft4CFG();
        break;
    default:
        D_004E1D50 = 0;
        ret = -1;
        break;
    }
    return ret;
}
/* merge_units: end func_00323270 */

/* merge_units: begin func_003232E0 */
typedef int (*CopyFn3232E0)(void* dst, void* src, int n);
extern CopyFn3232E0 D_004E1D40;
extern char D_00476B00[];
extern char D_00477AE8[];
extern char D_004B6F90[];
void nvuInitVuFft4CFG(void)
{
    D_004E1D40((void*)0x11000000, D_00476B00, D_00477AE8 - D_00476B00);
    D_004E1D40((void*)0x11004800, D_004B6F90, 0x7E0);
}
/* merge_units: end func_003232E0 */

/* merge_units: begin func_00323330 */
extern void rFft_vu4(float *re, float *im, int n);

void nvuFftCenter512(float *in, int n, int bits, float *re, float *im)
{
    int q = n >> 2;
    int h = n >> 1;
    int size = 1 << bits;
    float *pr = re + (256 - q);
    float *pi = im + (256 - q);
    int i, m;

    for (i = 0; i < q; i++) {
        *pr++ = *in++;
        *pi++ = *in++;
    }
    pr = re;
    pi = im;
    m = (n - q * 2) >> 1;
    for (i = 0; i < m; i++) {
        *pr++ = *in++;
        *pi++ = *in++;
    }
    if (n != h * 2) {
        *pr++ = *in++;
        *pi++ = 0;
        i++;
    }
    for (; i < 256 - q; i++) {
        *pr++ = 0;
        *pi++ = 0;
    }
    rFft_vu4(re, im, size / 2);
}
/* merge_units: end func_00323330 */
