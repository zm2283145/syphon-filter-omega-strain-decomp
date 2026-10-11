extern int func_002DD9F8(unsigned int, unsigned char **);
extern int func_002F5898(unsigned char *, int *);
int func_002E4190(int *out, unsigned int id)
{
    unsigned char *p = 0;
    int v = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (id >= 0x800) return 0x17;
    r = func_002DD9F8(id, &p);
    if (r) return r;
    if (p == 0) return 0;
    if (p[0] != 2) return 9;
    if (p[4]) return 9;
    if (p + 0x2C == 0) return 9;
    if (func_002F5898(p + 0x2C, &v) == 0) {
        *out = v;
        return 0;
    }
    return 9;
}
