extern unsigned long long D_00476B00[];
extern unsigned long long D_004778C0[];
void vuClearFftData(void)
{
    int addr = D_004778C0 - D_00476B00;
    __asm__ volatile("ctc2.ni %0, $vi27\n\tsync.p\n\tsync\n\tsync.p\n\tvnop\n\tvcallmsr $vi27\n\tvnop" : : "r"(addr));
}
