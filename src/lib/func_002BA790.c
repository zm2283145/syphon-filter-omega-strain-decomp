typedef struct { int x; char pad[0x894]; } E2BA790;
extern E2BA790 D_00513514[];
extern int func_002BC788(int);
extern int func_002B6808(int, char *, char *);
extern int func_002B63F0(char *);
extern int func_002B6380(char *);
extern char *strchr(const char *, int);
extern char *strrchr(const char *, int);
extern char *String_Copy(char *, const char *);
extern int func_002B84E0(int, char *, unsigned short *, int *, int *);
extern int func_002B8928(int, unsigned short *, int, int);
extern int func_002BAD48(int);
int func_002BA790(int idx, char *path, char *newname)
{
    unsigned short st[0x100];
    char name[0x80];
    char buf[0x80];
    int x, y;
    int r;
    if (!func_002BC788(idx)) return 0x81010013;
    if (D_00513514[idx].x == 0) return 0x8101006F;
    if (!func_002B6808(idx, path, name)) return 0x81010016;
    if (strchr(newname, '/')) return 0x81010016;
    String_Copy(buf, name);
    String_Copy(strrchr(buf, '/') + 1, newname);
    if (!func_002B63F0(path)) return 0x81010016;
    if (!func_002B63F0(newname)) return 0x81010016;
    if (!func_002B6380(path)) return 0x8101005B;
    if (!func_002B6380(newname)) return 0x8101005B;
    r = func_002B84E0(idx, buf, st, &x, &y);
    if (r != 0x81010002) return r;
    r = func_002B84E0(idx, name, st, &x, &y);
    if (r != 0x81010011) return r;
    String_Copy((char *)st + 0x40, newname);
    r = func_002B8928(idx, st, x, y);
    if (r) return r;
    return func_002BAD48(idx) ? 0 : 0x8101006F;
}

