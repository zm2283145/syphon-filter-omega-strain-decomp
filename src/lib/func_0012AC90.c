char *func_0012AC90(char *s, const char *delim, char **lasts)
{
    char *spanp;
    int c, sc;
    char *tok;
    if (s == 0 && (s = *lasts) == 0) return 0;
cont:
    c = *s++;
    for (spanp = (char *)delim; (sc = *spanp++) != 0;) {
        if (c == sc) goto cont;
    }
    if (c == 0) {
        *lasts = 0;
        return 0;
    }
    tok = s - 1;
    for (;;) {
        c = *s++;
        spanp = (char *)delim;
        do {
            if ((sc = *spanp++) == c) {
                if (c == 0) s = 0;
                else s[-1] = 0;
                *lasts = s;
                return tok;
            }
        } while (sc != 0);
    }
}
