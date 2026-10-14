unsigned int D_00497CD0[5] = { 0x0, 0x0, 0x0, 0x0, 0x0 };
extern unsigned int strlen(const char *);
extern char *strncpy(char *, const char *, unsigned int);
int func_004688D8(char *dst)
{
    if (((char*)D_00497CD0)[0] == 0) return -0xB;
    strncpy(dst, ((char*)D_00497CD0), strlen(((char*)D_00497CD0)) + 1);
    return 0;
}