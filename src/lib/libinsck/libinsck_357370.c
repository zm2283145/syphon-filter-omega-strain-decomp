extern unsigned int func_00357150(unsigned int x);
extern unsigned int func_00357190(const char *nptr, char **endptr, int base, int *err);

int func_00357370(const char *cp, unsigned int *addr)
{
    unsigned int parts[4];
    unsigned int val;
    char *c;
    char *endptr;
    int err;
    int gotend, n;
    int ch;
    unsigned int tmp;

    c = (char *)cp;
    n = 0;
    gotend = 0;
    while (!gotend) {
        err = 0;
        val = func_00357190(c, &endptr, 0, &err);

        if (err == 34)
            return 0;
        if (endptr == c)
            return 0;
        parts[n] = val;
        c = endptr;

        ch = (unsigned char)*c;
        switch (*c) {
        case '.':
            if (n == 3)
                return 0;
            n++;
            c++;
            break;

        case '\0':
            gotend = 1;
            break;

        default:
            if ((unsigned int)(ch - 9) < 5 || ch == ' ') {
                gotend = 1;
                break;
            } else
                return 0;
        }
    }

    switch (n) {
    case 0:
        break;
    case 1:
        if (val > 0xffffff || parts[0] > 0xff)
            return 0;
        val |= parts[0] << 24;
        break;

    case 2:
        if (val > 0xffff || parts[0] > 0xff || parts[1] > 0xff)
            return 0;
        val |= (parts[0] << 24) | (parts[1] << 16);
        break;

    case 3:
        if (val > 0xff || parts[0] > 0xff || parts[1] > 0xff ||
            parts[2] > 0xff)
            return 0;
        tmp = (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8);
        val |= tmp;
        break;
    }

    if (addr != 0)
        *addr = func_00357150(val);
    return 1;
}


