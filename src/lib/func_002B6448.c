extern char *strchr(const char *, int);
extern char *strrchr(const char *, int);
extern unsigned int strlen(const char *);
extern int strcmp(const char *, const char *);
extern void String_Copy(char *, char *);
extern char D_004AC1B0[];
extern char D_004AC1B8[];
int func_002B6448(char *path)
{
    char buf[0x20];
    if (strchr(path, '/')) {
        if (strlen(strrchr(path, '/') + 1) >= 0x20) return 0;
        String_Copy(buf, strrchr(path, '/') + 1);
    } else {
        if (strlen(path) >= 0x20) return 0;
        String_Copy(buf, path);
    }
    if (strcmp(buf, D_004AC1B0) == 0 || strcmp(buf, D_004AC1B8) == 0) return 0;
    return 1;
}
