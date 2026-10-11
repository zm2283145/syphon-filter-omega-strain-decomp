int func_002EFDA0(unsigned int* bits, unsigned int n)
{
    bits += n >> 5;
    return ((1 << n) & *bits) != 0;
}
