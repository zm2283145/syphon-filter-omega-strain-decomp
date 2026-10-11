extern char *func_002D9E88(char *, int);
extern void func_002EDD08(int, char *, int, int);
extern void func_002D9A30(char *, int, char *, int *, int);
int func_002DA9A8(char *s, int id, int v)
{
    char buf[16];
    int w;
    char *p;
    if (id == 0xFFFF || id == *(int *)(s + 0x78)) return -1;
    p = func_002D9E88(s, id);
    if (p == 0) return -1;
    *(int *)(p + 0x38) = v;
    w = v;
    func_002EDD08(*(int *)(s + 0x64), buf, 0x11, 4);
    func_002D9A30(s, id, buf, &w, 4);
    return 0;
}
