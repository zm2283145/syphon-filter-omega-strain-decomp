extern int func_002E51B8(unsigned int, char **);
extern char *strncpy(char *, const char *, unsigned int);
int func_002E6BC0(unsigned int a, int b, int c, const char *name)
{
    char *p[1];
    p[0] = 0;
    if (name == 0) return -1;
    if (a >= 4) return 0x10;
    if (func_002E51B8(a, p) || p[0] == 0) return -1;
    strncpy(p[0] + 0x418, name, 0x10);
    return 0x10;
}
