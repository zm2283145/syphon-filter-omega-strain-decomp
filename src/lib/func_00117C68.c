extern long func_0011ACF8(long, long);

long func_00117C68(unsigned int sec, unsigned int usec)
{
    unsigned long t = (unsigned long)sec * 0x8CA0000u;
    return t + func_0011ACF8((unsigned long)usec * 0x8CA0000u, 1000000);
}
