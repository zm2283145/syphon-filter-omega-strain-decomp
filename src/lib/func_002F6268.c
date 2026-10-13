extern int func_002F6770(int, char **);
extern int func_002F7C28(int, unsigned char *, int, int);
extern int func_002F6878(int, int, int);
int func_002F6268(int a, unsigned char *out, int c, int d)
{
    char *p = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (c == 0) return 2;
    if (d == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (*(int *)(p + 8) != 3) return 0xC;
    r = func_002F7C28(*(int *)(p + 4), out, c, d);
    if (r) return r;
    if (*out == 1) {
        r = func_002F6878(0, 0x1C, 0);
        if (r) return r;
    }
    return 0;
}
