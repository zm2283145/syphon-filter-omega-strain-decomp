extern int func_002F6770(int, char **);
extern int func_002F6628(int, unsigned char *);
extern int func_002F7C40(int, unsigned short *);
int func_002F6330(int a, unsigned short *out)
{
    unsigned char ok;
    char *p = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
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
    return func_002F7C40(*(int *)(p + 4), out);
}
