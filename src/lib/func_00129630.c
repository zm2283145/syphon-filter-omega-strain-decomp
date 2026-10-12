typedef unsigned int size_t;
extern unsigned char D_00499C70[];
#define isupper(c) ((D_00499C70 + 1)[(unsigned)(c)] & 1)
#define tolower(c) ({ int __x = (c); isupper(__x) ? (__x - 'A' + 'a') : __x; })
int func_00129630(const char *s1, const char *s2, size_t n)
{
    if (n == 0)
        return 0;
    while (n-- != 0 && tolower(*s1) == tolower(*s2)) {
        if (n == 0 || *s1 == '\0' || *s2 == '\0')
            break;
        s1++;
        s2++;
    }
    return tolower(*(unsigned char *)s1) - tolower(*(unsigned char *)s2);
}