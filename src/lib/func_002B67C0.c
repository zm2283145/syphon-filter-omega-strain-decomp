int func_002B67C0(char *s)
{
    int n = 0;
    while (*s) {
        if (*s == '/') n++;
        s++;
    }
    return n;
}