extern int strcmp(const char *, const char *);
extern void String_Copy(char *, char *);
extern char *Libc_Strcat(char *, const char *);
extern const char D_004AC1C8[];
typedef struct { char cwd[0x898]; } MC2Port;
extern MC2Port D_00513490[];
extern int func_002B8188(int, char *, char *);
extern int func_002B84E0(int, char *, unsigned short *, int *, int *);
int func_002BA110(int idx, char *path, char *out)
{
    unsigned short st[0x100];
    char name[0x80];
    int r;
    r = func_002B8188(idx, path, name);
    if (r) return r;
    if (strcmp(name, D_004AC1C8) == 0) {
        String_Copy(D_00513490[idx].cwd, name);
        if (out) String_Copy(out, name);
        return 0;
    }
    r = func_002B84E0(idx, name, st, 0, 0);
    if (r != 0x81010011) return r;
    if (!(st[0] & 0x20)) return 0x81010014;
    String_Copy(D_00513490[idx].cwd, name);
    Libc_Strcat(D_00513490[idx].cwd, D_004AC1C8);
    if (out) String_Copy(out, name);
    return 0;
}
