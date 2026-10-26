int rt_msg_get_byte(unsigned char *src, unsigned char *dst)
{
    int ret = 2;
    if (src == 0) return ret;
    if (dst == 0) return ret;
    *dst = *src;
    return 0;
}