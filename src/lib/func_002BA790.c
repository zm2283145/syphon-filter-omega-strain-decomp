typedef struct { int x; char pad[0x894]; } E2BA790;
extern E2BA790 D_00513514[];
extern int func_002BC788(int);
extern int _make_path(int, char *, char *);
extern int isCorrFname(char *);
extern int isCorrNameSize(char *);
extern char *strchr(const char *, int);
extern char *strrchr(const char *, int);
extern char *String_Copy(char *, const char *);
extern int _sceMcFatSearchFile(int, char *, unsigned short *, int *, int *);
extern int _SetEntryByPos(int, unsigned short *, int, int);
extern int func_002BAD48(int);
int _sceMcFatRename(int idx, char *path, char *newname)
{
    unsigned short st[0x100];
    char name[0x80];
    char buf[0x80];
    int x, y;
    int r;
    if (!func_002BC788(idx)) return 0x81010013;
    if (D_00513514[idx].x == 0) return 0x8101006F;
    if (!_make_path(idx, path, name)) return 0x81010016;
    if (strchr(newname, '/')) return 0x81010016;
    String_Copy(buf, name);
    String_Copy(strrchr(buf, '/') + 1, newname);
    if (!isCorrFname(path)) return 0x81010016;
    if (!isCorrFname(newname)) return 0x81010016;
    if (!isCorrNameSize(path)) return 0x8101005B;
    if (!isCorrNameSize(newname)) return 0x8101005B;
    r = _sceMcFatSearchFile(idx, buf, st, &x, &y);
    if (r != 0x81010002) return r;
    r = _sceMcFatSearchFile(idx, name, st, &x, &y);
    if (r != 0x81010011) return r;
    String_Copy((char *)st + 0x40, newname);
    r = _SetEntryByPos(idx, st, x, y);
    if (r) return r;
    return func_002BAD48(idx) ? 0 : 0x8101006F;
}

