extern int func_002F6770(int, char **);
extern int func_002F6628(int, unsigned char *);
extern int func_002F7BA8(int, int, unsigned short, unsigned short *);
extern int func_002F6878(unsigned short, int, int);
int Socket_WriteConnected(int a, int b, unsigned short c, unsigned short *out)
{
    unsigned char ok;
    char *p = 0;
    int r, t;
    if (out == 0) return 2;
    *out = 0;
    if (b == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    t = *(int *)(p + 8);
    if (t != 0 && t != 2) return 0xC;
    if (((unsigned char *)p)[0x16] == 0 && *(int *)(p + 8) == 0) {
        ok = 0;
        r = func_002F6628(a, &ok);
        if (r) return r;
        if (ok == 0) {
            *out = 0;
            return r;
        }
        p[0x16] = 1;
    }
    r = func_002F7BA8(*(int *)(p + 4), b, c, out);
    if (r) return r;
    return func_002F6878(*out, 0, 0x28);
}
