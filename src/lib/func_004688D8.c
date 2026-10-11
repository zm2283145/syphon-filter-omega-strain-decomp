extern char D_00497CD0[];
extern unsigned int strlen(const char *);
extern char *strncpy(char *, const char *, unsigned int);
int func_004688D8(char *dst)
{
    if (D_00497CD0[0] == 0) return -0xB;
    strncpy(dst, D_00497CD0, strlen(D_00497CD0) + 1);
    return 0;
}