extern void func_002EDCB0(char *, char *);
extern char *func_002ED898(char *);
int func_002DA5A8(char *s, int (*cb)(char *, int, char *), int arg)
{
    char buf[0x40];
    char *n = *(char **)(s + 0x64);
    if (cb == 0) return -1;
    while (n) {
        func_002EDCB0(n, buf);
        if (!cb(s, arg, buf)) break;
        n = func_002ED898(n);
        if (n == *(char **)(s + 0x64)) n = 0;
    }
    return 0;
}
