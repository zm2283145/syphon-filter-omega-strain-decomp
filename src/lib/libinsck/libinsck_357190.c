unsigned int strtoui_internal(const char *nptr, char **endptr, int base, int *err)
{
    const char *s = nptr;
    unsigned int acc;
    unsigned char c;
    unsigned int cutoff;
    int neg = 0, any, cutlim;

    do {
        c = *s++;
    } while ((unsigned int)(c - 9) < 5 || c == ' ');
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) &&
        c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = (unsigned int)0xFFFFFFFF / (unsigned int)base;
    cutlim = (unsigned int)0xFFFFFFFF % (unsigned int)base;
    for (acc = 0, any = 0; (signed char)c >= 0; c = *s++) {
        if ((unsigned char)(c - '0') < 10)
            c -= '0';
        else if ((unsigned char)(c - 'A') < 26 || (unsigned char)(c - 'a') < 26)
            c -= (unsigned char)(c - 'A') < 26 ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = 0xFFFFFFFF;
        *err = 34;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char *)(any ? s - 1 : nptr);
    return acc;
}
