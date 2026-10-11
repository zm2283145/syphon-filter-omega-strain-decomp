extern void *memset(void *, int, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern int D_0048C458;
extern char D_00588074[];
int func_002DD488(char *p)
{
    if (p == 0) return 0x17;
    memset(p, 0, 0x10);
    if (D_0048C458 == 0) return 0x11;
    strncpy(p, D_00588074, 0x10);
    return 0;
}