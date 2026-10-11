extern void func_002DDE30(char *, int, int);
extern int func_002DE5E8(signed char, int, unsigned int, unsigned int, int, int, char *);
int func_002DE770(signed char a, int b, unsigned int c, unsigned int d, int e, int f, int g)
{
    char buf[0x30];
    if (c >= 6) return 0x17;
    if (d >= 0x100) return 0x17;
    if (e <= 0) return 0x17;
    if (f == 0) return 0x17;
    func_002DDE30(buf, b, g);
    return func_002DE5E8(a, b, c, d, e, f, buf);
}
