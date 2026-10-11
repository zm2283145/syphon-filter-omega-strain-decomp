void func_002EFDC8(unsigned int* bits, unsigned int n)
{
    bits += n >> 5;
    *bits |= 1 << n;
}
