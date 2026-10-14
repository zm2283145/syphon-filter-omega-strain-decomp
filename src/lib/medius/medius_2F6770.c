extern int func_002F6758(int);
extern int func_002F67C0(int);
int func_002F6770(int a, int *p)
{
    if (p == 0) return 2;
    if (func_002F6758(a)) return 0xB;
    return func_002F67C0(*p) ? 0 : 0xB;
}