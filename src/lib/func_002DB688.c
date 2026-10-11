extern int func_002E6088(int);
extern void func_002DB188(char **, unsigned int, int);
extern char *func_002DB270(unsigned int, int);
extern void func_002DB550(unsigned int, int);
extern void func_002DB470(char *);
void func_002DB688(unsigned int a, int b)
{
    char *p;
    if (func_002E6088(b) != 1) return;
    if (a >= 4) return;
    func_002DB188(&p, a, b);
    if (p == 0) {
        p = func_002DB270(a, b);
        if (p == 0) return;
    }
    *(unsigned short *)(p + 4) = 0x1000;
    func_002DB550(a, -1);
    func_002DB470(p);
}
