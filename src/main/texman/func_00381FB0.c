#define R(a) (*(volatile unsigned int*)(a))
extern int D_00539328;
extern int D_00539330;
extern unsigned int D_00539340[][1024];

int func_00381FB0(void)
{
    R(0x1000E010) = 2;
    while (R(0x1000A000) & 0x100) {
    }
    R(0x1000A020) = 0;
    R(0x1000A030) = D_00539340[D_00539330][D_00539328] & 0x0FFFFFFF;
    R(0x1000A000) = 0x105;
    asm volatile ("sync");
    D_00539328++;
    R(0x10003C10) = 8;
    asm volatile ("sync");
    asm volatile ("ei");
    return 1;
}
