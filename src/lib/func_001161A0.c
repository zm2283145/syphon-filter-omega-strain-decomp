int func_001161A0(void)
{
    int s, v;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) {
        do {
            __asm__ volatile("di");
            __asm__ volatile("sync.p");
            __asm__ volatile("mfc0 %0, $12" : "=r"(v));
            v &= 0x10000;
            /* R5900 short-loop padding emitted by the SCE assembler */
            __asm__ volatile("nop\n\tnop" : "+r"(v));
        } while (v);
    }
    return s != 0;
}

