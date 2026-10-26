unsigned int CheckAddress(unsigned int a)
{
    if ((a >> 28) == 7) { a &= 0x0FFFFFFF; a |= 0x80000000; }
    return a;
}