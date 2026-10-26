int isCorrFname(char* s)
{
    for (; *s != 0; s++) {
        if (*s == '?' || *s == '*' || *s < 0x20) return 0;
    }
    return 1;
}