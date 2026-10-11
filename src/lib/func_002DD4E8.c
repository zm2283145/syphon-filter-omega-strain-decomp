extern void *memset(void *, int, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern int func_002E51B8(unsigned int, char **);
extern int func_002E52D8(unsigned int, unsigned int, unsigned char **);
int func_002DD4E8(char *dst, unsigned int a, unsigned int b)
{
    char *p = 0;
    unsigned char *q = 0;
    int r;
    if (dst == 0) return 0x17;
    memset(dst, 0, 0x10);
    if (b >= 0x100) return 0x17;
    if (a >= 4) return 0x17;
    r = func_002E51B8(a, &p);
    if (r) return r;
    if (p == 0) return 0xF;
    r = func_002E52D8(a, b, &q);
    if (r) return r;
    if (q == 0) return 8;
    if (q[0x28] == 0) return 8;
    strncpy(dst, (char *)q, 0x10);
    return 0;
}
