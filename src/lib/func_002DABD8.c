extern char *func_002F2FA8(int);
extern char *func_002D9E18(char *, int);
extern void func_002EF878(char *, int);
extern int func_002D8AD8(char *);
extern void func_002F4180(int, int);
extern void func_002F3F00(int, int);
extern void func_002F2F30(char *, int);
void func_002DABD8(char *s)
{
    char *c = func_002F2FA8(*(int *)(s + 0x6C));
    char *n;
    if (c == 0) return;
    if (*(int *)(c + 0x30) > 0) {
        n = func_002D9E18(s, *(int *)(c + 0x30));
        if (n) func_002EF878(n, *(int *)(c + 0x34));
    }
    if (*(char **)(s + 0x64)) func_002EF878(*(char **)(s + 0x64), *(int *)(c + 0x34));
    if (*(int *)(c + 0x848)) {
        func_002F4180(func_002D8AD8(s), *(int *)(c + 0x848));
        *(int *)(c + 0x848) = 0;
    }
    if (*(int *)(c + 0x84C)) {
        func_002F3F00(func_002D8AD8(s), *(int *)(c + 0x84C));
        *(int *)(c + 0x84C) = 0;
    }
    func_002F2F30(s + 0x6C, *(int *)(c + 0x34));
}
