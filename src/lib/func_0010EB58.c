int func_0010EB58(unsigned long x)
{
    long e = (x << 1) >> 53;
    e -= 0x433;
    if (e < -53)
        return 0;
    if (e >= 13)
        return 9999;
    x = (x << 12) >> 12;
    x |= 1UL << 52;
    if (e < 0) {
        e = -e;
        x >>= e - 2;
        if ((x & 3) == 3)
            x = (x >> 2) + 1;
        else
            x >>= 2;
    } else {
        x <<= e;
    }
    return x;
}


