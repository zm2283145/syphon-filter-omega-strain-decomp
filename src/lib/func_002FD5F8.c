extern unsigned char D_004908EC;
extern int func_002FE860(unsigned short, char **);
extern void String_Copy(char *, char *);
int func_002FD5F8(unsigned short id, char *dst)
{
    char *p = 0;
    int r;
    if (D_004908EC != 1) return 5;
    if (dst == 0) return 2;
    r = func_002FE860(id, &p);
    if (r) return r;
    if (*(int *)(p + 8) != 8) return 0x17;
    String_Copy(dst, p + 0x5C);
    return 0;
}
