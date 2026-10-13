extern int func_002F5748(void *s, unsigned char flag, void *p);
int func_002F56F8(void *s, unsigned char flag)
{
    if (s == 0) return 2;
    if (flag && *(void **)((char *)s + 0x14) == 0) return 4;
    return func_002F5748(s, flag, *(void **)((char *)s + 0x14));
}
