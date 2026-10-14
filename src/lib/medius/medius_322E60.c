/*
 * lib/medius: 2 files, 00322E60-00322E70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00322E60 */
int func_00322E60(void)
{
    volatile char buf[16];
    return 0;
}
/* merge_units: end func_00322E60 */

/* merge_units: begin func_00322E70 */
typedef void *(*CopyFnE70)(void *dst, void *src, int n);
extern CopyFnE70 D_004E1D40;
extern unsigned long long D_00476B00[];
extern unsigned long long D_00477350[];
extern unsigned long long fft256_mpg[];
__asm__("fft256_mpg = D_00476B00");
extern int func_00103D40(int);
extern int func_00104310(int, int, int);
void func_00322E70(float *re, float *im, int n)
{
    int addr;
    D_004E1D40((void *)0x11004000, re, n * 4);
    D_004E1D40((void *)0x11004400, im, n * 4);
    if (n == 256)
        addr = fft256_mpg - D_00476B00;
    else
        addr = D_00477350 - D_00476B00;
    func_00104310(func_00103D40(0), 0, 0);
    __asm__ volatile("ctc2.ni %0, $vi27\n\tsync.p\n\tsync\n\tsync.p\n\tvnop\n\tvcallmsr $vi27\n\tvnop" : : "r"(addr));
    D_004E1D40(re, (void *)0x11004000, n * 4);
    D_004E1D40(im, (void *)0x11004400, n * 4);
}
/* merge_units: end func_00322E70 */
