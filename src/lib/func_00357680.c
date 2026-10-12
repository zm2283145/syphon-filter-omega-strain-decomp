static inline int is_space(unsigned char c)
{
    int r = 0;
    if ((unsigned int)(c - 9) < 5 || c == ' ')
        r = 1;
    return r;
}

static inline int is_xdigit(char c)
{
    int r = 0;
    unsigned char u;
    if ((unsigned char)(u - '0') < 10 || (unsigned int)((unsigned char)c - 'a') < 6 ||
        (unsigned int)((unsigned char)c - 'A') < 6)
        r = 1;
    return r;
}

unsigned int func_00357680(char *cp)
{
    int val; unsigned int base;
    unsigned int n, i;
    char c;
    unsigned char u;
    unsigned int parts[4], *pp = parts;

again:
    val = 0;
    base = 10;
    if (*cp == '0') {
        cp++;
        base = 8;
    }
    if (*cp == 'x' || *cp == 'X') {
        cp++;
        base = 16;
    }
    while ((c = *cp)) {
        if ((unsigned int)((unsigned char)c - '0') < 10) {
            val = (val * base) + (c - '0');
            cp++;
            continue;
        }
        if (base == 16 && is_xdigit(c)) {
            { int d = (val << 4) + (c + 10 - ((unsigned int)((unsigned char)c - 'a') < 26 ? 'a' : 'A')); val = d; }
            cp++;
            continue;
        }
        break;
    }
    if (*cp == '.') {
        if (pp >= parts + 3)
            return 0xFFFFFFFF;
        *pp++ = val, cp++;
        goto again;
    }
    if (*cp && !is_space(*cp))
        return 0xFFFFFFFF;
    *pp++ = val;
    n = pp - parts;
    val = 0;
    for (i = 0; i < n; i++)
    {
        val <<= 8;
        val |= parts[i] & 0xff;
    }
    return val;
}



