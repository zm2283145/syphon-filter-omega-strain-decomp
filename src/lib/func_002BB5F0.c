extern char D_0051AAC0[];
extern void func_002BC808(void);
extern void func_0010DA58(char *, char *);
extern int func_0026A8C8(int);
char *func_002BB5F0(int a)
{
    char *p = D_0051AAC0;
    func_002BC808();
    func_0010DA58(p, p + 0x7F);
    if (*(int *)p > 0) return p;
    if (func_0026A8C8(a) == 3) {
        ((int *)p)[2] = 0;
        return p;
    }
    ((int *)p)[2] = 0;
    return p;
}
