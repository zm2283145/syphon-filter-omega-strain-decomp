extern int func_002F6770(int, char **);
extern int func_002F7CD0(int, unsigned char *);
int func_002F6628(int a, unsigned char *out)
{
    char *p = 0;
    int r;
    if (out == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8)) return 0xC;
    if (((unsigned char *)p)[0x16] == 1) {
        *out = ((unsigned char *)p)[0x16];
    } else {
        r = func_002F7CD0(*(int *)(p + 4), out);
        if (r) return r;
        p[0x16] = *out;
    }
    return 0;
}
