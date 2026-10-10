int func_002B6318(char* s, char c)
{
    char* p = s;
    while (*p != 0 && *p != c) p++;
    if (*p == c) return p - s;
    return -1;
}