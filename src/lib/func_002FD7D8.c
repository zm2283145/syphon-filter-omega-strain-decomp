extern unsigned char D_004908EC;
extern int func_002FE860(unsigned short, char **);
int func_002FD7D8(unsigned short id, int v)
{
    char *p = 0;
    unsigned int i;
    char **pp;
    int r;
    if (D_004908EC != 1) return 5;
    r = func_002FE860(id, &p);
    if (r) return r;
    pp = (char **)(p + 0x78);
    for (i = 0; i < 2; i++, pp++)
        if (*pp) *(int *)(*pp + 0x40) = v;
    return 0;
}
