extern int func_002FE810(unsigned short);
extern int func_002FE720(int);
int func_002FE860(unsigned short a, int *p)
{
    if (p == 0) return 2;
    if (func_002FE810(a)) return 0xB;
    return func_002FE720(*p) ? 0 : 0xB;
}