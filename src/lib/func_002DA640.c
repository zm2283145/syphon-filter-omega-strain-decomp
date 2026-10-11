typedef struct { char b[0x18]; unsigned int flags; char c[4]; } I2DA640;
extern int func_002F3220(char *);
int func_002DA640(char *s, int (*cb)(char *, int, I2DA640 *), int arg)
{
    I2DA640 info;
    char *n, *head;
    if (cb == 0 || *(int *)(s + 0x64) == 0) return -1;
    n = *(char **)(s + 0x6C);
    head = n;
    while (n) {
        info = *(I2DA640 *)(n + 0x20);
        if (func_002F3220(n) & 0x4000) info.flags |= 0x8000;
        else info.flags &= ~0x8000;
        if (!cb(s, arg, &info)) break;
        n = *(char **)(n + 4);
        if (n == head) n = 0;
    }
    return 0;
}
