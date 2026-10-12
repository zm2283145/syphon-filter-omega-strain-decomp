extern char *func_0030F0E8(char *buf, int len);
extern int strlen(const char *s);
extern int String_CompareN(const char *a, const char *b, int n);
int func_0030F050(char *buf, int *len, const char *tag)
{
    char *e = func_0030F0E8(buf, *len);
    int n = strlen(tag);
    if (String_CompareN(tag, e, n) == 0) {
        *len = *len - n - 1;
        buf[*len] = 0;
        return 1;
    }
    return 0;
}
