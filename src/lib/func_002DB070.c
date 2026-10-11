extern void func_002EDD08(int, char *, int, int);
extern void func_002D9A30(char *, int, char *, short *, int);
void func_002DB070(char *o, short a, int b, short c)
{
    char buf[16];
    short s[2];
    s[0] = a;
    s[1] = c;
    func_002EDD08(*(int *)(o + 0x64), buf, 0x12, 4);
    func_002D9A30(o, b, buf, s, 4);
}