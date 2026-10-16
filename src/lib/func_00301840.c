/* Busy-wait delay; asm nops are the delay padding (gcc 2.96 emits one extra nop per group). */
int func_00301840(void)
{
    int i;
    int c;
    i = 15;
    do {
        i--;
        __asm__("nop"); __asm__("nop"); __asm__("nop"); __asm__("nop");
    } while (i >= 0);
    i = 16;
    while (c) {
        i++;
        c = i < 16;
        __asm__("nop"); __asm__("nop"); __asm__("nop");
    }
    return c;
}
