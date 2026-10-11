extern int func_002E51B8(unsigned int, char **);
extern char *strncpy(char *, const char *, unsigned int);
int func_002E54E8(unsigned int a, const char *s)
{
    char *p = 0;
    int r;
    if (a >= 4) return 8;
    if (s == 0) return 0x17;
    r = func_002E51B8(a, &p);
    if (r) return r;
    if (p == 0) return r;
    strncpy(p + 0x408, s, 0x10);
    return 0;
}
