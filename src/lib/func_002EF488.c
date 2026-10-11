extern void func_002DA900(int, int *);
extern void func_002EDD08(char *, char *, int, int);
extern int func_002ED940(char *, int, char *, int, int);
int func_002EF488(char *s)
{
    char buf[16];
    int h = 0xFFFF;
    if (s == 0 || *(int *)(s + 0xC) == 0) return -1;
    func_002DA900(*(int *)(s + 8), &h);
    func_002EDD08(s, buf, 0xF, 0);
    return func_002ED940(s, h, buf, 0, 0);
}
