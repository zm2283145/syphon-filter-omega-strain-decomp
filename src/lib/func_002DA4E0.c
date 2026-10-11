extern void func_002EDD08(int, char *, int, int);
extern int func_002ED940(int, int, char *, unsigned short *, int);
extern char *func_002D9E18(char *, int);
extern void func_002EF878(char *, int);
extern void func_002EF6E0(char *);
extern void func_002F3198(int, int);
extern void func_002D9EB0(char *, int);
int func_002DA4E0(char *s, int id)
{
    char buf[16];
    unsigned short v;
    int r;
    char *n;
    if (id == 0 || id != *(int *)(s + 0x98)) return -1;
    v = id;
    func_002EDD08(*(int *)(s + 0x64), buf, 0xA, 2);
    r = func_002ED940(*(int *)(s + 0x64), *(int *)(s + 0x78), buf, &v, 2);
    n = func_002D9E18(s, *(int *)(s + 0x98));
    if (n) {
        func_002EF878(n, *(int *)(s + 0x78));
        func_002EF6E0(n);
    }
    *(int *)(s + 0x98) = 0;
    func_002F3198(*(int *)(s + 0x68), 0);
    func_002D9EB0(s, 4);
    return r;
}
