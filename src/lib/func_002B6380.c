extern char *strchr(const char *, int);
extern char *strrchr(const char *, int);
extern unsigned int strlen(const char *);
int isCorrNameSize(char *s)
{
    if (strchr(s, '/')) {
        if (strlen(strrchr(s, '/') + 1) >= 0x20) return 0;
    } else if (strlen(s) >= 0x20) return 0;
    return 1;
}
