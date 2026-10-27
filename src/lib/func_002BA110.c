extern int strcmp(const char *, const char *);
extern void Libc_Strcpy(char *, char *);
extern char *Libc_Strcat(char *, const char *);
extern const char D_004AC1C8[];
typedef struct { char cwd[0x898]; } MC2Port;
extern MC2Port D_00513490[];
extern int func_002B8188(int, char *, char *);
extern int _sceMcFatSearchFile(int, char *, unsigned short *, int *, int *);
int _sceMcFatChDir(int idx, char *path, char *out)
{
    unsigned short st[0x100];
    char name[0x80];
    int r;
    r = func_002B8188(idx, path, name);
    if (r) return r;
    if (strcmp(name, D_004AC1C8) == 0) {
        Libc_Strcpy(D_00513490[idx].cwd, name);
        if (out) Libc_Strcpy(out, name);
        return 0;
    }
    r = _sceMcFatSearchFile(idx, name, st, 0, 0);
    if (r != 0x81010011) return r;
    if (!(st[0] & 0x20)) return 0x81010014;
    Libc_Strcpy(D_00513490[idx].cwd, name);
    Libc_Strcat(D_00513490[idx].cwd, D_004AC1C8);
    if (out) Libc_Strcpy(out, name);
    return 0;
}
