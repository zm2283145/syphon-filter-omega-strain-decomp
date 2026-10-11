int func_003019E8(unsigned char *p, int v)
{
    int ret = 2;
    if (p == 0) return ret;
    *p++ = v;
    *p++ = v >> 8;
    *p++ = v >> 16;
    *p = v >> 24;
    return 0;
}