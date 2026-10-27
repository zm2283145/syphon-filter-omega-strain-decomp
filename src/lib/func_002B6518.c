extern int func_002B6318(char *s, char c);
extern int Libc_Strncmp(char *a, char *b, int n);
extern int strcmp(const char *a, const char *b);
int isWildFit(char *s, char *p)
{
    int q, a, n;
    while ((q = func_002B6318(p, '?')), (a = func_002B6318(p, '*')), q >= 0 || a >= 0) {
        if (q < 0)
            n = a;
        else if (a < 0)
            n = q;
        else
            n = q < a ? q : a;
        if (Libc_Strncmp(p, s, n) != 0)
            return 0;
        p += n;
        s += n;
        while (*p == '?') {
            if (*s == 0)
                return 1;
            s++;
            p++;
        }
        if (*p != '*')
            continue;
        do
            p++;
        while (*p == '*' || *p == '?');
        if (*p == 0)
            return 1;
        while ((n = func_002B6318(s, *p)) >= 0) {
            s += n;
            if (isWildFit(s++, p) == 1)
                return 1;
        }
        return 0;
    }
    return strcmp(p, s) == 0;
}
