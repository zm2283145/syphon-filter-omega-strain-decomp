extern void func_002DA4E0(char *, int);
extern char *func_002D9E18(char *, int);
extern void func_002EDD08(int, char *, int, int);
extern int func_002ED940(int, int, char *, unsigned short *, int);
extern char *func_002F2FA8(int, int);
extern void func_002F3198(char *, int);
extern void func_002EF748(char *, char *);
extern void func_002EF938(char *);
int func_002DA3D8(char *s, int id)
{
    char buf[16];
    unsigned short v;
    int r = 0;
    char *n, *c;
    if (*(int *)(s + 0x98) > 0 && *(int *)(s + 0x98) != id && (*(int *)(s + 0x70) & 4))
        func_002DA4E0(s, *(int *)(s + 0x98));
    if (id > 0) {
    n = func_002D9E18(s, id);
    v = id;
    func_002EDD08(*(int *)(s + 0x64), buf, 9, 2);
    r = func_002ED940(*(int *)(s + 0x64), *(int *)(s + 0x78), buf, &v, 2);
    if (r == 0) {
        c = func_002F2FA8(*(int *)(s + 0x6C), *(int *)(s + 0x78));
        *(int *)(s + 0x98) = id;
        func_002F3198(c, id);
        if (n) func_002EF748(n, c);
    }
    func_002EF938(n);
    }
    return r;
}
