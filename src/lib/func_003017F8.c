int func_003017F8(unsigned int idx, unsigned char *a, unsigned char *b, unsigned char *c)
{
    int ret = 2;
    if (idx >= 2) return ret;
    if (a == 0) return ret;
    if (b == 0) return ret;
    if (c == 0) return ret;
    *a = 1;
    *b = 8;
    *c = 0x84;
    return 0;
}