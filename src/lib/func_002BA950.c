extern int func_002B8188(int, int, char *);
extern int _sceMcFatSearchFile(int, char *, char *, int, int);
extern int _GetFreeEntrySize(int, int, int, int *);
int func_002BA950(int a, int b)
{
    char buf[0x200];
    char name[0x80];
    int err;
    int v;
    err = func_002B8188(a, b, name);
    if (err) return err;
    err = _sceMcFatSearchFile(a, name, buf, 0, 0);
    if (err != 0x81010011) return err;
    if (!(*(unsigned short *)buf & 0x20)) return 0x81010014;
    v = _GetFreeEntrySize(a, *(int *)(buf + 0x10), *(int *)(buf + 4), &err);
    return err ? err : v;
}
