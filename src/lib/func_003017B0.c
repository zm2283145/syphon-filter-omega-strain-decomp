int func_003017B0(unsigned int idx, unsigned char en, unsigned char lvl, int unused, unsigned char *out)
{
    int ret = 2;
    if (out == 0) return ret;
    *out = 0;
    if (idx >= 2) return ret;
    if (en != 0 && lvl >= 7) *out = 1;
    return 0;
}