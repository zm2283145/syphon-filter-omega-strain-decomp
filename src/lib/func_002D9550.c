extern int func_002D9E18(char *, int);
extern char *func_002ED898(char *);
extern char *func_002ED930(char *);
extern int strcmp(const char *, const char *);
extern void func_002DA4E0(char *, int);
extern char *func_002D9DD8(char *, int, int);
extern void func_002ED900(char *, const char *);
extern char *func_002F2FA8(int, int);
extern void func_002EF748(char *, char *);
extern void func_002EDC60(char *, unsigned short *);
extern void func_002EDD08(char *, char *, int, int);
extern void func_002F3198(char *, int);
extern int func_002ED940(char *, int, char *, unsigned short *, int);

int func_002D9550(char *s, int a1, int *id, const char *name)
{
    char buf[16];
    unsigned short info[0x28];
    char *n = *(char **)(s + 0x64);
    char *p, *c;
    if (id == 0 || name == 0 || *name == 0)
        return 1;
    for (*id = 1; func_002D9E18(s, *id); (*id)++)
        ;
    while ((n = func_002ED898(n)) != 0 && n != *(char **)(s + 0x64)) {
        if (strcmp(func_002ED930(n), name) == 0)
            return 1;
    }
    if (*(int *)(s + 0x98) > 0) {
        func_002DA4E0(s, *(int *)(s + 0x98));
        *(int *)(s + 0x98) = 0;
    }
    n = func_002D9DD8(s, *id, a1);
    func_002ED900(n, name);
    c = func_002F2FA8(*(int *)(s + 0x6C), *(int *)(s + 0x78));
    func_002EF748(n, c);
    func_002EDC60(n, info);
    func_002EDD08(*(char **)(s + 0x64), buf, 6, 0x44);
    func_002F3198(c, *(int *)(s + 0x98) = info[1]);
    return func_002ED940(*(char **)(s + 0x64), *(int *)(s + 0x78), buf, info, 0x44);
}

