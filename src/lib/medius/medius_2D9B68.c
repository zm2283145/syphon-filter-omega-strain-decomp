extern int D_00588060;
extern int D_00588064;
extern void func_002F4E20(int, char *);
extern int func_00307CB0(int, char *, unsigned short, int, unsigned short);
int func_002D9B68(char *s, int b, int c, int d, int e)
{
    char buf[16];
    func_002F4E20(d, buf);
    if (func_00307CB0(*(int *)(s + 0x8C), buf, e, b, c)) {
        D_00588064 += c;
        return -1;
    }
    D_00588060 += c;
    return c;
}
