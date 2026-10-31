typedef void *(*CopyFnE70)(void *dst, void *src, int n);
extern CopyFnE70 D_004E1D40;
extern unsigned long long D_00476B00[];
extern unsigned long long D_00477350[];
extern unsigned long long D_00477908[];
extern unsigned long long fft256_mpg[];
__asm__("fft256_mpg = D_00476B00");
extern float D_004B6B90[];
extern float D_004B6F90[];
extern int sceDmaGetChan(int);
extern int sceDmaSync_2(int, int, int);
void rFft_vu4(float *re, float *im, int n)
{
    int addr;
    float r0, i0, rh, ih;
    float *p, *q;
    if (n == 256)
        addr = fft256_mpg - D_00476B00;
    else
        addr = D_00477350 - D_00476B00;
    D_004E1D40((void *)0x11004000, re, n * 4);
    D_004E1D40((void *)0x11004400, im, n * 4);
    sceDmaSync_2(sceDmaGetChan(0), 0, 0);
    __asm__ volatile("ctc2.ni %0, $vi27\n\tsync.p\n\tsync\n\tsync.p\n\tvnop\n\tvcallmsr $vi27\n\tvnop" : : "r"(addr));
    addr = D_00477908 - D_00476B00;
    r0 = *(float *)0x11004000;
    i0 = *(float *)0x11004400;
    p = (float *)0x11004000 + (n >> 1);
    q = (float *)0x11004400 + (n >> 1);
    rh = *p;
    ih = *q;
    D_004E1D40((void *)0x11004800, D_004B6B90, n * 4);
    __asm__ volatile("ctc2.ni %0, $vi27\n\tsync.p\n\tsync\n\tsync.p\n\tvnop\n\tvcallmsr $vi27\n\tvnop" : : "r"(addr));
    D_004E1D40(re, (void *)0x11004000, n * 4);
    D_004E1D40(im, (void *)0x11004400, n * 4);
    D_004E1D40((void *)0x11004800, D_004B6F90, 0x400);
    re[0] = r0 + i0;
    re[n] = r0 - i0;
    im[0] = 0;
    im[n] = 0;
    re[n >> 1] = rh;
    im[n >> 1] = -ih;
}
