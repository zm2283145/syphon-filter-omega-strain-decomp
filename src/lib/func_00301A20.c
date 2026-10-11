int func_00301A20(unsigned char *p, unsigned int *out)
{
    int ret = 2;
    if (p == 0) return ret;
    if (out == 0) return ret;
    *out = *p++;
    *out |= *p++ << 8;
    *out |= *p++ << 16;
    *out |= *p << 24;
    return 0;
}