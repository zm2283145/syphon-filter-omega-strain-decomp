extern unsigned char D_00499C70[];
#define isupper(c) ((D_00499C70 + 1)[(unsigned)(c)] & 1)
#define tolower(c) ({ int __x = (c); isupper(__x) ? (__x - 'A' + 'a') : __x; })
int String_CompareNoCase(const char *s1, const char *s2)
{
    while (*s1 != '\0' && tolower(*s1) == tolower(*s2)) {
        s1++;
        s2++;
    }
    return tolower(*(unsigned char *)s1) - tolower(*(unsigned char *)s2);
}