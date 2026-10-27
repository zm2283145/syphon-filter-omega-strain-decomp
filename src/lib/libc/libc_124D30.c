extern char **D_0048943C;
static char ***D_00489440 = &D_0048943C;
extern void Newlib_EnvLock(void *);
extern void Newlib_EnvUnlock(void *);
extern int Libc_Strncmp(const char *, const char *, unsigned int);
char *Newlib_FindenvR(void *reent_ptr, const char *name, int *offset)
{
    int len;
    char **p;
    const char *c;
    Newlib_EnvLock(reent_ptr);
    if (*D_00489440 == 0)
        return 0;
    c = name;
    len = 0;
    while (*c && *c != '=') {
        c++;
        len++;
    }
    for (p = *D_00489440; *p; ++p)
        if (!Libc_Strncmp(*p, name, len))
            if (*(c = *p + len) == '=') {
                *offset = p - *D_00489440;
                Newlib_EnvUnlock(reent_ptr);
                return (char *)(++c);
            }
    Newlib_EnvUnlock(reent_ptr);
    return 0;
}