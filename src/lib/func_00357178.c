unsigned int func_00357178(unsigned int input)
{
    register unsigned int x asm("$4") = input;
    register unsigned int r asm("$2") = (x << 8) & 0xFF00;
    register unsigned int s asm("$3");

    // Preserve the first mask before extracting the other byte.
    __asm__("" : "+r"(r), "+r"(x));
    s = (x >> 8) & 0xFF;
    return r | s;
}
