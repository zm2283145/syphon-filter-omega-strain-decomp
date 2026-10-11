extern int func_002DA910(int);
extern char *func_002EF440(char *, int);
extern void func_002ED620(char *);
extern void func_002EFB28(char *);
extern int func_002EF488(char *);
extern void func_002EFA38(char *, int);
extern void func_002F33E0(char *, int);
void func_002EF878(char *s, int b)
{
    char *n;
    if (s == 0) return;
    if (func_002DA910(*(int *)(s + 8)) == *(int *)(s + 0xC)) {
        n = func_002EF440(s, b);
        if (n) {
            func_002ED620(n);
            if (*(int *)(s + 0x58)) {
                func_002EFB28(s);
                func_002EF488(s);
                func_002EFA38(s, b);
            }
        }
    }
    func_002F33E0(s + 0x50, b);
}
