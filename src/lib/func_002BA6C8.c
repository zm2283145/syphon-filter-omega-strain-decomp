extern int func_002B8188(int, int, char *);
extern int func_002B84E0(int, char *, unsigned short *, int *, int *);
extern int func_002B8928(int, unsigned short *, int, int);
extern int func_002BAD48(int);
int func_002BA6C8(int idx, int path, unsigned short mode)
{
    char name[0x80];
    unsigned short st[0x100];
    int x, y;
    int r;
    r = func_002B8188(idx, path, name);
    if (r) return r;
    r = func_002B84E0(idx, name, st, &x, &y);
    if (r != 0x81010011) return r;
    if (!(st[0] & 0x20)) return 0x81010014;
    st[0] = (st[0] & 0xE7F0) | (mode & 0x180F);
    r = func_002B8928(idx, st, x, y);
    if (r) return r;
    return func_002BAD48(idx) ? 0 : 0x8101006F;
}
