int func_004700F8(char *s, int n)
{
    if (s == 0) return -0x63;
    if (n > 0) s[n - 1] = 0;
    else *s = 0;
    return 0;
}