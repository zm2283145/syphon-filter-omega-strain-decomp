extern char *strchr(const char *, int);
extern char *strrchr(const char *, int);
extern unsigned int strlen(const char *);
extern int strcmp(const char *, const char *);
extern void Libc_Strcpy(char *, char *);
int func_002B6448(char *path)
{
    char buf[0x20];
    if (strchr(path, '/')) {
        if (strlen(strrchr(path, '/') + 1) >= 0x20) return 0;
        Libc_Strcpy(buf, strrchr(path, '/') + 1);
    } else {
        if (strlen(path) >= 0x20) return 0;
        Libc_Strcpy(buf, path);
    }
    if (strcmp(buf, ".") == 0 || strcmp(buf, "..") == 0) return 0;
    return 1;
}
