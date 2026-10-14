extern char **D_0048943C;
static char ***D_00489440 = &D_0048943C;
extern void func_00123310(void *);
extern void func_00123318(void *);
extern int String_CompareN(const char *, const char *, unsigned int);
char *func_00124D30(void *reent_ptr, const char *name, int *offset)
{
    int len;
    char **p;
    const char *c;
    func_00123310(reent_ptr);
    if (*D_00489440 == 0)
        return 0;
    c = name;
    len = 0;
    while (*c && *c != '=') {
        c++;
        len++;
    }
    for (p = *D_00489440; *p; ++p)
        if (!String_CompareN(*p, name, len))
            if (*(c = *p + len) == '=') {
                *offset = p - *D_00489440;
                func_00123318(reent_ptr);
                return (char *)(++c);
            }
    func_00123318(reent_ptr);
    return 0;
}