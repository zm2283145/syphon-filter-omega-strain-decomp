extern int rt_circ_buf_normalize_with_buf(void *s, unsigned char flag, void *p);
int rt_circ_buf_normalize(void *s, unsigned char flag)
{
    if (s == 0) return 2;
    if (flag && *(void **)((char *)s + 0x14) == 0) return 4;
    return rt_circ_buf_normalize_with_buf(s, flag, *(void **)((char *)s + 0x14));
}
