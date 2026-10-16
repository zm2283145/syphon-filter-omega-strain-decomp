extern char D_00512B88[];
extern char *D_00512B80;
extern char D_004AC1C0[];
char *String_Copy(char *d, const char *s);
char *strchr(const char *s, int c);

char *func_002B66A0(char *str, char *delim)
{
    char *tok;
    char *e;
    if (str) {
        String_Copy(D_00512B88, str);
        str = D_00512B88;
        if (str) goto have;
    }
    str = D_00512B80;
    if (!str) goto ret0;
have:
    if (*str != 0) goto scan;
    return 0;
loop:
    if (str[-1] == 0) return 0;
scan:
    if (strchr(delim, *str++)) goto loop;
    tok = str - 1;
    if (*tok == '"') {
        tok = str;
        do {
        } while (!strchr(D_004AC1C0, *str++));
    } else {
        do {
        } while (!strchr(delim, *str++));
    }
    e = str - 1;
    if (*e) D_00512B80 = str;
    else D_00512B80 = 0;
    *e = 0;
    return tok;
ret0:
    return 0;
}


