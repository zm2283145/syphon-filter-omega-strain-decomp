extern long func_0011ACF8(long, long);

void func_00117BC0(long t, int *sec, int *usec)
{
    int q = func_0011ACF8(t, 0x8CA0000);
    if (sec) *sec = q;
    if (usec) *usec = func_0011ACF8((t - (unsigned long)(unsigned int)q * 0x8CA0000u) * 1000000, 0x8CA0000);
}