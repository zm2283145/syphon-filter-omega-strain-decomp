extern unsigned int strlen(const char *s);
extern char *strncpy(char *d, const char *s, unsigned int n);
int func_0030EFD0(char *buf, unsigned int *pos, char *s)
{
    unsigned int n = strlen(s) + 1;
    if (*pos + n >= 256) return 0;
    strncpy(buf + *pos, s, n);
    *pos += n;
    return 1;
}