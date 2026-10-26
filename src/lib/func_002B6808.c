extern char *strrchr(const char *, int);
extern unsigned int strlen(const char *);
extern int strcmp(const char *, const char *);
extern char *strcpy(char *, const char *);
extern void String_Copy(char *, char *);
extern char *_strtok(char *, char *);
extern char *Libc_Strcat(char *, char *);
extern char D_004AC1B0[];
extern char D_004AC1B8[];
typedef struct { char cwd[0x898]; } MC2Port;
extern MC2Port D_00513490[];
int _make_path(int idx, char *path, char *out)
{
    char *tok;
    if (strlen(path) >= 0x80) return 0;
    String_Copy(out, D_00513490[idx].cwd);
    if (*path == '/') {
        strcpy(out, "/");
        tok = _strtok(path + 1, "/");
    } else {
        tok = _strtok(path, "/");
    }
    while (tok) {
        if (strcmp(tok, D_004AC1B0) == 0) {
            tok = _strtok(0, "/");
        } else if (strcmp(tok, D_004AC1B8) == 0) {
            char *p;
            out[strlen(out) - 1] = 0;
            p = strrchr(out, '/');
            if (!p) return 0;
            p[1] = 0;
            tok = _strtok(0, "/");
        } else {
            Libc_Strcat(out, tok);
            Libc_Strcat(out, "/");
            tok = _strtok(0, "/");
        }
    }
    if (strcmp(out, "/") != 0) *strrchr(out, '/') = 0;
    return 1;
}
